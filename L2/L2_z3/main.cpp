#include <iostream>

std::string longest(std::string s){
    std::string l;
    std::string p;
    size_t pos=0;
    size_t start=0;
    while((pos)!=std::string::npos){
        pos=s.find(' ',pos+1);
        p=s.substr(start,pos-start);
        if(p.size()>l.size()){
            l=p;
        }
        start=pos+1;
    }

    return l;
}
int main()
{
    std::string input="Ala ma kota jezdzi na Roombie";
    std::cout<<"Najdłuższy wyraz to: "<<longest(input)<<std::endl;
    return 0;
}
