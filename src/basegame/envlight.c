#include "envlight.h"

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

void EnvConstruct(edict_entry_t* self, float delta)
{
    self->color = (Color){235, 166, 71, 255};
    self->target = (Vector3){-20.0f, 0.0f, -20.0f};
}
void EnvDestruct(edict_entry_t* self, float delta){} // Nothing
void EnvInit(edict_entry_t* self, float delta)
{
    int ambientLoc = GetShaderLocation(self->shader, "ambient");
    SetShaderValue(self->shader, ambientLoc, (float[4]){0.41f, 0.55f, 0.64f, 1.0f}, SHADER_UNIFORM_VEC4);
    self->light = CreateLight(LIGHT_DIRECTIONAL, self->position, self->target, self->color, 25, self->shader);
}
void EnvTick(edict_entry_t* self, float delta)
{
    UpdateLightValues(self->shader, self->light);
}
void EnvRender(edict_entry_t* self, float delta)
{
    //?
}