#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include <algorithm>


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
    std::list <int> tab;
    for(int i=0;i<n;i++){
        tab.push_back(randomInt(-20,20));
    }
    for(auto it=tab.begin();it!=tab.end();it++){
        std::cout<<*it<<",  ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout << "Podaj szukana: ";
    int x;
    std::cin>>x;
    tab.remove(x);
    //auto sz= std::find(tab.begin(),tab.end(),x);
   // tab.erase(sz);

    for(auto it=tab.begin();it!=tab.end();it++){
        std::cout<<*it<<",  ";
    }
    auto min= std::min_element(tab.begin(),tab.end());
    auto max= std::max_element(tab.begin(),tab.end());
    std::cout<<"Wartosc max:"<<*max<<std::endl;
    std::cout<<"Wartosc min:"<<*min<<std::endl;
    return 0;
}
