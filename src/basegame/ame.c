#include "ame.h"
#include "common/utils.h"

void AmeConstruct(edict_entry_t* self, float delta)
{
    self->position = Vector3Zero();
    self->scale = Vector3One();
    self->rotation = QuaternionFromEuler(-90*DEG2RAD, 0, 0);
    self->mdl = LoadModel("data/models/ame.iqm");

    self->mdl.materials[0].maps[0].texture = LoadTexture("data/textures/SmolameTex.png");
    self->mdl.materials[1].maps[0].texture = LoadTexture("data/textures/WalfiestyleHoloEN_FaceTex.png");
    self->mdl.materials[2].maps[0].texture = LoadTexture("data/textures/WalfiestyleHoloEN_FaceTex.png");
    
    self->anims = LoadModelAnimations("data/models/ame_anims.iqm", &self->animCount);
}
void AmeDestruct(edict_entry_t* self, float delta)
{
    UnloadModel(self->mdl);
}
void AmeInit(edict_entry_t* self, float delta){}
void AmeTick(edict_entry_t* self, float delta)
{
    self->rotation = QuaternionFromEuler(-90*DEG2RAD, 0, 0);
    self->mdl.transform = CalculateMatrixFromVars(self->position, self->scale, self->rotation);

    if(IsKeyDown(KEY_SPACE))
    {
        self->currentAnimFrame++;
        UpdateModelAnimation(self->mdl, self->anims[0], self->currentAnimFrame);
        if(self->currentAnimFrame >= self->anims[0].frameCount) self->currentAnimFrame = 0;
    }
}
void AmeRender(edict_entry_t* self, float delta)
{
    DrawMultiModel(self->mdl);
}