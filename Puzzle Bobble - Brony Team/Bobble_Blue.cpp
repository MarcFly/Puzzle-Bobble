#include "Application.h"
#include "Bobble_Blue.h"
#include "ModuleCollision.h"

Bobble_Blue::Bobble_Blue(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 12, 260, 16, 16 });
	idle.speed = 0.05;

	animation = &idle;

	collider = App->collision->AddCollider({0, 0, 16, 16}, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}
