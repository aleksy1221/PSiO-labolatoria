#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class CustomRectangleShape : public sf::RectangleShape{
public:
    CustomRectangleShape(const sf::Vector2 <double> &size, const sf::Vector2 <double> &position);


protected:
    sf::Vector2f size_(double a, double b);
    sf::Vector2f position_(double x, double y);

};
class Vehicle {
protected:
    Vehicle(const std::string &name, double max_speed)
        : name_(name), max_speed_(max_speed) {}

    std::string name_;
    int number_of_wheels_;
    std::string propulsion_type_;
    double max_speed_;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
