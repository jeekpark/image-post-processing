/**
 * @file MainWindow.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ipp/View/MainWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "ipp/common.hpp"

namespace Ipp
{
  void MainWindow::setup(const sf::Image &originalImage)
  {
    mOriginalImage = originalImage;
    mPreviewImage = mOriginalImage;
    mWindowTitle = "image-post-processing ";
    mWindowTitle.append(IPP_VERSION);
    mWindow.create(sf::VideoMode(WINDOW_X, WINDOW_Y), mWindowTitle);
    mWindow.setFramerateLimit(60);
    mGrayscaleFilter.setMethod(GrayscaleFilter::Luminosity);
    

    mH1Font.loadFromFile(TIMES_FONT_PATH);
    mH1Font.setSmooth(true);
    mH2Font.loadFromFile(TIMES_FONT_PATH);
    mH2Font.setSmooth(true);
    mH3Font.loadFromFile(ARIAL_FONT_PATH);
    mH3Font.setSmooth(true);

    /**
     * @brief Gray widget box
     * 
     */
    mGrayscaleWidgetBox.setSize(sf::Vector2f(359.f - 8, 179.f - 8));
    mGrayscaleWidgetBox.setFillColor(BLACK_COLOR);
    mGrayscaleWidgetBox.setOutlineColor(WHITE_COLOR);
    mGrayscaleWidgetBox.setOutlineThickness(4.f);
    mGrayscaleWidgetBox.setPosition(4.f, 4.f);

    mGrayscaleWidgetText.setFont(mH2Font);
    mGrayscaleWidgetText.setCharacterSize(28);
    mGrayscaleWidgetText.setFillColor(WHITE_COLOR);
    mGrayscaleWidgetText.setPosition(12.f, 7.f);
    mGrayscaleWidgetText.setScale(0.72f, 1.f);
    mGrayscaleWidgetText.setString("GRAYSCALE");


    /**
     * @brief Average
     * 
     */
    mGrayAverageButton.setSize(sf::Vector2f(13, 13));
    mGrayAverageButton.setFillColor(BLACK_COLOR);
    mGrayAverageButton.setOutlineColor(WHITE_COLOR);
    mGrayAverageButton.setOutlineThickness(1.f);
    mGrayAverageButton.setPosition(15.f, 45.f);
  
    mGrayAverageText.setFont(mH3Font);
    mGrayAverageText.setCharacterSize(15);
    mGrayAverageText.setFillColor(WHITE_COLOR);
    mGrayAverageText.setPosition(35.f, 43.f);
    mGrayAverageText.setScale(0.76f, 1.f);
    mGrayAverageText.setString("AVERAGE METHOD");

    /**
     * @brief Luminosity
     * 
     */
    mGrayLuminosityButton.setSize(sf::Vector2f(13.f, 13.f));
    mGrayLuminosityButton.setFillColor(BLACK_COLOR);
    mGrayLuminosityButton.setOutlineColor(WHITE_COLOR);
    mGrayLuminosityButton.setOutlineThickness(1.f);
    mGrayLuminosityButton.setPosition(15.f, 45.f + 24);

    mGrayLuminosityText.setFont(mH3Font);
    mGrayLuminosityText.setCharacterSize(15);
    mGrayLuminosityText.setFillColor(WHITE_COLOR);
    mGrayLuminosityText.setPosition(35.f, 43.f + 24);
    mGrayLuminosityText.setScale(0.76f, 1.f);
    mGrayLuminosityText.setString("LUMINOSITY METHOD*");

    /**
     * @brief Desaturaion
     * 
     */
    mGrayDesaturationButton.setSize(sf::Vector2f(13.f, 13.f));
    mGrayDesaturationButton.setFillColor(BLACK_COLOR);
    mGrayDesaturationButton.setOutlineColor(WHITE_COLOR);
    mGrayDesaturationButton.setOutlineThickness(1.f);
    mGrayDesaturationButton.setPosition(15.f, 45.f + 24 * 2);

    mGrayDesaturationText.setFont(mH3Font);
    mGrayDesaturationText.setCharacterSize(15);
    mGrayDesaturationText.setFillColor(WHITE_COLOR);
    mGrayDesaturationText.setPosition(35.f, 43.f + 24 * 2);
    mGrayDesaturationText.setScale(0.76f, 1.f);
    mGrayDesaturationText.setString("DESATURATION METHOD");

    /**
     * @brief Single color channel
     * 
     */
    mGraySingleChannelButton.setSize(sf::Vector2f(13.f, 13.f));
    mGraySingleChannelButton.setFillColor(BLACK_COLOR);
    mGraySingleChannelButton.setOutlineColor(WHITE_COLOR);
    mGraySingleChannelButton.setOutlineThickness(1.f);
    mGraySingleChannelButton.setPosition(15.f, 45.f + 24 * 3);

    mGraySingleChannelText.setFont(mH3Font);
    mGraySingleChannelText.setCharacterSize(15);
    mGraySingleChannelText.setFillColor(WHITE_COLOR);
    mGraySingleChannelText.setPosition(35.f, 43.f + 24 * 3);
    mGraySingleChannelText.setScale(0.76f, 1.f);
    mGraySingleChannelText.setString("SINGLE CHANNEL METHOD");


    eGrayscaleMethod = MainWindow::None;
  }

  void MainWindow::loop()
  {
    Widget widget("test", sf::Vector2f(0, 400));
    widget.addCheckBox("hello");
    widget.addCheckBox("bye");
    widget.addCheckBox("good");

    while (mWindow.isOpen())
    {
      sf::Event event;
      while (mWindow.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
          mWindow.close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
          if (event.mouseButton.button == sf::Mouse::Left)
          {
            sf::Vector2i mousePos = sf::Mouse::getPosition(mWindow);
            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            if (widget.isContains(mousePosF))
            {
              widget.update(mousePosF);
              
            }
            if (mGrayAverageButton.getGlobalBounds().contains(mousePosF))
            {
              if (eGrayscaleMethod == Average)
              {
                eGrayscaleMethod = None;
                mPreviewImage = mOriginalImage;
                mGrayAverageButton.setFillColor(BLACK_COLOR);
              }
              else
              {
                eGrayscaleMethod = Average;
                mPreviewImage = mOriginalImage;
                mGrayscaleFilter.setMethod(GrayscaleFilter::Average);
                mPreviewImage.applyFilter(&mGrayscaleFilter);

                mGrayAverageButton.setFillColor(RED_COLOR);
                mGrayLuminosityButton.setFillColor(BLACK_COLOR);
                mGrayDesaturationButton.setFillColor(BLACK_COLOR);
                mGraySingleChannelButton.setFillColor(BLACK_COLOR);
              }
            }
            else if (mGrayLuminosityButton.getGlobalBounds().contains(mousePosF))
            {
              if (eGrayscaleMethod == Luminosity)
              {
                eGrayscaleMethod = None;
                mPreviewImage = mOriginalImage;
                mGrayLuminosityButton.setFillColor(BLACK_COLOR);
              }
              else
              {
                eGrayscaleMethod = Luminosity;
                mGrayscaleFilter.setMethod(GrayscaleFilter::Luminosity);
                mPreviewImage = mOriginalImage;
                mPreviewImage.applyFilter(&mGrayscaleFilter);

                mGrayAverageButton.setFillColor(BLACK_COLOR);
                mGrayLuminosityButton.setFillColor(RED_COLOR);
                mGrayDesaturationButton.setFillColor(BLACK_COLOR);
                mGraySingleChannelButton.setFillColor(BLACK_COLOR);
              }
            }
            else if (mGrayDesaturationButton.getGlobalBounds().contains(mousePosF))
            {
              if (eGrayscaleMethod == Desaturation)
              {
                eGrayscaleMethod = None;
                mPreviewImage = mOriginalImage;
                mGrayLuminosityButton.setFillColor(BLACK_COLOR);
              }
              else
              {
                eGrayscaleMethod = Desaturation;
                mGrayscaleFilter.setMethod(GrayscaleFilter::Desaturation);
                mPreviewImage = mOriginalImage;
                mPreviewImage.applyFilter(&mGrayscaleFilter);

                mGrayAverageButton.setFillColor(BLACK_COLOR);
                mGrayLuminosityButton.setFillColor(BLACK_COLOR);
                mGrayDesaturationButton.setFillColor(RED_COLOR);
                mGraySingleChannelButton.setFillColor(BLACK_COLOR);
              }
            }
            else if (mGraySingleChannelButton.getGlobalBounds().contains(mousePosF))
            {
              if (eGrayscaleMethod == SingleChannel)
              {
                eGrayscaleMethod = None;
                mPreviewImage = mOriginalImage;
                mGraySingleChannelButton.setFillColor(BLACK_COLOR);
              }
              else
              {
                eGrayscaleMethod = SingleChannel;
                mGrayscaleFilter.setMethod(GrayscaleFilter::SingleChannel);
                mPreviewImage = mOriginalImage;
                mPreviewImage.applyFilter(&mGrayscaleFilter);

                mGrayAverageButton.setFillColor(BLACK_COLOR);
                mGrayLuminosityButton.setFillColor(BLACK_COLOR);
                mGrayDesaturationButton.setFillColor(BLACK_COLOR);
                mGraySingleChannelButton.setFillColor(RED_COLOR);
              }
            }
          }
        }
      }
      sf::Texture t;
      t.loadFromImage(mPreviewImage);
      sf::Sprite s;
      s.setTexture(t);
      s.setPosition(361.f, 0.f);
      mWindow.clear();
      mWindow.draw(s);
      mWindow.draw(mGrayscaleWidgetBox);
      mWindow.draw(mGrayscaleWidgetText);
      mWindow.draw(mGrayAverageButton);
      mWindow.draw(mGrayAverageText);
      mWindow.draw(mGrayLuminosityButton);
      mWindow.draw(mGrayLuminosityText);
      mWindow.draw(mGrayDesaturationButton);
      mWindow.draw(mGrayDesaturationText);
      mWindow.draw(mGraySingleChannelButton);
      mWindow.draw(mGraySingleChannelText);
      widget.drawTo(mWindow);
      mWindow.display();
    }
  }
}