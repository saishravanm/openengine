#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
class CSprite {
    public:
    std::string textureFile; 
    sf::Sprite sprite; 
    sf::Texture text();
    CSprite(std::string tf, sf::Sprite s) : textureFile(tf),sprite(s){text().loadFromFile(textureFile);}; 
};