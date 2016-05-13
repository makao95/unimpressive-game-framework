#include "UGF/Text.h"
using namespace ugf;

Text::Text(std::string text):text(text), scale(1){

}

void Text::setFont(BitmapFont &font){
    this->font = &font;
    if (text.length()){
        vertexArray = std::move(font.getVertexArrayForText(text));
       setPosition(position);
       setColor(color);
    }
}

void Text::setText(std::string text){
    this->text = text;
    if (font == nullptr)
        return;
    vertexArray = font->getVertexArrayForText(text);
    setPosition(position);
}

void Text::setPosition(sf::Vector2f pos){
   position = pos;
   for (int i=0; i<vertexArray.getVertexCount(); i++){
       vertexArray[i].position += pos;
   }
}

void Text::setColor(sf::Color color){
    this->color = color;
    for (int i=0; i<vertexArray.getVertexCount(); i++)
        vertexArray[i].color = color;
}

void Text::setScale(float s){
    int x=0;
    for (int i=0; i<vertexArray.getVertexCount(); i+=4){
        int width = vertexArray[i+1].position.x - vertexArray[i].position.x;
        int height = vertexArray[i+2].position.y - vertexArray[i].position.y;
        vertexArray[i].position += sf::Vector2f(x, 0);
        vertexArray[i+1].position += sf::Vector2f(x+width*s, 0);
        vertexArray[i+2].position += sf::Vector2f(x+width*s, height*s);
        vertexArray[i+3].position += sf::Vector2f(x, height*s);

        x += vertexArray[1].position.x - vertexArray[0].position.x;
    }
}

//void Text::updateArray(){

//}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    states.texture = &font->getTexture();
    target.draw(vertexArray, states);
}

sf::Vector2f Text::getSize(){
    if (vertexArray.getVertexCount()>0)
        return vertexArray[0].position - vertexArray[vertexArray.getVertexCount()-1].position;
    else
        return sf::Vector2f(0, 0);
}
