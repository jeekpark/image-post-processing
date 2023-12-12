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

#include "ipp/common.hpp"

namespace Ipp
{
  CheckBoxWidgetElement::CheckBoxWidgetElement(const std::string& label,
                                               sf::Vector2f pos,
                                               int index,
                                               bool state)
  {
    

    mFont.loadFromFile(ARIAL_FONT_PATH);
    mFont.setSmooth(true);

    mCheckBoxButton.setSize(sf::Vector2f(13.f, 13.f));
    mCheckBoxButton.setFillColor(BLACK_COLOR);
    mCheckBoxButton.setOutlineColor(WHITE_COLOR);
    mCheckBoxButton.setOutlineThickness(1.f);
    mCheckBoxButton.setPosition(sf::Vector2f(pos.x, pos.y));

    mLabelString = label;
    mLabelText.setString(mLabelString);
    mLabelText.setFont(mFont);
    mLabelText.setCharacterSize(15);
    mLabelText.setFillColor(WHITE_COLOR);
    mLabelText.setPosition(sf::Vector2f(pos.x + 80, pos.y));


    mIndex = index;
    bState = state;
  }

  CheckBoxWidgetElement::~CheckBoxWidgetElement()
  {}

  CheckBoxWidgetElement::CheckBoxWidgetElement(const CheckBoxWidgetElement& copy)
  {
    mLabelString = copy.mLabelString;
    mFont = copy.mFont;
    mLabelText = copy.mLabelText;
    mLabelText.setString(mLabelString);
    mLabelText.setFont(mFont);
    bState = copy.bState;
    mIndex = copy.mIndex;
    mCheckBoxButton = copy.mCheckBoxButton;
  }


  void CheckBoxWidgetElement::setState(bool state)
  {
    bState = state;
  }

  int CheckBoxWidgetElement::getIndex() const
  {
    return mIndex;
  }

  bool CheckBoxWidgetElement::getState() const
  {
    return bState;
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
    //std::cout << mLabelText.getFont() << " " << mIndex << std::endl;
  }


}