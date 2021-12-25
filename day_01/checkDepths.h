#include <list>
#include <string>

class CheckDepths
{
private:
  std::list<int> readings;
  int sumWindow(std::list<int>::iterator i, size_t window);
public:
  enum class Result {
    SUCCESS,
    FAILURE
  };

  Result readDepths(std::string file);

  size_t countDeeper();
  size_t countDeeperSlidingWindow(size_t window);
};