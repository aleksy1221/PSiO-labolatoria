#include <iostream>
#include <vector>

void fill_progressive(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++) {
       vec[i]=i+1;
    }

}
void print_vector(const std::vector<int> &vec)
{
    for (const int &n : vec) {
        std::cout << n <<", ";
    }

}
int main()
{
    std::cout << "Podaj dlugosc wektora: ";
    int n;
    std::cin>>n;
    std::cout<<"Dlugosc to: "<<n<<std::endl;
    std::vector<int> vec(n);
    fill_progressive(vec);
    print_vector(vec);
    return 0;
}
