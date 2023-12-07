/**
 * @file Core.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once


#include "ipp/common.hpp"

namespace Ipp
{
	class Core
	{
	public:
		Core();
		~Core();
		bool initImage(const std::string& fileName);
		void run();

	private:
		std::string mWindowTitle;
		sf::RenderWindow mWindow;
		std::string mFilePath;		
		sf::Image mImage;
		sf::Vector2u mImageSize;
	};
}