#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800,600), "My window");
    //window.setFramerateLimit(60);
    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(0.0, 0.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setFillColor(sf::Color(100, 50, 250));
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);
    float rectangle_velocity_x=50;
    float rectangle_velocity_y=150;
    float rectangle_angular_velocity=10;
    sf::Clock dt_clock;
    float dt;
    sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
    std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
    std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;
    // run the program as long as the window is open
    while (window.isOpen()) {
        dt=dt_clock.restart().asSeconds();
        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        std::cout<<1.0f/dt<<std::endl;
        if(rectangle_bounds.top+rectangle_bounds.height>600){
            rectangle_velocity_y*=-1;
            srand(time(NULL));
            rectangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if(rectangle_bounds.top<0){
            rectangle_velocity_y*=-1;
            srand(time(NULL));
            rectangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if(rectangle_bounds.left<0){
            rectangle_velocity_x*=-1;
            srand(time(NULL));
            rectangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if(rectangle_bounds.left+rectangle_bounds.width>800){
            rectangle_velocity_x*=-1;
            srand(time(NULL));
            rectangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        }
        rectangle.move(rectangle_velocity_x*dt,rectangle_velocity_y*dt);
        rectangle.rotate(rectangle_angular_velocity*dt);
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        // end the current frame
        window.display();
    }

    return 0;
}
