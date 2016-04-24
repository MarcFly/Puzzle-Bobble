#include "Application.h"
#include "Bobble.h"
#include "ModuleCollision.h"

Bobble::Bobble(int x, int y) : Enemy(x, y)
{
	idle.PushBack({5,6,24,24});
	idle.speed = 0.2f;

	animation = &idle;

	collider = App->collision->AddCollider({0, 0, 24, 24}, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}
