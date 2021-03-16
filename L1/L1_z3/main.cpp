#include <iostream>

using namespace std;
uint64_t factorial(int n){
uint64_t f=1;
for(int i=1;i<=n;i++){
    f*=i;
}

return f;
}

int main()
{

    uint64_t result = factorial(15);
    std::cout << result << std::endl;
    return 0;
}
