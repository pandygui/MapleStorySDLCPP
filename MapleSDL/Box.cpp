#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
#include "GameDebug.hpp"
#include "Global.h"

using namespace std;

#include "Input.hpp"
#include "MessageDispatch.hpp"
#include "GameUtils.hpp"
#include "RelativeSpace.hpp"
#include "AnimatedSprite.hpp"
#include "GameObject.h"
#include "ItemDrop.hpp"
#include "Entity.hpp"
#include "Box.hpp"



void Box::Init(b2World* world, const b2Vec2 & pos, const b2Vec2 & dim) {
	b2BodyDef bodyDef;
	this->dimensions = dim;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(pos.x, pos.y);

	body = world->CreateBody(&bodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(10, 10);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.0f;
	this->fixture = body->CreateFixture(&fixtureDef);

}