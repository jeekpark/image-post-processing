/**
 * @file GrayscaleFilter.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include "ipp/common.hpp"

#include "ipp/Filter/IFilter.hpp"

namespace Ipp
{
  class GrayscaleFilter : public IFilter
  {
  public:
    enum Method
    {
      Average = 0,
      Luminosity,
      Desaturation,
      SingleChannel
    };
    GrayscaleFilter();
    virtual ~GrayscaleFilter();
    virtual void applyTo(sf::Image& image);
    void setMethod(Method method);
  private:
    sf::Uint8 getGrayPixelAverage(sf::Color pixel);
    sf::Uint8 getGrayPixelLuminosity(sf::Color pixel);
    sf::Uint8 getGrayPixelDesaturation(sf::Color pixel);
    sf::Uint8 getGrayPixelSingleChannel(sf::Color pixel);
    typedef sf::Uint8 (GrayscaleFilter::*functionPointer)(sf::Color);
    functionPointer getGrayPixel[4];
  private:
    Method eMethod;
  };
}