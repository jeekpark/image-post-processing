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

#include "ipp/View/MainWindow.hpp"

namespace Ipp
{
	class Core
	{
	public:
		Core();
		~Core();
		bool loadOriginalImage(const std::string& fileName);
		void run();
	private:
		std::string mFilePath;
		sf::Image mOriginalImage;
		MainWindow mMainWindow;
	};
}