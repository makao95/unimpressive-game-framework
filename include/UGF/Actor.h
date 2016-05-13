#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "UGF/Taggable.h"
#include <sys/types.h>
//#include "UGF/ActorsSystem.h"

namespace ugf{

class ActorId{
public:
    unsigned int id;
    unsigned int index; //actual index of an Actor in ActorsSystem's vector
};


class ActorsSystem;
class Controller;

class Actor : public ugf::Taggable, public sf::Drawable{
//    friend ActorsSystem;
public:
    Actor();

//    void setBody(b2Body* body);
//    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void update();
    unsigned int inline getId();

    b2Body* body;
    sf::Vector2f position;
    Controller* controller;
    ActorId id;
    std::vector<sf::Vertex> verticles;
    sf::PrimitiveType primitiveType;
    sf::Texture* texture;
    bool vertexArrayUpdated;
//    sf::VertexArray vertexArray;
private:
    Actor(ActorsSystem& actorsSystem, ActorId actorId);
//    ActorsSystem& actorsSystem;
};

}
