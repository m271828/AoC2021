#include <iostream>
#include "CalculateEpsilonGamma.h"
#include "CalculateLifeSupport.h"

int main()
{
  CalculateEpsilonGamma engine;
  engine.readData("input");
  engine.calculateComponents();
  std::cout << "Epsilon: " << engine.getEpsilon() << std::endl;
  std::cout << "Gamma: " << engine.getGamma() << std::endl;
  std::cout << "Power Consumption: " << engine.getPowerConsumption() << std::endl;
  CalculateLifeSupport lifeEngine;
  lifeEngine.readData("input");
  lifeEngine.calculateValues();
  std::cout << "O2 Generator Rating: " << lifeEngine.getO2GenRate() << std::endl;
  std::cout << "CO2 Scrubber Rating: " << lifeEngine.getCO2ScrubRate() << std::endl;
  std::cout << "Life Support Rating: " << lifeEngine.getLifeSupportRate() << std::endl;
}