#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Enemy::Enemy(int x, int y) : position(x, y), collider(nullptr)
{}

Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Draw(SDL_Texture* sprites)
{
	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}
