#include <iostream>
#include <cmath>

double pi_leibniz(double stop){
    double pi=0;
    double p=1;
    double x=1;
    while( std::abs(p)>stop){
        pi+=p;
        if(x>0)x+=2;
        else x-=2;
        x*=-1;
        p=1/x;
    }

    return pi*4;
}
int main()
{
    double stop_at = 0.00001;
    double pi_approx = pi_leibniz(stop_at);
    std::cout << pi_approx << std::endl;
    std::cout << "error: " << pi_approx - M_PI << std::endl;
    return 0;
}
