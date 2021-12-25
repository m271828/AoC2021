#include <iostream>
#include "checkDepths.h"

int main()
{
  CheckDepths cp;
  if(cp.readDepths("input") != CheckDepths::Result::SUCCESS)
    return -1;
  std::cout << cp.countDeeper() << std::endl;
  return 0;
}