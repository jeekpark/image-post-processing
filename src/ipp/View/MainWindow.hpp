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

#include "ipp/View/FilterWidgets/GrayscaleFilterWidget.hpp"

namespace Ipp
{
  class MainWindow
  {
  public:
    MainWindow();
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
    GrayscaleMethod eGrayscaleMethod;


    
  
  };
}