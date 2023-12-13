#pragma once

#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>
#include <random>
#include <iomanip>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define interface         struct
#define IPP_VERSION				"0.0.1a"

#define TIMES_FONT_PATH   "resource/Times New Roman/times new roman bold.ttf"
#define ARIAL_FONT_PATH   "resource/arial-cufonfonts/ARIAL.TTF"
#define LIGHT_FONT_PATH   "./resource/louis_george_cafe/Louis George Cafe Light.ttf"

#define ORANGE_COLOR      (sf::Color(255, 114, 53))
#define WHITE_COLOR       (sf::Color(255, 255, 255))
#define SKYBLUE_COLOR     (sf::Color(177, 225, 248))
#define RED_COLOR         (sf::Color(254, 3, 76))
#define BLACK_COLOR       (sf::Color(0, 0, 0))

#define WINDOW_X					1920
#define WINDOW_Y					1080