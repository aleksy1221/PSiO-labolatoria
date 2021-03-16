#include <iostream>
bool is_prime(int i){
    if(i<2) return 0;
    for(int y=2;y*y<=i;y++){
        if(i%y==0)return 0;
    }
    return 1;

}
int main()
{
    int i = 4;
    if (is_prime(i)) {
        std::cout << i << " is prime!" << std::endl;
    } else {
        std::cout << i << " is not prime!" << std::endl;
    }
    return 0;
}
