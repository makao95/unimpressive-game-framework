#pragma once
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
//#include "resource_manager.h"
//#include "UGF/ResourceManager.h"

namespace ugf{

class BitmapFont{
public:
    BitmapFont();
    void loadCharactersFromFile(std::string path);
    void setTexture(sf::Texture* texture, sf::IntRect rect);
    void setTexture(sf::Texture& texture);
    sf::Texture& getTexture();
    void addChar(std::string character, sf::IntRect rect);
    void setSpacing(int s);
    sf::VertexArray getVertexArrayForText(std::string text);
private:
    sf::Texture texture;
    sf::IntRect texturesRect;
    std::map<std::string, sf::IntRect> charactersMap;
};

}
