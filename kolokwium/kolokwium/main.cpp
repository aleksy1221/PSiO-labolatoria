#include <vector>
#include <iostream>
#include <memory>
#include <cmath>

const float PI = 3.1415f;

class Figura
{
    std::string nazwa_;
    float pole=pole_powierzchni();
public:
    Figura(const std::string& nazwa) : nazwa_(nazwa) {
    }

    virtual float pole_powierzchni()=0;

    std::string nazwa() {
        return nazwa_;
    }
};

class Prostokat : public Figura
{
    float x;
    float y;
public:
    float polepowierzchni(){
        return x*y;
    }
};

class Kolo : public Figura
{
public:
    float r;
public:
    float polepowierzchni(){
        return PI*pow(r,2);
    }
};

std::vector<std::unique_ptr<Figura>> utworz_figury() {
    std::vector<std::unique_ptr<Figura>> figury;
    // ...
    return figury;

}

void drukuj(const std::vector<std::unique_ptr<Figura>>& figury) {
    for (const auto& figura : figury)
    {
        std::cout << figura->nazwa() << ": " << figura->pole_powierzchni() << '\n';
    }

}

int main() {

    std::vector<std::unique_ptr<Figura>> figury = utworz_figury();
    drukuj(figury);
    Kolo c;


    return 0;

}
