#include <list>
#include <string>

class CheckDepths
{
private:
  std::list<int> readings;
public:
  enum class Result {
    SUCCESS,
    FAILURE
  };

  Result readDepths(std::string file);

  size_t countDeeper();
};