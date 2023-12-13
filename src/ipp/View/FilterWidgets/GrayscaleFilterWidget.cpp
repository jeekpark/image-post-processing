/**
 * @file GrayscaleFilterWidget.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "ipp/View/FilterWidgets/GrayscaleFilterWidget.hpp"

namespace Ipp
{
  const int GrayscaleFilterWidget::scPriority = 1;

  GrayscaleFilterWidget::GrayscaleFilterWidget(sf::Vector2f pos)
  : RadioButtonWidget("GRAYSCALE", pos)
  {
    addElement("Average method");
    addElement("Luminosity method *suitable for human eyes");
    addElement("Desaturation method");
    addElement("Single color channel method(red)");
  }
}