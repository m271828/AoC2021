#include <fstream>
#include <sstream>
#include "movementTrackerWithAim.h"

bool MovementTrackerWithAim::move(int horz)
{
  this->horz += horz;
  vert += aim*horz;
  return true;
}

bool MovementTrackerWithAim::adjustAim(int aim)
{
  this->aim += aim;
  return true;
}

bool MovementTrackerWithAim::seriesOfMoves(std::string fileName)
{
  std::ifstream file(fileName);
  std::string line;
  for(size_t i = 0; std::getline(file, line); ++i)
  {
    std::stringstream stream(line);
    std::string direction;
    int dist = 0;
    stream >> direction >> dist;
    if(direction == "up")
    {
      adjustAim(-dist);
    }
    else if(direction == "down")
    {
      adjustAim(dist);
    }
    else if(direction == "forward")
    {
      move(dist);
    }
    else
    {
      return false;
    }
  }
  return true;
}

int MovementTrackerWithAim::getVert()
{
  return vert;
}

int MovementTrackerWithAim::getHorz()
{
  return horz;
}

int MovementTrackerWithAim::getAim()
{
  return aim;
}