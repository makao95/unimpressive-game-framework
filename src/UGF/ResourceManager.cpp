#include "UGF/ResourceManager.h"
#include <iostream>
using namespace ugf;

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::ResourceManager(){}

ResourceManager& ResourceManager::getInstance(){
    if (instance == nullptr)
        instance = new ResourceManager();
    return *instance;
}

sf::Texture& ResourceManager::getTexture(std::string path){
    auto it = textures.find(path);
    if (it != textures.end())
        return *(it->second);
    else{
        sf::Texture* texture = new sf::Texture();
        if (texture->loadFromFile(path))
            textures[path] = texture;
        else
            std::cerr << "Texture loading error: " + path;
        return *texture;
    }
}
