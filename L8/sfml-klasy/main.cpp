#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class CustomRectangleShape : public sf::RectangleShape{
protected:
    sf::Vector2f size_(float a, float b);
    sf::Vector2f position_(float x, float y);

public:
    CustomRectangleShape(sf::Vector2f size, sf::Vector2f position)
        :RectangleShape(size), position_(position){}
    sf::Vector2f positon() { return positon_; }


};
class Car : public Vehicle {
public:
    Car(const std::string &name, const std::string &propulsion_type,
        double max_speed, bool has_abs)
        : Vehicle(name, 4, propulsion_type, max_speed),
          has_abs_(has_abs) {}

    bool has_abs() { return has_abs_; }

private:
    bool has_abs_;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
