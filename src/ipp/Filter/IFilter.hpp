/**
 * @file IFilter.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "./ipp/common.hpp"

namespace Ipp
{
  class IFilter
  {
  public:
    virtual ~IFilter() {}
    virtual void applyTo(sf::Image& image) = 0;
  };
}