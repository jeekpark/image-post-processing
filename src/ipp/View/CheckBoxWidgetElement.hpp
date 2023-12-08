/**
 * @file CheckBoxWidgetElement.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "ipp/common.hpp"

namespace Ipp
{
  class CheckBoxWidgetElement
  {
  public:
    CheckBoxWidgetElement(const std::string& label, sf::Vector2f pos);
    ~CheckBoxWidgetElement();

    void setPosition(sf::Vector2f pos);
    void setLabel(const std::string& label);
    void setState(bool state);
  
    bool isContains(sf::Vector2f pos);
    void update();
    void drawTo(sf::RenderWindow& window);

  private:
    std::string mLabelString;

    sf::Font mFont;
    sf::RectangleShape mCheckBoxButton;
    sf::Text mLabelText;
    bool bState;
  };
}