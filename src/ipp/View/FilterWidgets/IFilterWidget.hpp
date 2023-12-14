/**
 * @file IFilterWidget.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include "ipp/common.hpp"


namespace Ipp
{
  interface IFilter;
  interface IFilterWidget
  {
    virtual bool isChanged() = 0;
    virtual IFilter* getFilterPtr() = 0;
    virtual int getPriorty() = 0;
  };
}