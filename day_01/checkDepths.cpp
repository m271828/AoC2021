#include <fstream>
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