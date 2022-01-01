#include <iostream>
#include <vector>

class CalculateEpsilonGamma
{
private:
  std::vector<std::vector<int>> data;
  std::string gamma;
  int dec_gamma = 0;
  std::string epsilon;
  int dec_epsilon = 0;

  int convertToDecimal(std::string bin);

public:
  bool readData(std::string file);
  bool calculateComponents();
  int getGamma();
  int getEpsilon();
  int getPowerConsumption();
};