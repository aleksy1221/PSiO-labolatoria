#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>


int main()
{
    std::fstream file;
    file.open("1.html",std::ios::in);
    std::string text1;
    if(file.is_open()){
        std::stringstream str_stream;
        str_stream <<file.rdbuf();
        text1 = str_stream.str();
    }
    else
    {
        std::cout<<"nie udalo sie otworzyc pliku 1 :(";
    }
    file.close();

    file.open("2.html",std::ios::in);
    std::string text2;
    if(file.is_open()){
        std::stringstream str_stream;
        str_stream <<file.rdbuf();
        text2 = str_stream.str();
    }
    else
    {
        std::cout<<"nie udalo sie otworzyc pliku 2 :(";
    }
    file.close();

    file.open("3.html",std::ios::in);
    std::string text3;
    if(file.is_open()){
        std::stringstream str_stream;
        str_stream <<file.rdbuf();
        text3 = str_stream.str();
    }
    else
    {
        std::cout<<"nie udalo sie otworzyc pliku 3 :(";
    }
    file.close();

    file.open("4.html",std::ios::in);
    std::string text4;
    if(file.is_open()){
        std::stringstream str_stream;
        str_stream <<file.rdbuf();
        text4 = str_stream.str();
    }
    else
    {
        std::cout<<"nie udalo sie otworzyc pliku 4 :(";
    }
    file.close();
    std::vector<std::string> podzial;
    std::regex strona(R"(www\.(\w)+\.\w+\.\w+(\/\w+-?(\w+)?-?-?(\w+)?-?-?(\w+)?-?)(\/\w+-?(\w+)?-?-?(\w+)?-?)?)");
    std::regex numer(R"((\+48 |0048|\+48)?\(?\d\d(\s|-)?\d(\s|\)\s|-)?\d(\s|-)?\d(\s|-)?\d(\s|-)?\d(\s|-)?\d\d)");
    std::smatch sm;
    std::smatch m;
    while (regex_search(text1, sm, strona)) {
        std::string pom=sm.prefix().str()+sm[0].str();
        text1=sm.suffix();
        regex_search(text1, sm, strona);
        podzial.emplace_back(pom+sm.prefix().str());
    }
    std::map<std::string, std::vector<std::string>> mapa;

    for(size_t i=0;i<podzial.size();i++){

        regex_search(podzial[i], sm, strona);
        std::cout<<i<<": "<<sm[0]<<": ";
        while (regex_search(podzial[i], m, numer)) {
                    podzial[i] = sm.suffix();
                    std::cout<<m[0]<<", ";
                    mapa[sm[0]].emplace_back(m[0]);
                }

//        std::cout<<podzial[i]<<std::endl;
//        std::cout<<"-------------------------------------------------------------------"<<std::endl;
    }
//    for(size_t i=0;i<podzial.size();i++){
//        std::string n;
//        regex_search(podzial[i], sm, strona);
//        std::cout<<sm[0]<<": ";
//        while (regex_search(podzial[i], m, numer)) {
//            podzial[i] = sm.prefix().str()+sm.suffix().str();
//            n=m[0];
//            std::cout<<m[0]<<", ";
//            mapa[sm[0]].emplace_back(n);
//        }
//    }
    return 0;
}
