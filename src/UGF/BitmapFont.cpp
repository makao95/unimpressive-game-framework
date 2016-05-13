#include "UGF/BitmapFont.h"
#include <fstream>
#include <iostream>
#include <sstream>

ugf::BitmapFont::BitmapFont() {

}

void ugf::BitmapFont::loadCharactersFromFile(std::string path) {
	std::fstream file;
	file.open(path);
    if (!file.is_open()) {
		std::cout << "Font file opening error"<<std::endl;
        return;
	}
	std::string line;
    int top = 0;
	int left = 0;
    int width = 0;
    int height = 0;
	while (std::getline(file, line)) {
        if (line.at(0) == '#'){
            std::stringstream s(line);
            std::string tmp;
            int tmpI;
            s >> tmp;
            s >> tmp;
            if (tmp == "top"){
                s >> tmpI;
                top = tmpI;
            }else if (tmp == "left"){
                s >> tmpI;
                left = tmpI;
            }else if (tmp == "width"){
                s >> tmpI;
                width = tmpI;
            }else if (tmp == "height"){
                s >> tmpI;
                height = tmpI;
            }
        }else{
            std::stringstream ss(line);
            std::string c;
            while (ss >> c){
                addChar(c, sf::IntRect(left, top, width, height));
                left += width;
            }
        }

	}
}

void ugf::BitmapFont::addChar(std::string character, sf::IntRect rect) {
	std::cout << "Char: " << character << " rect: " << rect.left << " " << rect.top << " " << rect.width << " " << rect.height << std::endl;
	charactersMap[character] = rect;
}

sf::VertexArray ugf::BitmapFont::getVertexArrayForText(std::string text) {
    //Process UTF-8 string by character
    std::vector<std::string> characters;
	for(auto it = text.begin(); it != text.end(); it++) {
        unsigned char c;
        c = *it;
        std::string character;
        character.push_back(c);
        if (c > 0xC0) { //2 bytes utf-8 character
            it++;
            c = (*it);
            character.push_back(c);
        }
        characters.push_back(character);
	}

    sf::VertexArray vertexArray(sf::Quads);
    sf::Vector2f lastPos = sf::Vector2f(0,0);
      for(std::string character : characters){
        sf::Vertex v1, v2, v3, v4;
        sf::IntRect texRect = charactersMap[character];
        v1.texCoords = sf::Vector2f(texRect.left, texRect.top);
        v2.texCoords = sf::Vector2f(texRect.left+texRect.width, texRect.top);
        v3.texCoords = sf::Vector2f(texRect.left+texRect.width, texRect.top+texRect.height);
        v4.texCoords = sf::Vector2f(texRect.left, texRect.top+texRect.height);
        v1.position = lastPos;
        v2.position = lastPos + sf::Vector2f(texRect.width, 0);
        v3.position = lastPos + sf::Vector2f(texRect.width, texRect.height);
        v4.position = lastPos + sf::Vector2f(0, texRect.height);
        lastPos += sf::Vector2f(10, 0);
        vertexArray.append(v1);
        vertexArray.append(v2);
        vertexArray.append(v3);
        vertexArray.append(v4);
    }
      return vertexArray;
}

void ugf::BitmapFont::setTexture(sf::Texture &texture){
    this->texture = texture;
}

sf::Texture& ugf::BitmapFont::getTexture(){
    return texture;
}
