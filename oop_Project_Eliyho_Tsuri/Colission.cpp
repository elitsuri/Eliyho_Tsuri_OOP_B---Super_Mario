#include "Colission.h"

typedef void(*HitFunctionPtr)(GameObject&, GameObject&);
typedef map<pair<string, string>, HitFunctionPtr> HitMap;
namespace
{
	void MarioOnCoin(GameObject& mario, GameObject& coin)
	{
		Mario& mario1 = static_cast<Mario&>(mario);
		Goomba& coin1 = static_cast<Goomba&>(coin);
		
	}
	void MarioOnGoomba(GameObject& mario, GameObject& goomba)
	{
		Mario& mario1 = static_cast<Mario&>(mario);
		Goomba& goomba1 = static_cast<Goomba&>(goomba);
	}
	void MarioOnTurtle(GameObject& mario, GameObject& turtle)
	{
		Mario& mario1 = static_cast<Mario&>(mario);
		Turtle& turtle1 = static_cast<Turtle&>(turtle);
	}
	void MarioOnWall(GameObject& mario, GameObject& wall)
	{
		Mario& mario1 = static_cast<Mario&>(mario);
		Wall& wall1 = static_cast<Wall&>(wall);
	}
	void MarioOnBrick(GameObject& mario, GameObject& brick)
	{
		Mario& mario1 = static_cast<Mario&>(mario);
		Brick& brick1 = static_cast<Brick&>(brick);
	}
	
	void MarioOnBox(GameObject& mario, GameObject& box)
	{
		Mario& mario1 = static_cast<Mario&>(mario);
		Box& box1 = static_cast<Box&>(box);
	}
	void MarioOnPipe(GameObject& mario, GameObject& pipe)
	{
		Mario& mario1 = static_cast<Mario&>(mario);
		Pipe& pipe1 = static_cast<Pipe&>(pipe);
	}
	void MarioOnCastle(GameObject& mario, GameObject& castle)
	{
		Mario& mario1 = static_cast<Mario&>(mario);
		Castle& castle1 = static_cast<Castle&>(castle);
	}
	unique_ptr<HitMap> initializeCollisionMap()
	{
		auto phm = std::make_unique<HitMap>();
		(*phm)[make_pair(typeid(Mario).name(), typeid(Coin).name())] = &MarioOnCoin;
		(*phm)[make_pair(typeid(Mario).name(), typeid(Goomba).name())] = &MarioOnGoomba;
		(*phm)[make_pair(typeid(Mario).name(), typeid(Turtle).name())] = &MarioOnTurtle;
		(*phm)[make_pair(typeid(Mario).name(), typeid(Wall).name())] = &MarioOnWall;
		(*phm)[make_pair(typeid(Mario).name(), typeid(Brick).name())] = &MarioOnBrick;
		(*phm)[make_pair(typeid(Mario).name(), typeid(Box).name())] = &MarioOnBox;
		(*phm)[make_pair(typeid(Mario).name(), typeid(Pipe).name())] = &MarioOnPipe;
		(*phm)[make_pair(typeid(Mario).name(), typeid(Castle).name())] = &MarioOnCastle;
		return phm;
	}
	HitFunctionPtr lookup(const string& class1, const string& class2)
	{
		static unique_ptr<HitMap>
			collisionMap(initializeCollisionMap());
		auto mapEntry =
			collisionMap->find(make_pair(class1, class2));
		if (mapEntry == collisionMap->end())
			return nullptr;
		return (*mapEntry).second;
	}
}

void Colission::processCollision(GameObject& object1, GameObject& object2)
{
	HitFunctionPtr phf = lookup(typeid(object1).name(), typeid(object2).name());
	if (phf)
		phf(object1, object2);
}