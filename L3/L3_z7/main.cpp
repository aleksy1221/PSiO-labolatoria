#include <iostream>
#include <vector>
enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};
using Koszyk = std::vector<Roslina>;

int main()
{
    Koszyk koszyk;
    std::ostream& operator<<(std::ostream &out, const Roslina &roslina) { }
    std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk) { }
    return 0;
}
