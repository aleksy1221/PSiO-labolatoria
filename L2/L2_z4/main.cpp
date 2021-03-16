#include <iostream>
#include <vector>

std::vector<std::string> split(std::string s, char z=' '){
    size_t pos=0;
    size_t start=0;
    std::vector<std::string> odp;
    while (pos!=std::string::npos) {
        pos=s.find(z,pos+1);
                odp.push_back(s.substr(start,pos-start));
        start=pos+1;
    }

    return odp;
}
int main()
{
    std::string sentence= "Ala,ma,kota";
    std::vector<std::string> words = split(sentence,',');
    for(size_t i=0;i<words.size();i++){
       std::cout<<words[i]<<std::endl;
    }
    return 0;
}
