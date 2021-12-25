#include <fstream>
#include <iostream>
#include "checkDepths.h"

CheckDepths::Result CheckDepths::readDepths(std::string fileName)
{
  std::ifstream file(fileName);
  std::string line;
  for(size_t i = 0; std::getline(file, line); ++i)
  {
      readings.emplace_back(std::stoi(line));
  }
  return Result::SUCCESS;
}

size_t CheckDepths::countDeeper()
{
  size_t deeper = 0;
  auto i = readings.begin();
  while(i != readings.end())
  {
    auto v1 = *i;
    ++i;
    auto v2 = *i;
    if(v2-v1 > 0)
    {
      deeper++;
    }
  }
  return deeper;
}

int CheckDepths::sumWindow(std::list<int>::iterator i, size_t window)
{
  int res = 0;
  for(size_t j = 0; j < window; j++)
  {
    res += *i;
    i++;
  }
  return res;
}

size_t CheckDepths::countDeeperSlidingWindow(size_t window)
{
  size_t deeper = 0;
  auto i = readings.begin();
  int lastWindow = sumWindow(i, window);
  i++;
  while(i != readings.end())
  {
    int thisWindow = sumWindow(i, window);
    if(lastWindow < thisWindow)
    {
      deeper++;
    }
    lastWindow = thisWindow;
    i++;
  }
  return deeper;
}