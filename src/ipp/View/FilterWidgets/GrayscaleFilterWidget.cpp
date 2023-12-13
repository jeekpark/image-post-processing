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

    mPreviousActiveElementIndex = -1;
    bIsChanged = false;
    mGrayscaleFilter.setMethod(GrayscaleFilter::Average);
  }

  void GrayscaleFilterWidget::update(sf::Vector2f pos)
  {
    RadioButtonWidget::update(pos);
    std::cout << "asd" << std::endl;
    if (mPreviousActiveElementIndex == RadioButtonWidget::getActiveElementIndex())
    {
      bIsChanged = false;
    }
    else
    {
      bIsChanged = true;
      mPreviousActiveElementIndex = RadioButtonWidget::getActiveElementIndex();
      switch (RadioButtonWidget::getActiveElementIndex())
      {
      case 0:
        mGrayscaleFilter.setMethod(GrayscaleFilter::Average);
        break;
      case 1:
        mGrayscaleFilter.setMethod(GrayscaleFilter::Luminosity);
        break;
      case 2:
        mGrayscaleFilter.setMethod(GrayscaleFilter::Desaturation);
        break;
      case 3:
        mGrayscaleFilter.setMethod(GrayscaleFilter::SingleChannel);
        break;
      default:
        break;
      }
    }
  }

  bool GrayscaleFilterWidget::isChanged() const
  {
    return bIsChanged;
  }

  IFilter* GrayscaleFilterWidget::getFilterPtr()
  {
    return &mGrayscaleFilter;
  }

  int GrayscaleFilterWidget::getPriorty() const
  {
    return scPriority;
  }

}