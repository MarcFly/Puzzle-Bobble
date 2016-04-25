#ifndef __BOBBLE_H__
#define __BOBBLE_H__

#include "Enemy.h"

class Bobble_Blue: public Enemy
{
private:
	int original_y = 0;
	Animation idle;
	Animation explode;

public:

	Bobble_Blue(int x, int y);
};

//

class Bobble_Red : public Enemy
{
private:
	int original_y = 0;
	Animation idle;
	Animation explode;

public:

	Bobble_Red(int x, int y);
};

//

class Bobble_Green : public Enemy
{
private:
	int original_y = 0;
	Animation idle;
	Animation explode;

public:

	Bobble_Green(int x, int y);
};

//

class Bobble_Yellow : public Enemy
{
private:
	int original_y = 0;
	Animation idle;
	Animation explode;

public:

	Bobble_Yellow(int x, int y);
};

//

class Bobble_Black : public Enemy
{
private:
	int original_y = 0;
	Animation idle;
	Animation explode;

public:

	Bobble_Black(int x, int y);
};

//

class Bobble_Orange : public Enemy
{
private:
	int original_y = 0;
	Animation idle;
	Animation explode;

public:

	Bobble_Orange(int x, int y);
};

//

class Bobble_Grey : public Enemy
{
private:
	int original_y = 0;
	Animation idle;
	Animation explode;

public:

	Bobble_Grey(int x, int y);
};

//

class Bobble_Purple : public Enemy
{
private:
	int original_y = 0;
	Animation idle;
	Animation explode;

public:

	Bobble_Purple(int x, int y);
};


#endif // __BOBBLE_H__