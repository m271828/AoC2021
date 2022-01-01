#include <bitset>
#include <fstream>
#include "CalculateLifeSupport.h"

int CalculateLifeSupport::convertToDecimal(std::string bin)
{
  return std::bitset<64>(bin).to_ullong();
}

bool CalculateLifeSupport::readData(std::string fileName)
{
  std::ifstream file(fileName);
  std::string line;
  for(size_t i = 0; std::getline(file, line); ++i)
  {
    data.emplace_back(line);
  }
  return true;
}

void CalculateLifeSupport::calculateValues()
{
  auto o2 = data;
  auto co2 = data;

  size_t count0 = 0, count1 = 0;
  std::string str_o2, str_co2;
  for(size_t i = 0; i < data.size(); ++i)
  {
    if(data[i][0] == '0')
    {
      count0++;
    }
    else
    {
      count1++;
    }
  }
  if(count1 >= count0)
  {
    str_o2 = filter(o2, '1', 0, FAVOR::MAX);
    str_co2 = filter(co2, '0', 0, FAVOR::MIN);
  }
  else
  {
    str_o2 = filter(o2, '0', 0, FAVOR::MAX);
    str_co2 = filter(o2, '0', 0, FAVOR::MIN);
  }

  this->o2 = convertToDecimal(str_o2);
  this->co2 = convertToDecimal(str_co2);
}

std::string CalculateLifeSupport::filter(std::vector<std::string> filteredData, char value, size_t idx, FAVOR fav)
{
  std::vector<std::string> next;
  for(auto i = filteredData.begin(); i != filteredData.end(); ++i)
  {
    if((*i)[idx] == value)
    {
      next.emplace_back(*i);
    }
  }

  if(next.size() == 1)
  {
    return next[0];
  }

  idx++;
  if(idx >= next[0].length())
  {
    return "";
  }
  
  size_t count0 = 0, count1 = 0;
  for(size_t i = 0; i < next.size(); i++)
  {
    if(next[i][idx] == '0')
    {
      count0++;
    }
    else
    {
      count1++;
    }
  }
  if(count1 >= count0 && fav == FAVOR::MAX)
  {
    return filter(next, '1', idx, fav);
  }
  else if(count1 >= count0 && fav == FAVOR::MIN)
  {
    return filter(next, '0', idx, fav);
  }
  else if(count1 <= count0 && fav == FAVOR::MIN)
  {
    return filter(next, '1', idx, fav);
  }
  else if(count1 <= count0 && fav == FAVOR::MAX)
  {
    return filter(next, '0', idx, fav);
  }
}

int CalculateLifeSupport::getO2GenRate()
{
  return o2;
}

int CalculateLifeSupport::getCO2ScrubRate()
{
  return co2;
}

int CalculateLifeSupport::getLifeSupportRate()
{
  return o2*co2;
}