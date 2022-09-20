#include "entity.h"

// Construct a generic entity.
void genericEntityConstruct(edict_entry_t* self, float delta)
{
    self->position = Vector3Zero();
    self->scale = Vector3One();
    self->rotation = QuaternionIdentity();
}

void genericEntityNullfunc(edict_entry_t* self, float delta)
{

}

void testEntInit(edict_entry_t* self, float delta)
{
    self->tex = LoadTexture("data/test.png");
}
void testEntAwake(edict_entry_t* self, float delta)
{
    printf("Awoken!\n");
}
void testEntSleep(edict_entry_t* self, float delta)
{
    printf("zzz!\n");
}
void testEntTick(edict_entry_t* self, float delta)
{
    self->position.x = GetMousePosition().x;
    self->position.y = GetMousePosition().y;

}
void testEntPreRender(edict_entry_t* self, float delta)
{
    // printf("PreRendered!\n");
}
void testEntRender(edict_entry_t* self, float delta)
{
    DrawTextureEx(self->tex, (Vector2){self->position.x, self->position.y}, 0, 0.25f, WHITE);
}
void testEntPostRender(edict_entry_t* self, float delta)
{
    // printf("PostRendered!\n");
}