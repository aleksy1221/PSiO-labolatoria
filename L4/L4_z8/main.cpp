#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <set>

int main()
{
    std::fstream input_file("numery.html", std::ios::in);
    std::string full_text;
    if(input_file.is_open()){
        std::stringstream str_stream;
        str_stream << input_file.rdbuf();
        full_text = str_stream.str();
    }
    else{
        std::cout<<"\nBlad wczytania pliku!!!!"<<std::endl;
    }
    std::regex re(R"((\+48 |0048|\+48)?\(?\d\d(\s|-)?\d(\s|\)\s|-)?\d(\s|-)?\d(\s|-)?\d(\s|-)?\d(\s|-)?\d\d)");
    std::smatch sm;
    std::set <std::string> numery;
    while (regex_search(full_text, sm, re)) {
        numery.insert(sm[0]);
        full_text = sm.suffix();
    }
    std::cout<<"Znalezione numery:"<<std::endl;
    for(const std::string &n: numery){
        std::cout<<n<<std::endl;
    }
    return 0;
}
