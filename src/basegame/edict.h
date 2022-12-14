#pragma once
#include "pch.h"
#include "entity.h"
#include "camera.h"
#include "ame.h"
#include "envlight.h"

#define EMPTY_ENT 0
#define FREECAM_ENT 1
#define AME_ENT 2
#define ENVLIHGT_ENT 3

typedef struct functable_entry_t
{
    void (*construct)(edict_entry_t* self, float delta);
    void (*destruct)(edict_entry_t* self, float delta);
 
    void (*init)(edict_entry_t* self, float delta);
    void (*tick)(edict_entry_t* self, float delta);
    void (*fixedTick)(edict_entry_t* self, float delta);
    void (*preRender) (edict_entry_t* self, float delta);
    void (*render) (edict_entry_t* self, float delta);
    void (*postRender) (edict_entry_t* self, float delta);
}functable_entry_t;

static functable_entry_t functable[] =
{
{GenericEntityConstruct, EmptyEntityDestruct, EmptyEntityInit, EmptyEntityTick,EmptyEntityFixedTick, EmptyEntityPreRender, EmptyEntityRender, EmptyEntityPostRender},  // EMPTY_ENT
{FreeCamEntityConstruct, FreeCamEntityDestruct, FreeCamEntityInit, FreeCamEntityTick,EmptyEntityFixedTick, FreeCamEntityPreRender, FreeCamEntityRender, FreeCamEntityPostRender}, // FREECAM_ENT
{AmeConstruct, AmeDestruct, AmeInit, AmeTick, AmeFixedTick, EmptyEntityPreRender, AmeRender, EmptyEntityPostRender},   // Ame
{EnvConstruct, EnvDestruct, EnvInit, EnvTick, EmptyEntityFixedTick, EmptyEntityPreRender, EnvRender, EmptyEntityPostRender}    // Env light
};

edict_entry_t* createEdictHead();

void edict_init(edict_entry_t* head);
void edict_tick(edict_entry_t* head, float delta);
void edict_fixedTick(edict_entry_t* head, float delta);
void edict_render(edict_entry_t* head);
void edict_push_back(edict_entry_t *head, int type, Vector3 position, Vector3 scale, Quaternion rotation, Shader shader);
void edict_destruct(edict_entry_t* head);
void edict_clear(edict_entry_t* head);