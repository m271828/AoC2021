#include <iostream>
#include <string>

#include "checkDepths.h"

int main()
{
  CheckDepths cp;
  if(cp.readDepths(std::string("input")) != CheckDepths::Result::SUCCESS)
    return -1;
  std::cout << "Measure to Measure: " << cp.countDeeper() << std::endl;
  std::cout << "Windows of 3: " << cp.countDeeperSlidingWindow(3) << std::endl;
  return 0;
}
