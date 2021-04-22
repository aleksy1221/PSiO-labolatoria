#include <iostream>
#include <map>
#include <fstream>
#include <regex>
#include <vector>
#include <cctype>
#include <algorithm>

std::string tolower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c);
    });
    return s;
}

int main()
{
    std::fstream wej("license.txt",std::ios::in);
    std::fstream wyj("wyniki.txt",std::ios::out);
    std::map<std::string,int> words;
    std::regex re(R"((\w)+)");
    std::smatch m;
    if(wej.is_open()){
        while(!wej.eof()){
            std::string word;
            wej>>word;
            word=tolower(word);
            if(std::regex_match(word, m, re)){
                auto search = words.find(word);
                if (search != words.end()) {
                    int pom=words[word];
                    pom++;
                    words[word]=pom;
                } else {
                    words.emplace(word,1);
                }
            }
        }
    }
    else{
        std::cout<<"BLAD WCZYTANIA PLIKU!"<<std::endl;
    }
    //    for(auto &[word, frequency] : words){
    //        std::cout<< word << " - " << frequency << std::endl;
    //    }
    std::vector<std::pair<std::string,int>> w;
    std::copy(words.begin(), words.end(),
              std::back_inserter(w));

    std::sort(w.begin(),w.end(),[](auto &left, auto &right) {
        return left.second > right.second;});

    for(auto &[word, frequency] : w){
        std::cout<< word << " - " << frequency << std::endl;
        wyj<<word << " - " << frequency << std::endl;
    }
    return 0;
}
