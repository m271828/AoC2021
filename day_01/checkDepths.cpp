#include <fstream>
#include <iostream>
#include "checkDepths.h"

CheckDepths::Result CheckDepths::readDepths(std::string fileName)
{
  std::ifstream file(fileName);
  std::string line;
  for(std::size_t i = 0; std::getline(file, line); ++i)
  {
      readings.emplace_back(std::stoi(line));
  }
  return Result::SUCCESS;
}

std::size_t CheckDepths::countDeeper()
{
  std::size_t deeper = 0;
  auto i = readings.begin();
  auto end = --readings.end();
  while(i != end)
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

int CheckDepths::sumWindow(std::list<int>::iterator i, std::size_t window)
{
  int res = 0;
  for(std::size_t j = 0; j < window; j++)
  {
    res += *i;
    i++;
  }
  return res;
}

std::size_t CheckDepths::countDeeperSlidingWindow(std::size_t window)
{
  std::size_t deeper = 0;
  auto i = readings.begin();
  auto end = --(--readings.end());
  int lastWindow = sumWindow(i, window);
  i++;
  while(i != end)
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
