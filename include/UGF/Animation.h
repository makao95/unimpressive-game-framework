#pragma once
#include <SFML/Graphics.hpp>


namespace ugf{

class Animation{
    Animation(std::string name);
    void addFrame(sf::Rect arena, sf::Time duration = 1);
    std::string getName();
};

class Animator{
    Animator();
    void addAnimation(Animation animation);
    void playAnimation(std::string name);
    void update(sf::Time time);
    // getSprite or sth like that
};

}
