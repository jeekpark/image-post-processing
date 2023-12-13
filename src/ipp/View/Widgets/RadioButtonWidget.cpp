/**
 * @file RadioButtonWidget.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ipp/View/Widgets/RadioButtonWidget.hpp"

namespace Ipp
{
  const unsigned int RadioButtonWidget::scWidgetNameCharacterSize = 28;
  const float RadioButtonWidget::scWidgetNameWidthScale = 0.72f;

  const float RadioButtonWidget::scWidgetBoxMarginTop = 3.f;
  const float RadioButtonWidget::scWidgetBoxMarginLeft = 12.f;
  const float RadioButtonWidget::scWidgetBoxMarginBot = 3.f;

  const float RadioButtonWidget::scWidgetBoxOutlineThickness = 2.f;
  const sf::Vector2f RadioButtonWidget::scWidgetBoxSize = sf::Vector2f(360.f, 37.f);


  RadioButtonWidget::RadioButtonWidget(const std::string& widgetName, sf::Vector2f widgetPos)
  {
    mWidgetNameString = widgetName;
    mWidgetPos = widgetPos;

    mWidgetNameFont.loadFromFile(TIMES_FONT_PATH);
    mWidgetNameFont.setSmooth(true);

    mWidgetNameText.setString(mWidgetNameString);
    mWidgetNameText.setFont(mWidgetNameFont);
    mWidgetNameText.setCharacterSize(scWidgetNameCharacterSize);
    mWidgetNameText.setFillColor(WHITE_COLOR);
    mWidgetNameText.setPosition(mWidgetPos.x + scWidgetBoxMarginLeft,
                                mWidgetPos.y + scWidgetBoxMarginTop);
    mWidgetNameText.setScale(scWidgetNameWidthScale, 1.f);

    mWidgetBox.setSize(sf::Vector2f(scWidgetBoxSize.x - (2 * scWidgetBoxOutlineThickness),
                                    scWidgetBoxSize.y - (2 * scWidgetBoxOutlineThickness) + scWidgetBoxMarginBot));
    mWidgetBox.setFillColor(BLACK_COLOR);
    mWidgetBox.setOutlineColor(WHITE_COLOR);
    mWidgetBox.setOutlineThickness(scWidgetBoxOutlineThickness);
    mWidgetBox.setPosition(mWidgetPos.x + scWidgetBoxOutlineThickness,
                           mWidgetPos.y + scWidgetBoxOutlineThickness);
  }

  void RadioButtonWidget::addElement(const std::string &elementName, bool initstate)
  {
    mElements.push_back(CheckBoxWidgetElement(elementName,
                                              sf::Vector2f(13.f, (37 + mWidgetBox.getPosition().y) + 20.f * mElements.size()),
                                              mElements.size(),
                                              initstate));
    mWidgetBox.setSize(sf::Vector2f(scWidgetBoxSize.x - (2 * scWidgetBoxOutlineThickness),
                                    scWidgetBoxSize.y - (2 * scWidgetBoxOutlineThickness) + scWidgetBoxMarginBot + (20.f * mElements.size())));
  }

  int RadioButtonWidget::getActiveElementIndex() const
  {
    for (std::list<CheckBoxWidgetElement>::const_iterator it = mElements.begin();
         it != mElements.end(); ++it)
    {
      if (it->getState())
        return it->getIndex();
    }
    return -1;
  }

  RadioButtonWidget::~RadioButtonWidget()
  {

  }

  bool RadioButtonWidget::isContains(sf::Vector2f pos)
  {
    return mWidgetBox.getGlobalBounds().contains(pos);
  }

  void RadioButtonWidget::update(sf::Vector2f pos)
  {
    for (std::list<CheckBoxWidgetElement>::iterator it = mElements.begin();
         it != mElements.end(); ++it)
    {
      if (it->isContains(pos))
      {
        if (it->getState())
        {
          fillCheckBox(false);
          return ;
        }
        else
        {
          fillCheckBox(false);
          it->setState(true);
          it->update();
          return ;
        }
      }
    }
  }

  void RadioButtonWidget::drawTo(sf::RenderWindow &window)
  {
    window.draw(mWidgetBox);
    window.draw(mWidgetNameText);
    for (std::list<CheckBoxWidgetElement>::iterator it = mElements.begin();
				 it != mElements.end(); ++it)
		{
			it->drawTo(window);
		}
  }


  void RadioButtonWidget::fillCheckBox(bool state)
	{
		for (std::list<CheckBoxWidgetElement>::iterator it = mElements.begin();
		     it != mElements.end(); ++it)
		{
			it->setState(state);
			it->update();
		}
	}
}