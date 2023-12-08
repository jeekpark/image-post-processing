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
	Core::Core(){}
	Core::~Core(){}

	bool Core::loadOriginalImage(const std::string &fileName)
	{
		if (!mOriginalImage.loadFromFile(fileName)) return false;
		else return true;
	}

	void Core::run()
	{
		mMainWindow.setup(mOriginalImage);
		mMainWindow.loop();
	}
	
}