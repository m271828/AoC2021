#include <vector>

class CalculateLifeSupport
{
public:
  CalculateLifeSupport(): o2(0), co2(0) {}
  bool readData(std::string fileName);
  void calculateValues();
  int getO2GenRate();
  int getCO2ScrubRate();
  int getLifeSupportRate();

  enum class FAVOR
  {
    MIN,
    MAX
  };


private:
  std::string o2_str;
  int o2;
  std::string co2_str;
  int co2;
  std::vector<std::string> data;

  int convertToDecimal(std::string bin);
  std::string filter(std::vector<std::string> filteredData, char value, size_t idx, FAVOR fav);
};