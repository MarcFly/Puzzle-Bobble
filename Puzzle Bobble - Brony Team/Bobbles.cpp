#include "Application.h"
#include "Bobbles.h"
#include "ModuleCollision.h"

Bobble_Blue::Bobble_Blue(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 18, 559, 16, 16 });
	idle.PushBack({ 35, 559, 16, 16 });
	idle.PushBack({ 52, 559, 16, 16 });
	idle.PushBack({ 18, 559, 16, 16 });
	idle.PushBack({ 18, 559, 16, 16 });
	idle.PushBack({ 18, 559, 16, 16 });
	idle.speed = 0.1f;

	explode.PushBack({ 112, 260, 16, 16 });
	explode.PushBack({ 132, 260, 16, 16 });
	explode.PushBack({ 152, 260, 16, 16 });
	explode.PushBack({ 172, 260, 16, 16 });
	explode.PushBack({ 192, 260, 16, 16 });
	explode.PushBack({ 212, 260, 16, 16 });
	explode.PushBack({ 232, 260, 16, 16 });
	explode.speed = 0.05f;

	animation = &idle;

	collider = App->collision->AddCollider({0, 0, 15, 15}, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Red::Bobble_Red(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 18, 607, 16, 16 });
	idle.speed = 0.05f;

	explode.PushBack({ 112, 312, 16, 16 });
	explode.PushBack({ 132, 312, 16, 16 });
	explode.PushBack({ 152, 312, 16, 16 });
	explode.PushBack({ 172, 312, 16, 16 });
	explode.speed = 0.05f;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 15, 15 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Green::Bobble_Green(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 266, 559, 16, 16 });
	idle.PushBack({ 266, 559, 16, 16 });
	idle.PushBack({ 266, 559, 16, 16 });
	idle.PushBack({ 283, 559, 16, 16 });
	idle.PushBack({ 300, 559, 16, 16 });
	idle.speed = 0.05f;

	explode.PushBack({ 338, 260, 16, 16 });
	explode.PushBack({ 358, 260, 16, 16 });
	explode.PushBack({ 378, 260, 16, 16 });
	explode.PushBack({ 398, 260, 16, 16 });
	explode.speed = 0.05f;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 15, 15 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Yellow::Bobble_Yellow(int x, int y) : Enemy(x, y)
{

	idle.PushBack({ 18, 631, 16, 16 });
	idle.PushBack({ 35, 631, 16, 16 });
	idle.PushBack({ 18, 631, 16, 16 });
	idle.speed = 0.05f;

	explode.PushBack({ 32, 338, 16, 16 });
	explode.PushBack({ 52, 338, 16, 16 });
	explode.PushBack({ 72, 338, 16, 16 });
	explode.PushBack({ 92, 338, 16, 16 });
	explode.speed = 0.05f;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 15, 15 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Black::Bobble_Black(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 266, 583, 16, 16 });
	idle.PushBack({ 266, 583, 16, 16 });
	idle.PushBack({ 266, 583, 16, 16 });
	idle.PushBack({ 283, 583, 16, 16 });
	idle.PushBack({ 300, 583, 16, 16 });
	idle.speed = 0.05f;

	explode.PushBack({ 338, 286, 16, 16 });
	explode.PushBack({ 358, 286, 16, 16 });
	explode.PushBack({ 378, 286, 16, 16 });
	explode.PushBack({ 398, 286, 16, 16 });
	explode.speed = 0.05f;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 15, 15 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Orange::Bobble_Orange(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 266, 607, 16, 16 });
	idle.PushBack({ 266, 607, 16, 16 });
	idle.PushBack({ 266, 607, 16, 16 });
	idle.PushBack({ 283, 607, 16, 16 });
	idle.PushBack({ 300, 607, 16, 16 });
	idle.speed = 0.05f;

	explode.PushBack({ 338, 312, 16, 16 });
	explode.PushBack({ 358, 312, 16, 16 });
	explode.PushBack({ 378, 312, 16, 16 });
	explode.PushBack({ 398, 312, 16, 16 });
	explode.speed = 0.05f;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 15, 15 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Grey::Bobble_Grey(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 18, 583, 16, 16 });
	idle.speed = 0.05f;

	explode.PushBack({ 32, 286, 16, 16 });
	explode.PushBack({ 52, 286, 16, 16 });
	explode.PushBack({ 72, 286, 16, 16 });
	explode.PushBack({ 92, 286, 16, 16 });
	explode.speed = 0.05f;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 15, 15 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}

Bobble_Purple::Bobble_Purple(int x, int y) : Enemy(x, y)
{
	idle.PushBack({ 266, 631, 16, 16 });
	idle.PushBack({ 266, 631, 16, 16 });
	idle.PushBack({ 266, 631, 16, 16 });
	idle.PushBack({ 283, 631, 16, 16 });
	idle.PushBack({ 300, 631, 16, 16 });

	idle.speed = 0.05f;

	explode.PushBack({ 266, 631, 16, 16 });
	explode.PushBack({ 358, 338, 16, 16 });
	explode.PushBack({ 378, 338, 16, 16 });
	explode.PushBack({ 398, 338, 16, 16 });
	explode.speed = 0.05f;

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 15, 15 }, COLLIDER_TYPE::COLLIDER_BOBBLE, (Module*)App->enemies);

	original_y = y;
}
