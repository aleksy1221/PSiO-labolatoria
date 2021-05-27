#include <iostream>
#include <complex.h>

using namespace std;

int main()
{
    complex a(3,-2);
    complex b(5.0,9.0);
    complex c=a*b;
    std::cout<<(c)<<std::endl;
    return 0;
}
