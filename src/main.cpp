/**
 * @file main.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ipp/Core/Core.hpp"

int
main(
  const int argc,
  const char** argv
)
{
  if (argc != 2)
  {
    std::cerr << "usage: ./imagepp <file>" << std::endl;
    return 1;
  }
  Ipp::Core* app = new Ipp::Core();
  if (!app->loadOriginalImage(argv[1]))
  {
    std::cerr << "error: Failed to load image, \"" << argv[1] << "\"." << std::endl;
    delete app;
    return 1;
  }
  app->run();
  delete app;
  return 0;
}