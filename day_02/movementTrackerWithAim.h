#include <fstream>

class MovementTrackerWithAim
{
private:
  int vert;
  int horz;
  int aim;

public:
  MovementTrackerWithAim(): vert(0), horz(0), aim(0) {}

  bool move(int horz);
  bool adjustAim(int aim);

  bool seriesOfMoves(std::string file);

  int getVert();
  int getHorz();
  int getAim();
};