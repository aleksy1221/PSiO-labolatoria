#include <iostream>

int gcd(int a,int b){
    int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;

}
int main()
{
    int a,b;
    std::cout << "Podaj a: ";
    std::cin>>a;
    std::cout << "Podaj b: ";
    std::cin>>b;
    std::cout<<"Najwiekszy wspolny dzielnik to: "<<gcd(a,b)<<std::endl;

    return 0;
}
