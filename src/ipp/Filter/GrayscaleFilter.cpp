/**
 * @file GrayscaleFilter.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "ipp/Filter/GrayscaleFilter.hpp"

namespace Ipp
{
  GrayscaleFilter::GrayscaleFilter()
  {
    eMethod = Luminosity;
    getGrayPixel[Average] = &GrayscaleFilter::getGrayPixelAverage;
    getGrayPixel[Luminosity] = &GrayscaleFilter::getGrayPixelLuminosity;
    getGrayPixel[Desaturation] = &GrayscaleFilter::getGrayPixelDesaturation;
    getGrayPixel[SingleChannel] = &GrayscaleFilter::getGrayPixelSingleChannel;
  }

  GrayscaleFilter::~GrayscaleFilter()
  {}

  void GrayscaleFilter::applyTo(sf::Image &image)
  {
    sf::Image tempImage = image;
    sf::Vector2u size = tempImage.getSize();
    for(unsigned int x = 0; x < size.x; ++x)
    {
      for (unsigned int y = 0; y < size.y; ++y)
      {
        sf::Uint8 gray = (this->*getGrayPixel[eMethod])(tempImage.getPixel(x, y));
        image.setPixel(x, y, sf::Color(gray, gray, gray));
      }
    }
  }

  void GrayscaleFilter::setMethod(Method method)
  {
    eMethod = method;
  }


  sf::Uint8 GrayscaleFilter::getGrayPixelAverage(sf::Color pixel)
  {
    return (pixel.r + pixel.g + pixel.b) / 3;
  }
  sf::Uint8 GrayscaleFilter::getGrayPixelLuminosity(sf::Color pixel)
  {
    return (0.299 * pixel.r) + (0.587 * pixel.g) + (0.114 * pixel.b);
  }
  sf::Uint8 GrayscaleFilter::getGrayPixelDesaturation(sf::Color pixel)
  {
    return (std::max(pixel.r, std::max(pixel.g, pixel.b)) +
            std::min(pixel.r, std::min(pixel.g, pixel.b)))
           / 2;
  }
  sf::Uint8 GrayscaleFilter::getGrayPixelSingleChannel(sf::Color pixel)
  {
    return pixel.r;
  }
}