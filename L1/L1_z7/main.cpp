#include <iostream>

void draw_square(int n, bool left_diagonal, bool right_diagonal){
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(x==0||y==0||x==n-1||y==n-1){
                std::cout<<"*";
            }
            else{
                if(left_diagonal&&x==y){
                    std::cout<<"*";
                }
                else{
                    if(right_diagonal&&y+x==n-1){
                        std::cout<<"*";
                    }
                    else{
                        std::cout<<" ";
                    }
                }

            }

        }
        std::cout<<std::endl;
    }

}

int main()
{
    bool lewa, prawa;
    int n;
    char pom;
    std::cout << "Podaj dlugosc boku: ";
    std::cin>>n;
    draw_square(n,true,false);
    return 0;
}
