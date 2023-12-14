/**
 * @file BlurFilter.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "ipp/Filter/BlurFilter.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/System/Vector2.hpp"


namespace Ipp
{
	const int BlurFilter::scMaxRadius = 5;
	BlurFilter::BlurFilter()
	{
		eMethod = Box;
		mRadius = 1;
		blurMethods[Box] = &BlurFilter::boxMethod;
		blurMethods[Gaussian] = &BlurFilter::gaussianMethod;
	}

	BlurFilter::~BlurFilter()
	{}

	void BlurFilter::applyTo(sf::Image& image)
	{
		(this->*blurMethods[eMethod])(image);
	}

	void BlurFilter::setMethod(Method method)
	{
		eMethod = method;
	}

	void BlurFilter::boxMethod(sf::Image& image)
	{
		sf::Image tempImage = image;
		sf::Vector2u size = tempImage.getSize();
		for (unsigned int x = 0; x < size.x; ++x)
		{
			for (unsigned int y = 0; y < size.y; ++y)
			{
				int r = 0, g = 0, b = 0;
				for (int i = (int)x - scMaxRadius; i <= (int)x + scMaxRadius; ++i)
				{
					int temp = i;
					if (temp < 0) temp = 0;
					else if (temp >= size.x) temp = size.x - 1;
					r += tempImage.getPixel(temp, y).r;
					g += tempImage.getPixel(temp, y).g;
					b += tempImage.getPixel(temp, y).b;
				}
				r /= 51;
				g /= 51;
				b /= 51;
				image.setPixel(x, y, sf::Color(r, g, b));
			}
		}
		tempImage = image;
		for (unsigned int x = 0; x < size.x; ++x)
		{
			for (unsigned int y = 0; y < size.y; ++y)
			{
				int r = 0, g = 0, b = 0;
				for (int i = (int)y - scMaxRadius; i <= (int)y + scMaxRadius; ++i)
				{
					int temp = i;
					if (temp < 0) temp = 0;
					else if (temp >= size.y) temp = size.y - 1;
					r += tempImage.getPixel(x, temp).r;
					g += tempImage.getPixel(x, temp).g;
					b += tempImage.getPixel(x, temp).b;
				}
				r /= 51;
				g /= 51;
				b /= 51;
				image.setPixel(x, y, sf::Color(r, g, b));
			}
		}
	}

	void BlurFilter::gaussianMethod(sf::Image& image)
	{
		std::vector<std::vector<float>> kernel = createGaussianKernel(scMaxRadius);

        // 이미지 복사 (원본 수정을 피하기 위해)
        sf::Image originalImage = image;

        // 이미지의 모든 픽셀에 대해 블러 처리
        for (unsigned x = 0; x < image.getSize().x; x++) {
            for (unsigned y = 0; y < image.getSize().y; y++) {
                sf::Color blurredColor = applyKernel(originalImage, kernel, x, y);
                image.setPixel(x, y, blurredColor);
            }
        }
	}


}