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


#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "ipp/common.hpp"

#include "ipp/View/CheckBoxWidgetElement.hpp"

namespace Ipp
{
  class Widget
  {
  public:
    Widget(const std::string& widgetName, sf::Vector2f pos);
    
    void addCheckBox(const std::string& label);

    bool isContains(sf::Vector2f pos);
    void update(sf::Vector2f pos);
    void drawTo(sf::RenderWindow& window);
    
    int getActiveCheckBoxIndex() const;
    
  private:
    void fillCheckBox(bool state);
  private:
    std::string mWidgetNameString;
    sf::Font mFont;
    sf::Text mWidgetNameText;
    sf::RectangleShape mWidgetBox;
    
    std::vector<CheckBoxWidgetElement> mCheckBoxs;
  };
}