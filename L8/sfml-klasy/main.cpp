#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace std;

class CustomRectangleShape : public sf::RectangleShape{
private:
    sf::Vector2f size_;
    sf::Vector2f position_;
    float speedX=0;
    float speedY=0;
    float speedZ=0;
    bool is_selected=false;
    //boundary
    int left;
    int right;
    int top;
    int bottom;
    void bounce(){
        sf::FloatRect rectangle_bounds = this->getGlobalBounds();
        if(rectangle_bounds.left < left)
        {
            speedX = std::abs(speedX);
        }
        else if(rectangle_bounds.left + rectangle_bounds.width > right)
        {
            speedX = - std::abs(speedX);
        }
        else if(rectangle_bounds.top < top)
        {
            speedY =   std::abs(speedY);
        }
        else if(rectangle_bounds.top + rectangle_bounds.height > bottom)
        {
            speedY = - std::abs(speedY);
        }
    }

public:
    CustomRectangleShape(sf::Vector2f size, sf::Vector2f position)
        :sf::RectangleShape(size), position_(position){
        setPosition(position);
    }

    sf::Vector2f positon() { return position_; }

    void setSpeed(float x=0,float y=0,float z=0){
        speedX=x;
        speedY=y;
        speedZ=z;
    }

    void animate(const sf::Time &elapsed){
        if(is_selected==false){
            float dt=elapsed.asSeconds();
            move(speedX*abs(dt),speedY*abs(dt));
            rotate(speedZ*abs(dt));
            bounce();
        }
    }
    void setBounds(int l, int r, int t, int b){
        left=l;
        right=r;
        top=t;
        bottom=b;
    }
    void setBounds(sf::IntRect bounds){
        left=bounds.left;
        right=bounds.width;
        top=bounds.top;
        bottom=bounds.height;
    }
    void select(){
        is_selected=true;

    }
    void unselect(){
        is_selected=false;

    }
    bool if_selected(){return is_selected;}

};

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800,600), "My window");
    std::vector<CustomRectangleShape> rectangles;
    for (int i=0; i<10; i++) {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }

    for (auto &rec : rectangles) {
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(100+std::rand()%60, 200+std::rand()%60, 10+std::rand()%20);
    }
    //    //my_rectangle1
    //    sf::Vector2f size(120.0, 60.0);
    //    sf::Vector2f position(120.0, 60.0);
    //    CustomRectangleShape my_rectangle1(size, position);
    //    my_rectangle1.setSpeed(100, 150, 10);
    //    my_rectangle1.setBounds(0, window.getSize().x, 0, window.getSize().y);
    //    my_rectangle1.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    //    //my_rectangle2
    //    position.x=74;
    //    position.y=154;
    //    CustomRectangleShape my_rectangle2(size, position);
    //    my_rectangle2.setSpeed(200, 400, 30);
    //    my_rectangle2.setBounds(0, window.getSize().x, 0, window.getSize().y);
    //    my_rectangle2.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    //    //my_rectangle3
    //    position.x=706;
    //    position.y=500;
    //    CustomRectangleShape my_rectangle3(size, position);
    //    my_rectangle3.setSpeed(100, 200, 60);
    //    my_rectangle3.setBounds(0, window.getSize().x, 0, window.getSize().y);
    //    my_rectangle3.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    //    //my_rectangle4
    //    position.x=74;
    //    position.y=154;
    //    CustomRectangleShape my_rectangle4(size, position);
    //    my_rectangle4.setSpeed(200, 400, 30);
    //    my_rectangle4.setBounds(0, window.getSize().x, 0, window.getSize().y);
    //    my_rectangle4.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    std::cout << "Mouse clicked: " << mouse_position.x << ", " << mouse_position.y << std::endl;
                    for (auto &rec : rectangles) {
                        if(rec.getGlobalBounds().contains(mouse_position.x,mouse_position.y)){
                            rec.select();
                            rec.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Right) {
                    sf::Vector2f mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    std::cout << "Mouse clicked: " << mouse_position.x << ", " << mouse_position.y << std::endl;
                    for (auto &rec : rectangles) {
                        if(rec.getGlobalBounds().contains(mouse_position.x,mouse_position.y)){
                            rec.unselect();
                            rec.setFillColor(sf::Color(254, 254, 254));
                        }
                    }

                }
            }

        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        sf::Time elapsed = clock.restart();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            for (auto &rec : rectangles) {
                if(rec.if_selected()){
                    sf::FloatRect rectangle_bounds = rec.getGlobalBounds();
                    if(rectangle_bounds.top>0){
                        float dt=elapsed.asSeconds();
                        rec.move(0,-1*100*abs(dt));
                    }

                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            for (auto &rec : rectangles) {
                if(rec.if_selected()){
                    sf::FloatRect rectangle_bounds = rec.getGlobalBounds();
                    if(rectangle_bounds.top+rectangle_bounds.height<window.getSize().y){
                        float dt=elapsed.asSeconds();
                        rec.move(0,100*abs(dt));
                    }

                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            for (auto &rec : rectangles) {
                if(rec.if_selected()){
                    sf::FloatRect rectangle_bounds = rec.getGlobalBounds();
                    if(rectangle_bounds.left>0){
                        float dt=elapsed.asSeconds();
                        rec.move(-1*100*abs(dt),0);
                    }

                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            for (auto &rec : rectangles) {
                if(rec.if_selected()){
                    sf::FloatRect rectangle_bounds = rec.getGlobalBounds();
                    if(rectangle_bounds.left+rectangle_bounds.width<window.getSize().x){
                        float dt=elapsed.asSeconds();
                        rec.move(100*abs(dt),0);
                    }

                }
            }
        }



        for (auto &rec : rectangles) {
            rec.animate(elapsed);
        }

        //        my_rectangle1.animate(elapsed);
        //        my_rectangle2.animate(elapsed);
        //        my_rectangle3.animate(elapsed);

        // draw everything here...
        for (auto &rec : rectangles) {
            window.draw(rec);
        }
        //        window.draw(my_rectangle1);
        //        window.draw(my_rectangle2);
        //        window.draw(my_rectangle3);

        // end the current frame
        window.display();
    }
    return 0;
}
