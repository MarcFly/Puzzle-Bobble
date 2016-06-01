#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Bobbles.h"

#define MAX_ENEMIES 150

enum ENEMY_TYPES
{
	NO_TYPE,
	BOBBLE_BLUE,
	BOBBLE_RED,
	BOBBLE_GREEN,
	BOBBLE_YELLOW,
	BOBBLE_BLACK,
	BOBBLE_ORANGE,
	BOBBLE_GREY,
	BOBBLE_PURPLE
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	bool EraseAll();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y);

private:

	void SpawnEnemy(const EnemyInfo& info);



private:

	Enemy* enemies[MAX_ENEMIES];
	EnemyInfo queue[MAX_ENEMIES];
	SDL_Texture* sprites;
};

#endif // __ModuleEnemies_H__