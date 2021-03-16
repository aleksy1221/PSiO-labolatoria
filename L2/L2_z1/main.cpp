#include <iostream>

bool is_palindrome(std::string a){

    int r=a.size();
    for(int i=0;i<r;i++){
        if(a[i]!=a[r-1-i]){
            return false;
        }
    }
    return true;

}
int main()
{
    std::string s;
    std::cout << "Podaj słowo: ";
    std::cin>>s;
    if(is_palindrome(s)){
        std::cout<<"Słowo jest palindromem."<<std::endl;
    }
    else{
        std::cout<<"Słowo nie jest palindromem."<<std::endl;
    }

    return 0;
}
