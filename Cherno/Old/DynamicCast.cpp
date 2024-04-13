#include "ConditionalBP.h"
#include <iostream>

class Entity {
public:
	virtual void PrintName() {}
};

class Player : public Entity {};
class PlayerSon : public Player {};
class Enemy : public Entity {};

int main() {
	Player* player = new Player();
	Entity* actuallyEnemy = new Player();
		
	Entity* actuallyPlayer = player;

	Player* p0 = dynamic_cast<Player*>(actuallyEnemy);
	Player* p1 = dynamic_cast<Player*>(actuallyPlayer);

	Entity* actuallyEntity = new Entity();
	PlayerSon* p2 = dynamic_cast<PlayerSon*>(actuallyEntity);
	return 0;
}
