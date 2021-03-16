#include <iostream>

std::string find_and_replace(std::string inp, std::string s1, std::string s2){
    std::string odp="";
    size_t pos=0;
    size_t start=0;
    while (pos!=std::string::npos) {
        pos=inp.find(s1,pos+1);
        odp=odp+inp.substr(start,pos)+s2;
        start=pos+s1.size();

    }

    return odp;
}

int main()
{
    std::string input="Ala ma kota, kot zjadł Ale!";
    std::string output=find_and_replace(input,"kot","hefalump");
    std::cout<<output<<std::endl;


    return 0;
}
