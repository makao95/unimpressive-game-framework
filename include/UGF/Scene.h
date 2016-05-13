#pragma once
#include <SFML/Graphics.hpp>
#include <UGF/ActorsSystem.h>

/***
    typedef std::chrono::milliseconds time;
    19ms;
    1s;
*/

namespace ugf {

//TODO: Global Actions/Events

class Scene : public sf::Drawable{
public:
    Scene();

    void update(sf::Time time, std::vector<sf::Event> events);
    void addActorsSystem(ActorsSystem& actorsSystem);

    void draw ( sf::RenderTarget &target, sf::RenderStates states);
};

}
