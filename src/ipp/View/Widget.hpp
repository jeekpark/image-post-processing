/**
 * @file Widget.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ipp/common.hpp"

#include "ipp/View/CheckBoxWidgetElement.hpp"

namespace Ipp
{
  class Widget
  {
  public:
    Widget(const std::string& widgetName);

    void setWidgetName(const std::string& widgetName);
    void addCheckBox(const std::string& label);
    
    sf::Vector2f getWidgetBoxSize() const;

  private:
    std::string mWidgetNameString;
    sf::Font mFont;
    sf::Text mWidgetNameText;
    sf::RectangleShape mWidgetBox;
    
    std::vector<CheckBoxWidgetElement> mCheckBoxs;


    

  };
}