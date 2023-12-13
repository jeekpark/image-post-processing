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

#include "ipp/common.hpp"

namespace Ipp
{
  MainWindow::MainWindow()
  {

  }
  void MainWindow::setup(const sf::Image &originalImage)
  {
    mOriginalImage = originalImage;
    mPreviewImage = mOriginalImage;
    mWindowTitle = "image-post-processing ";
    mWindowTitle.append(IPP_VERSION);
    mWindow.create(sf::VideoMode(WINDOW_X, WINDOW_Y), mWindowTitle);
    mWindow.setFramerateLimit(60);
    mGrayscaleFilter.setMethod(GrayscaleFilter::Luminosity);
    
    eGrayscaleMethod = MainWindow::None;

  }

  void MainWindow::loop()
  {

    RadioButtonWidget test("HELLO", sf::Vector2f(0, 0));
    test.addElement("GOOD");
    test.addElement("const std::string &elementName");
    while (mWindow.isOpen())
    {
      sf::Event event;
      while (mWindow.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
        {
          mWindow.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
          if (event.mouseButton.button == sf::Mouse::Left)
          {
            sf::Vector2i mousePos = sf::Mouse::getPosition(mWindow);
            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            if (test.isContains(mousePosF))
            {
              test.update(mousePosF);
              
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

      test.drawTo(mWindow);
      mWindow.display();
    }
  }
}