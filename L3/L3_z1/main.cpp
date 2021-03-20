#include <iostream>
#include <random>
#include <ctime>
#include <vector>

int randomInt(int min, int max) {
  static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
  std::uniform_int_distribution<int> d{min, max};
  return d(e);
}

int main()
{
    int n;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin>>n;
    std::vector <int> tab;
    return 0;
}
