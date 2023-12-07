/**
 * @file Core.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ipp/Core/Core.hpp"



namespace Ipp
{
	Core::Core()
	: mWindowTitle("image-post-processing")
	, mWindow()
	, mFilePath()
	, mImage()
	{
		srand(time(NULL));
		mWindowTitle.append(" ");
		mWindowTitle.append(IPP_VERSION);
		mWindow.create(sf::VideoMode(WINDOW_X, WINDOW_Y), mWindowTitle);
		mWindow.setFramerateLimit(60);
		mWindow.clear();
	}

	Core::~Core()
	{}

	bool Core::initImage(const std::string& fileName)
	{
		if (!mImage.loadFromFile(fileName))
			return false;
		mImageSize = mImage.getSize();
		return true;
	}

	void Core::run()
	{
		for (unsigned int y = 0; y < mImageSize.y; ++y)
		{
			for (unsigned int x = 0; x < mImageSize.x; ++x)
			{
				sf::Color pixel = mImage.getPixel(x, y);
				sf::Uint8 gray = static_cast<sf::Uint8>(0.299f * pixel.r + 0.587f * pixel.g + 0.114f * pixel.b);
				mImage.setPixel(x, y, sf::Color(gray, gray, gray));
			}
		}
		sf::Texture t;
		t.loadFromImage(mImage);
		sf::Sprite s;
		s.setTexture(t);

		float iamgeAspectRatio = static_cast<float>(mImageSize.x) / mImageSize.y;
		float windowAspectRatio = static_cast<float>(WINDOW_X) / WINDOW_Y;

		float scale;
		if (iamgeAspectRatio > windowAspectRatio)
			scale = static_cast<float>(WINDOW_X) / mImageSize.x;
		else
			scale = static_cast<float>(WINDOW_Y) / mImageSize.y;
		s.setScale(scale, scale);
		s.setPosition((WINDOW_X - mImageSize.x * scale) / 2, (WINDOW_Y - mImageSize.y * scale) / 2);
		

		while (mWindow.isOpen())
		{
			sf::Event event;
			while (mWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					mWindow.close();
			}
			mWindow.clear();
			mWindow.draw(s);
			mWindow.display();
		}
	}
	
}