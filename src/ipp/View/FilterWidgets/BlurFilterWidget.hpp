/**
 * @file BlurFilterWidget.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "ipp/common.hpp"

#include "ipp/View/Widgets/RadioButtonWidget.hpp"
#include "ipp/Filter/GrayscaleFilter.hpp"
#include "ipp/View/FilterWidgets/IFilterWidget.hpp"

namespace Ipp
{
  class GrayscaleFilterWidget : public RadioButtonWidget
  {
  public:
    GrayscaleFilterWidget(sf::Vector2f pos);

  public: // RadioButtonWidget methods
    virtual void update(sf::Vector2f pos);

  public: // IFilterWidget methods
    virtual bool isChanged() const;
    virtual IFilter* getFilterPtr();
    virtual int getPriorty() const;
    
  private:
    int mPreviousActiveElementIndex;
    bool bIsChanged;
    GrayscaleFilter mGrayscaleFilter;
  private: // static variables
    static const int scPriority;
  };
}