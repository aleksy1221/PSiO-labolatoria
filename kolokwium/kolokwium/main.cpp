#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

struct Product {
    std::string name;
    double mass; //masa towaru na magazynie w kg
    double price; //cena jednostkowa w PLN
};

int main() {
    std::vector<Product> products = {{"nuts", 2, 20},
        {"potatoes", 100, 3},
        {"butter", 50, 0},
        {"a", 50, 3}};

    auto above_threshold=[](const Product &products){
            return (products.name.size()>=2&&products.mass>=2&&products.price>3);

        };

    if (std::all_of(products.begin(), products.end(), above_threshold)) {
        std::cout << "All products are OK" << std::endl;
    }
    return 0;
}
