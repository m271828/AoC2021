#include <fstream>

class MovementTracker
{
private:
  int vert;
  int horz;

public:
  MovementTracker(): vert(0), horz(0) {}

  bool move(int vert, int horz);

  bool seriesOfMoves(std::string file);

  int getVert();
  int getHorz();
};