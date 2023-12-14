/**
 * @file BlurFilter.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "SFML/Graphics/Image.hpp"
#include "ipp/common.hpp"

#include "ipp/Filter/IFilter.hpp"

namespace Ipp
{
  class BlurFilter : public IFilter
  {
  public:
    enum Method
    {
      Box = 0,
      Gaussian
    };
    BlurFilter();
    virtual ~BlurFilter();
    virtual void applyTo(sf::Image& image);
    void setMethod(Method method);
		/**
		 * @brief Set the Radius object
		 * 
		 * @param radius 0~1
		 */
		void setRadius(float radius);
  private:
		void boxMethod(sf::Image& image);
		void gaussianMethod(sf::Image& image);
    /* sf::Uint8 getGrayPixelAverage(sf::Color pixel);
    sf::Uint8 getGrayPixelLuminosity(sf::Color pixel);
    sf::Uint8 getGrayPixelDesaturation(sf::Color pixel);
    sf::Uint8 getGrayPixelSingleChannel(sf::Color pixel);
    typedef sf::Uint8 (BlurFilter::*functionPointer)(sf::Color);
    functionPointer getGrayPixel[4]; */
		typedef void (BlurFilter::*functionPointer)(sf::Image&);
		functionPointer blurMethods[2];
  private:
    Method eMethod;
		float mRadius;

	private:
		static const int scMaxRadius;

     std::vector<std::vector<float>> createGaussianKernel(int radius) {
        int size = 2 * radius + 1;
        std::vector<std::vector<float>> kernel(size, std::vector<float>(size));
        float sigma = radius / 2.0f;
        float sum = 0.0f;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int x = i - radius;
                int y = j - radius;
                kernel[i][j] = std::exp(-(x * x + y * y) / (2 * sigma * sigma));
                sum += kernel[i][j];
            }
        }

        // 커널 정규화
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                kernel[i][j] /= sum;
            }
        }

        return kernel;
    }

    // 커널 적용 함수
    sf::Color applyKernel(const sf::Image& image, const std::vector<std::vector<float>>& kernel, unsigned x, unsigned y) {
        float red = 0.0f, green = 0.0f, blue = 0.0f;
        int radius = kernel.size() / 2;

        for (int i = -radius; i <= radius; i++) {
            for (int j = -radius; j <= radius; j++) {
                int currentX = x + i;
                int currentY = y + j;

                // 이미지 경계 확인
                if (currentX >= 0 && currentX < image.getSize().x && currentY >= 0 && currentY < image.getSize().y) {
                    sf::Color color = image.getPixel(currentX, currentY);
                    float weight = kernel[i + radius][j + radius];

                    red += color.r * weight;
                    green += color.g * weight;
                    blue += color.b * weight;
                }
            }
        }

        return sf::Color(static_cast<unsigned char>(red), static_cast<unsigned char>(green), static_cast<unsigned char>(blue));
    }
  };

}