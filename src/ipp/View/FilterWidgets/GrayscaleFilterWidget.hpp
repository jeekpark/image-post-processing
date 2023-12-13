/**
 * @file GrayscaleWidget.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ipp/common.hpp"

#include "ipp/View/Widgets/RadioButtonWidget.hpp"

namespace Ipp
{
  class GrayscaleFilterWidget : public RadioButtonWidget
  {
  public:
    GrayscaleFilterWidget(sf::Vector2f pos);
  private:
    static const int scPriority;    
  };
}