#pragma once
#include <vector>
#include <map>
#include "UGF/Actor.h"

namespace ugf{

/***IDEAS:
 * - ActorsIterator
 */

//typedef uint ActorId;d
class Actor;
class ActorsSystem : sf::Drawable{
public:
    ActorsSystem();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void update(sf::Time time);
    // ActorsIterator getVisibleActors();
//    void drawVisibleActors();


//    Actor& addActor(const Actor& actor);
    ugf::Actor& createActor();
//    Actor& createQuadActor();
//    Actor& createStaticActor();
    Actor& createActor(b2Body* body);
    /*** Actors must be iterated fast, so they will be put into vector<> */
//    Actor& getActor(uint id);
    Actor& getActor(ActorId& id);
    void removeActor(ActorId& id);

private:
    sf::VertexArray va;
    std::vector<Actor> visibleActors;
    std::vector<Actor> actors;
    std::vector<uint> indexes;
    uint idCounter;
};

}
