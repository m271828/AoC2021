#include <iostream>
#include "movementTracker.h"
#include "movementTrackerWithAim.h"

int main()
{
  MovementTracker mt;
  mt.seriesOfMoves("input");
  std::cout << "Final Horz: " << mt.getHorz() << std::endl;
  std::cout << "Final Vert: " << mt.getVert() << std::endl;
  std::cout << "Multiplied is: " << mt.getHorz()*mt.getVert() << std::endl;

  MovementTrackerWithAim mta;
  mta.seriesOfMoves("input");
  std::cout << "Final Horz: " << mta.getHorz() << std::endl;
  std::cout << "Final Vert: " << mta.getVert() << std::endl;
  std::cout << "Final Aim: " << mta.getAim() << std::endl;
  std::cout << "Multiple is: " << mta.getHorz()*mta.getVert() << std::endl;
}