#pragma once
#include "UGF/BitmapFont.h"
#include "SFML/Graphics.hpp"

namespace ugf{
class Text : public sf::Drawable{
public:
    Text(std::string text = "");
    void setFont(BitmapFont& font);
    void setText(std::string text);
    void setPosition(sf::Vector2f pos);
    void setColor(sf::Color color);
    void setScale(float s);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::Vector2f getSize();
private:
    std::string text;
    BitmapFont* font;
    sf::Color color;
    sf::Vector2f position;
    sf::VertexArray vertexArray;
    float scale;
};
}
