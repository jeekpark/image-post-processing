/**
 * @file Widget.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ipp/View/Widget.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "ipp/common.hpp"
#include <vector>

namespace Ipp
{
	Widget::Widget(const std::string& widgetName, sf::Vector2f pos)
	{
		mFont.loadFromFile(TIMES_FONT_PATH);
		mFont.setSmooth(true);
		
		mWidgetBox.setSize(sf::Vector2f(360.f, 48 + 40.f * mCheckBoxs.size()));
		mWidgetBox.setFillColor(BLACK_COLOR);
		mWidgetBox.setOutlineColor(WHITE_COLOR);
		mWidgetBox.setOutlineThickness(1.f);
		mWidgetBox.setPosition(pos); // argument use


		mWidgetNameString = widgetName; // argument use
		mWidgetNameText.setString(mWidgetNameString);
		mWidgetNameText.setFont(mFont);
		mWidgetNameText.setCharacterSize(28);
		mWidgetNameText.setFillColor(WHITE_COLOR);
		mWidgetNameText.setPosition(pos.x + 8, pos.y + 3);
	}

	void Widget::addCheckBox(const std::string& label)
	{
		mCheckBoxs.push_back(CheckBoxWidgetElement(label, 
																									sf::Vector2f(8.f, (48 + mWidgetBox.getPosition().y) + 40.f * mCheckBoxs.size()),
																									mCheckBoxs.size(),
																									false));
																				
		mWidgetBox.setSize(sf::Vector2f(360.f, 48 + 40.f * mCheckBoxs.size()));
	}

	bool Widget::isContains(sf::Vector2f pos)
	{
		return mWidgetBox.getGlobalBounds().contains(pos);
	}

	void Widget::update(sf::Vector2f pos)
	{
		for (std::vector<CheckBoxWidgetElement>::iterator it = mCheckBoxs.begin();
				 it != mCheckBoxs.end(); ++it)
		{
			if (it->isContains(pos))
			{
				fillCheckBox(false); // setState() and update()
				it->setState(true);
				it->update();
				return;
			}
		}
	}

	void Widget::drawTo(sf::RenderWindow& window)
	{
		window.draw(mWidgetBox);
		window.draw(mWidgetNameText);
		for (std::vector<CheckBoxWidgetElement>::iterator it = mCheckBoxs.begin();
				 it != mCheckBoxs.end(); ++it)
		{
			it->drawTo(window);
		}
	}

	int Widget::getActiveCheckBoxIndex() const
	{
		for (std::vector<CheckBoxWidgetElement>::const_iterator it = mCheckBoxs.begin();
				 it != mCheckBoxs.end(); ++it)
		{
			if (it->getState())
				return it->getIndex();
		}
		return -1;
	}


	/* private */
	void Widget::fillCheckBox(bool state)
	{
		for (std::vector<CheckBoxWidgetElement>::iterator it = mCheckBoxs.begin();
		     it != mCheckBoxs.end(); ++it)
		{
			it->setState(state);
			it->update();
		}
	}

}