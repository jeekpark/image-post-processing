/**
 * @file CheckBoxWidgetElement.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ipp/View/CheckBoxWidgetElement.hpp"

namespace Ipp
{
  CheckBoxWidgetElement::CheckBoxWidgetElement(const std::string& label, sf::Vector2f pos)
  {
    mLabelString = label;

    mFont.loadFromFile(ARIAL_FONT_PATH);
    mFont.setSmooth(true);

    mCheckBoxButton.setSize(sf::Vector2f(13.f, 13.f));
    mCheckBoxButton.setFillColor(BLACK_COLOR);
    mCheckBoxButton.setOutlineColor(WHITE_COLOR);
    mCheckBoxButton.setOutlineThickness(1.f);
    mCheckBoxButton.setPosition(sf::Vector2f(pos.x + 20, pos.y));

    mLabelText.setFont(mFont);
    mLabelText.setCharacterSize(15);
    mLabelText.setFillColor(WHITE_COLOR);
    mLabelText.setPosition(pos);
    mLabelText.setScale(0.76f, 1.f);
    mLabelText.setString(mLabelString);
  }

  CheckBoxWidgetElement::~CheckBoxWidgetElement()
  {}

  void CheckBoxWidgetElement::setPosition(sf::Vector2f pos)
  {
    mCheckBoxButton.setPosition(sf::Vector2f(pos.x + 20, pos.y));
    mLabelText.setPosition(pos);
  }

  void CheckBoxWidgetElement::setLabel(const std::string &label)
  {
    mLabelString = label;
    mLabelText.setString(mLabelString);
  }

  void CheckBoxWidgetElement::setState(bool state)
  {
    bState = state;
  }

  bool CheckBoxWidgetElement::isContains(sf::Vector2f pos)
  {
    return mCheckBoxButton.getGlobalBounds().contains(pos);
  }

  void CheckBoxWidgetElement::update()
  {
    if (bState) mCheckBoxButton.setFillColor(RED_COLOR);
    else mCheckBoxButton.setFillColor(BLACK_COLOR);
  }

  void CheckBoxWidgetElement::drawTo(sf::RenderWindow &window)
  {
    window.draw(mLabelText);
    window.draw(mCheckBoxButton);
  }


}