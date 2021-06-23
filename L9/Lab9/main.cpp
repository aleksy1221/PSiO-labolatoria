#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

using namespace std;

class AnimatedSprite : public sf::Sprite
{
private:
    int animation_fps_;
    std::vector<sf::IntRect> animation_frames_;
    sf::IntRect animation_stand;
    int current_frame_index_;
    float accumulated_time_=0;
    float y_acceleration_ = 9.81;
    int bborder = 0;

public:
    AnimatedSprite(int fps) : sf::Sprite()
    {
        animation_fps_ = fps;
        current_frame_index_ = 0;
    }
    void stand()
    {
        setTextureRect(animation_stand);
    }
    void add_animation_frame(const sf::IntRect &rect)
    {
        animation_frames_.emplace_back(rect);
    }
    void add_animation_stand(const sf::IntRect &rect)
    {
        animation_stand=rect;
    }
    void step(const sf::Time &elapsed_time)
    {
        accumulated_time_ += elapsed_time.asSeconds();

        if (accumulated_time_ >= 1.0/animation_fps_)
        {

            setTextureRect(animation_frames_[current_frame_index_]);
            if(current_frame_index_ >= static_cast<int>(animation_frames_.size()-1))
            {
                current_frame_index_ = 0;
            }
            else
            {
                current_frame_index_++;
            }
            accumulated_time_ = 0;
        }
    }
    void gravity()
    {
        sf::FloatRect rectangle_bounds = getGlobalBounds();

        if (!(rectangle_bounds.top + rectangle_bounds.height > bborder))
        {
            move(0,y_acceleration_); //1/2*y_acceleration*elapsed.asSeconds()*elapsed.asSeconds()
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "My window");

    sf::Clock clock;

    sf::Texture texture_wall;
    if(!texture_wall.loadFromFile("wall.png")) { return 1; }
    texture_wall.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(texture_wall);
    wall.setScale(0.3, 0.3);
    wall.setTextureRect(sf::IntRect(0, 0, 800/0.3, 600/0.3));

    int animation_fps = 7;
    sf::Texture texture_hero;
    if(!texture_hero.loadFromFile("hero.png")) { return 1; }
    AnimatedSprite hero(animation_fps);
    hero.setTexture(texture_hero);
    hero.setScale(3,3);

    /* add texture, set parameters, etc. */
    hero.add_animation_frame(sf::IntRect(200, 0, 37, 37)); // 1 frame of animation
    hero.add_animation_frame(sf::IntRect(250, 0, 37, 37)); // 2 frame
    hero.add_animation_frame(sf::IntRect(300, 0, 37, 37)); // 3 frame
    hero.add_animation_frame(sf::IntRect(350, 0, 37, 37)); // 4 frame
    hero.add_animation_frame(sf::IntRect(400, 0, 37, 37)); // 5 frame

    hero.add_animation_stand(sf::IntRect(0, 0, 37, 37));
    hero.stand();



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

        }
        sf::Time elapsed = clock.restart();


        // clear the window with black color
        window.clear(sf::Color::Black);

        //if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

            sf::FloatRect hero_bounds = hero.getGlobalBounds();
            if(hero_bounds.top>0){
                float dt=elapsed.asSeconds();
                hero.move(0,-1*100*abs(dt));
                hero.step(elapsed);
            }
        //}

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

            sf::FloatRect hero_bounds = hero.getGlobalBounds();
            if(hero_bounds.top>0){
                float dt=elapsed.asSeconds();
                hero.move(0,100*abs(dt));
                hero.step(elapsed);
            }
        }



hero.move(0,100*abs(dt));

        // draw everything here...

        window.draw(hero);


        // end the current frame
        window.display();
    }
    return 0;
}


