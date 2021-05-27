#ifndef PRINT_H
#define PRINT_H
#include<vector>
#include <iostream>

template <typename  T>
void print(std::vector<std::pair<T, int>> w){
    for(auto [bin, frequency] : w){ // rzutowanie klucza i wartości elementu na zmienną word (klucz) i frequency (wartość)
          std::cout<< bin << " : " << frequency << std::endl;
    }

}


#endif // PRINT_H
