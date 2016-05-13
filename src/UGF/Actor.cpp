#include "UGF/Actor.h"
#include <iostream>

//ugf::Actor::Actor(ActorsSystem &actorsSystem, ActorId actorId):actorsSystem(actorsSystem), actorId(actorId){

//}
ugf::Actor::Actor(){

}

void ugf::Actor::update(){
    position = sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
}

//void ugf::Actor::draw(sf::RenderTarget &target, sf::RenderStates states) const{
//    std::cout << "draw actor"<<std::endl;
//}
