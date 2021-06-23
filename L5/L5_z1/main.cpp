#include <iostream>
#include <histogram.h>
#include <print.h>
#include <algorithm>
#include <vector>



int main()
{
    Histogram <std::string> slowa;
    Histogram <int> liczby;
    liczby.read_csv("wyniki.csv",',',5);
    std::vector<std::pair<int, int>> w;
    w=liczby.unique_items();
    std::cout<<liczby;
    print(w);
    return 0;
}
