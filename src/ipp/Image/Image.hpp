/**
 * @file Image.hpp
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
  class Image : public sf::Image
  {
  public:
    Image& operator=(const Image& other);
    Image& operator=(const sf::Image& other);
    void applyFilter(IFilter* filter);
    const sf::Image& sfImage() const;
  };
}