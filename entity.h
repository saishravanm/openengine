#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "ctransform.h"
#include "cname.h"
#include "cshape.h"
#include "csprite.h"
class Entity{
  
  public: 
  std::shared_ptr<CTransform> cTransform;
  std::shared_ptr<CName> cName;
  std::shared_ptr<CShape> cShape;
  std::shared_ptr<CSprite> cSprite;
  Entity() {};
};

class Player : public Entity {
  public:
  std::shared_ptr<CTransform> cTransform; 
  std::shared_ptr<CName> cName; 
  std::shared_ptr<CShape> cShape; 

};