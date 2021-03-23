#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>


int randomInt(int min, int max) {
    static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
    std::uniform_int_distribution<int> d{min, max};
    return d(e);
}

int main()
{
    int n;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin>>n;
    std::vector <int> tab;
    for(int i=0;i<n;i++){
        tab.push_back(randomInt(-20,20));
        std::cout<<tab[i]<<",  ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout << "Podaj szukana: ";
    int x;
    std::cin>>x;

    auto tt = std::find(tab.begin(),tab.end(),x);
    tab.erase(tt);

    for(auto it=tab.begin();it!=tab.end();it++){
        std::cout<<*it<<",  ";
    }
    auto min= std::min_element(tab.begin(),tab.end());
    auto max= std::max_element(tab.begin(),tab.end());
    std::cout<<std::endl;
    std::cout<<"Wartosc max:"<<*max<<std::endl;
    std::cout<<"Wartosc min:"<<*min<<std::endl;


    // sortowanie z5
        //malejąco
    std::sort(tab.begin(),tab.end(),[](float x, float y){
        return x>y;
    });
    for(auto it=tab.begin();it!=tab.end();it++){
        std::cout<<*it<<",  ";
    }
    std::cout<<std::endl;
        //rosnącą
    std::sort(tab.begin(),tab.end(),[](float x, float y){
        return x<y;
    });
    for(auto it=tab.begin();it!=tab.end();it++){
        std::cout<<*it<<",  ";
    }
    std::cout<<std::endl;
        //wartosc bezwględna max
    std::sort(tab.begin(),tab.end(),[](float x, float y){
        return std::abs(x)>std::abs(y);
    });
    for(auto it=tab.begin();it!=tab.end();it++){
        std::cout<<*it<<",  ";
    }
    std::cout<<std::endl;
    return 0;
}
