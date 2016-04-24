#ifndef __BOBBLE_H__
#define __BOBBLE_H__

#include "Enemy.h"

class Bobble: public Enemy
{
private:
	int original_y = 0;
	Animation idle;

public:

	Bobble(int x, int y);

	void Move(){}
};

#endif // __BOBBLE_H__