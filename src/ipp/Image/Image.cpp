/**
 * @file Image.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ipp/Image/Image.hpp"

namespace Ipp
{
  Image& Image::operator=(const Image& other)
  {
    if (this != &other)
    {
      sf::Image::operator=(other);
    }
    return *this;
  }

  Image& Image::operator=(const sf::Image& other)
  {
    if (this != &other)
    {
      sf::Image::operator=(other);
    }
    return *this;
  }

  void Image::applyFilter(IFilter *filter)
  {
    filter->applyTo(*this);
  }

  const sf::Image& Image::sfImage() const
  {
    return *this;
  }
}