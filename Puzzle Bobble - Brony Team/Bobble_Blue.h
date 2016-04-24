#ifndef __BOBBLE_H__
#define __BOBBLE_H__

#include "Enemy.h"

class Bobble_Blue: public Enemy
{
private:
	int original_y = 0;
	Animation idle;

public:

	Bobble_Blue(int x, int y);
};

#endif // __BOBBLE_H__