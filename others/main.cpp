#include "shalhz.h"
#include "entity.h"

int main()
{
	Entity e; // created in the stack
			  
	Entity* player = new Entity(5, -5); // created in the heap -> not deleted after reaching end curly bracket. Need to be manually deleted

	std::cout << e.getX() << " " << e.getY() << std::endl;

	std::cout << player->getX() << " " << player->getY() << std::endl;

	delete player;

	std::cout << Entity::a << std::endl;

	return 0;
}
