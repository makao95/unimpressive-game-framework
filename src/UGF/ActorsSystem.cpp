#include "UGF/ActorsSystem.h"
using ugf::ActorsSystem;

ActorsSystem::ActorsSystem():idCounter(0){

}

void ActorsSystem::removeActor(ugf::ActorId& id){
/*    actors.erase(actors.begin()+indexes.at(id));
    for(auto it = indexes.begin()+id; it < indexes.end(); it++){
        (*it)--; //decrease every index after deleted item
    }
    */
}

ugf::Actor& ActorsSystem::getActor(ugf::ActorId& id){
/*    if(actors.at(id.index).id == id.id)
        return actors.at(id.number);
    else{
        if (actors.at(indexes.at(id.id)).id == id.id){
            id.index = indexes.at(id.id);
            return actors.at(id.index);
        }
    }*/
}

ugf::Actor& ActorsSystem::createActor(){
 //   actors.push_back(new ugf::Actor(this, ActorId(++id_counter)));
    indexes.push_back(idCounter);
    return actors.at(actors.size());
}

void ActorsSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    for (ugf::Actor actor : actors)
        target.draw(actor);
        //target.draw(actor.vertexArray);
}
