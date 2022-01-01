#include <iostream>
#include "CalculateEpsilonGamma.h"

int main()
{
  CalculateEpsilonGamma engine;
  engine.readData("input");
  engine.calculateComponents();
  std::cout << "Epsilon: " << engine.getEpsilon() << std::endl;
  std::cout << "Gamma: " << engine.getGamma() << std::endl;
  std::cout << "Power Consumption: " << engine.getPowerConsumption() << std::endl;
}