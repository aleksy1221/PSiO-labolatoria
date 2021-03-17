#include <iostream>
#include <vector>
int binary_search(const std::vector<double> &v, double sz){
    size_t l=0, r=v.size()-1;
    double m;
    while(l<=r){
        m=(l+r)/2;
        if(v[m]==sz){
            return m;
        }
        if(v[m]>sz){
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return -1;
}


int main()
{
    int odp;
    std::vector<double> w={1,2,4,6,7,11,15,19,32,44,61,69,70,99,142};
    odp=binary_search(w,16);
    std::cout<<"Szukana wartość ma indeks: "<<odp<<std::endl;
    return 0;
}
