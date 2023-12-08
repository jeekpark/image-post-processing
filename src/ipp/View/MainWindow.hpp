/**
 * @file MainWindow.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "ipp/common.hpp"

#include "ipp/Image/Image.hpp"
#include "ipp/Filter/GrayscaleFilter.hpp"

namespace Ipp
{
  class MainWindow
  {
  public:
    void setup(const sf::Image& originalImage);
    void loop();
  private:
    enum GrayscaleMethod
    {
      Average = 0,
      Luminosity,
      Desaturation,
      SingleChannel,
      None
    };
  private:
    /**
     * @brief Images
     * 
     */
    sf::Image mOriginalImage;
    Image mPreviewImage;

    /**
     * @brief Windows
     * 
     */
    std::string mWindowTitle;
    sf::RenderWindow mWindow;

    /**
     * @brief Filters
     * 
     */
    GrayscaleFilter mGrayscaleFilter;

    /**
     * @brief About UI.
     * 
     */
    sf::Font mH1Font;
    sf::Font mH2Font;
    sf::Font mH3Font;

    sf::RectangleShape mGrayscaleWidgetBox;
    sf::Text mGrayscaleWidgetText;
    sf::RectangleShape mGrayAverageButton;
    sf::Text mGrayAverageText;
    sf::RectangleShape mGrayLuminosityButton;
    sf::Text mGrayLuminosityText;
    sf::RectangleShape mGrayDesaturationButton;
    sf::Text mGrayDesaturationText;
    sf::RectangleShape mGraySingleChannelButton;
    sf::Text mGraySingleChannelText;
    GrayscaleMethod eGrayscaleMethod;
    

    
  
  };
}