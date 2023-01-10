#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
class CPhysics{
    public: 
    float gravity = -9.8; 
    float moveSpeed = 2;
    float jumpRate = 10;
    void jump(sf::Vector2i v)
    {
        v.y += -9.8+jumpRate;
    }
    void move_right(sf::RectangleShape rect);
    void move_left(sf::RectangleShape rect);
    CPhysics() {};
};