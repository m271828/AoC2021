#include <iostream>
#include "checkDepths.h"

int main()
{
  CheckDepths cp;
  if(cp.readDepths("input") != CheckDepths::Result::SUCCESS)
    return -1;
  std::cout << "Measure to Measure: " << cp.countDeeper() << std::endl;
  std::cout << "Windows of 3: " << cp.countDeeperSlidingWindow(3) << endl;
  return 0;
}