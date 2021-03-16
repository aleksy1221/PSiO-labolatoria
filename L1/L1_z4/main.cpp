#include <iostream>

uint64_t factorial_r(int n){
    if(n<2) return 1;
    return n*factorial_r(n-1);
}

int main()
{
    uint64_t result = factorial_r(15);
    std::cout << result << std::endl;
}
