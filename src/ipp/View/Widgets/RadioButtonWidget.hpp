/**
 * @file RadioButtonWidget.hpp
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

#include "ipp/View/Widgets/IWidget.hpp"
#include "ipp/View/Widgets/Elements/CheckBoxWidgetElement.hpp"

namespace Ipp
{
  class RadioButtonWidget : public IWidget
  {
  public:
    RadioButtonWidget(const std::string& widgetName, sf::Vector2f widgetPos);
    void addElement(const std::string& elementName, bool initState = false);
    int getActiveElementIndex() const;
  public:// interface functions
    virtual ~RadioButtonWidget();
    virtual bool isContains(sf::Vector2f pos);
    virtual void update(sf::Vector2f pos);
    virtual void drawTo(sf::RenderWindow& window);
  private:
    void fillCheckBox(bool state);
  private:
    std::string mWidgetNameString;
    sf::Vector2f mWidgetPos;

    sf::Font mWidgetNameFont;
    sf::Text mWidgetNameText;
    sf::RectangleShape mWidgetBox;
    std::list<CheckBoxWidgetElement> mElements;

    static const unsigned int scWidgetNameCharacterSize;
    static const float scWidgetNameWidthScale;

    static const float scWidgetBoxMarginTop;
    static const float scWidgetBoxMarginLeft;
    static const float scWidgetBoxMarginBot;

    static const sf::Vector2f scWidgetBoxSize;
    static const float scWidgetBoxOutlineThickness;
  };
}