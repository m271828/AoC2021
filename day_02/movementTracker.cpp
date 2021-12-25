#include <fstream>
#include <sstream>
#include "movementTracker.h"

bool MovementTracker::move(int vert, int horz)
{
  this->horz += horz;
  if(this->vert + vert < 0)
  {
    return false;
  }
  this->vert += vert;
  return true;
}

bool MovementTracker::seriesOfMoves(std::string fileName)
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
      move(-dist, 0);
    }
    else if(direction == "down")
    {
      move(dist, 0);
    }
    else if(direction == "forward")
    {
      move(0, dist);
    }
    else
    {
      return false;
    }
  }
}

int MovementTracker::getVert()
{
  return vert;
}

int MovementTracker::getHorz()
{
  return horz;
}