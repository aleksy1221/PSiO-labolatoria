#include <iostream>
#include <vector>
#include <algorithm>

void sort(std::vector<double> &v){
    bool pom;
    do{
        pom=0;
        size_t rozmiar=v.size();
        for(size_t i=0;i<rozmiar-1;i++){
            if(v[i]>v[i+1]){
                std::swap(v[i],v[i+1]);
                pom=1;
            }
        }
        rozmiar--;
    }while(pom==1);

}
int main()
{
    std::vector<double> v={12,4,11,56,23,75,2,1,89,5,3,23,7};
    sort(v);

    for(size_t i=0;i<v.size();i++){
        std::cout<<v[i];
        if(i!=v.size()-1)
            std::cout<<", ";
    }
    std::cout<<std::endl;
    return 0;
}
