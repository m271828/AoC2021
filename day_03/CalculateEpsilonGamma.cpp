#include <bitset>
#include <fstream>
#include <math.h>
#include "CalculateEpsilonGamma.h"

int CalculateEpsilonGamma::convertToDecimal(std::string bin)
{
  return std::bitset<64>(bin).to_ullong();
}

bool CalculateEpsilonGamma::readData(std::string fileName)
{
  std::ifstream file(fileName);
  std::string line;
  for(size_t i = 0; std::getline(file, line); ++i)
  {
    std::vector<int> rep;
    for(size_t j = 0; j < line.length(); ++j)
    {
      auto val = line[j] == 48 ? 0 : 
                                     line[j] == 49 ? 1 : NAN;
      rep.emplace_back(val);
    }
    data.emplace_back(rep);
  }
  return true;
}

bool CalculateEpsilonGamma::calculateComponents()
{
  auto numbers = data.size();
  auto len = data[0].size();
  int counts[len] = {};
  for(size_t i = 0; i < data.size(); ++i)
  {
    for(size_t j = 0; j < len; ++j)
    {
      counts[j] += data[i][j];
    }
  }
  auto half = round(data.size()/2);
  for(size_t i = 0; i < len; ++i)
  {
    if(counts[i] > half)
    {
      gamma.append("1");
      epsilon.append("0");
    }
    else
    {
      gamma.append("0");
      epsilon.append("1");
    }
  }
  return true;
}

int CalculateEpsilonGamma::getGamma()
{
  if(dec_gamma != 0)
  {
    return dec_gamma;
  }
  dec_gamma = convertToDecimal(gamma);
  return dec_gamma;
}

int CalculateEpsilonGamma::getEpsilon()
{
  if(dec_epsilon != 0)
  {
    return dec_epsilon;
  }
  dec_epsilon = convertToDecimal(epsilon);
  return dec_epsilon;
}

int CalculateEpsilonGamma::getPowerConsumption()
{
  return (getGamma()*getEpsilon());
}