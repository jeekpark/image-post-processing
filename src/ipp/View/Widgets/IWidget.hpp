/**
 * @file IWidget.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "ipp/common.hpp"

#define interface struct

namespace Ipp
{
  interface IWidget
  {
    virtual ~IWidget() {}
    virtual bool isContains(sf::Vector2f pos) = 0;
    virtual void update(sf::Vector2f pos) = 0;
    virtual void drawTo(sf::RenderWindow& window) = 0;
  };
}