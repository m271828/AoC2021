#include <iostream>
#include "movementTracker.h"

int main()
{
  MovementTracker mt;
  mt.seriesOfMoves("input");
  std::cout << "Final Horz: " << mt.getHorz() << std::endl;
  std::cout << "Final Vert: " << mt.getVert() << std::endl;
  std::cout << "Multiplied is: " << mt.getHorz()*mt.getVert() << std::endl;
}