#include <iostream>
#include <vector>

std::vector<size_t> find_all(std::string a, char z){
    std::vector<size_t> v;
    v.clear();
    size_t pos=0;
    while((pos= a.find(z,pos+1))!=std::string::npos){
        v.push_back(pos);
    }
    return v;
}

int main()
{
    std::string a="Ala ma kota";
    std::vector<size_t> pos=find_all(a,'a');
    for(size_t i=0;i<pos.size();i++){
        std::cout<<pos[i]<<", ";
    }

    return 0;
}
