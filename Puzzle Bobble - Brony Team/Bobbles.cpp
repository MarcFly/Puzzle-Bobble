#include "Application.h"
#include "Bobbles.h"
#include "ModuleCollision.h"

Bobble_Blue::Bobble_Blue(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 12, 260, 16, 16 });
	idle.speed = 0.05;

	animation = &idle;

	collider = App->collision->AddCollider({0, 0, 16, 16}, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Red::Bobble_Red(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 12, 312, 16, 16 });
	idle.speed = 0.05;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Green::Bobble_Green(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 318, 260, 16, 16 });
	idle.speed = 0.05;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Yellow::Bobble_Yellow(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 12, 338, 16, 16 });
	idle.speed = 0.05;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Black::Bobble_Black(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 318, 286, 16, 16 });
	idle.speed = 0.05;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Orange::Bobble_Orange(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 318, 312, 16, 16 });
	idle.speed = 0.05;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Grey::Bobble_Grey(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 12, 286, 16, 16 });
	idle.speed = 0.05;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Purple::Bobble_Purple(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 318, 338, 16, 16 });
	idle.speed = 0.05;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}
