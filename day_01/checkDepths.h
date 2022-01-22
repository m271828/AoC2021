#include <list>
#include <string>

class CheckDepths
{
private:
  std::list<int> readings;
  int sumWindow(std::list<int>::iterator i, std::size_t window);

public:
  enum class Result {
    SUCCESS,
    FAILURE
  };

  Result readDepths(std::string file);

  std::size_t countDeeper();
  std::size_t countDeeperSlidingWindow(std::size_t window);
};
