#pragma once
#include <vector>
#include <map>
#include "UGF/BitmapFont.h"

namespace ugf {
class ResourceManager {
public:
    static ResourceManager& getInstance();

    void setPrefix(std::string prefix);

    sf::Texture& getTexture(std::string path);
    sf::Image& getImage(std::string path);
    sf::Font getFont(std::string path);
    ugf::BitmapFont& getBitmapFont(std::string path);

    sf::Texture& createTexture(std::string path);
    sf::Texture& createImage(std::string path);
    sf::Font& createFont(std::string path);
    BitmapFont& createBitmapFont(std::string path);

private:
    ResourceManager();
    static ResourceManager* instance;
    std::string prefix;
    std::map<std::string, sf::Image*> images;
    std::map<std::string, sf::Texture*> textures;
    std::map<std::string, sf::Font*> fonts;
    std::map<std::string, BitmapFont> bitmapFonts;
};
}
