#pragma once
#include "pch.h"
#include "entity.h"
#include "camera.h"
#include "ame.h"

#define EMPTY_ENT 0
#define FREECAM_ENT 1
#define AME_ENT 2

typedef struct functable_entry_t
{
    void (*construct)(edict_entry_t* self, float delta);
    void (*destruct)(edict_entry_t* self, float delta);
 
    void (*init)(edict_entry_t* self, float delta);
    void (*tick)(edict_entry_t* self, float delta);
    void (*preRender) (edict_entry_t* self, float delta);
    void (*render) (edict_entry_t* self, float delta);
    void (*postRender) (edict_entry_t* self, float delta);
}functable_entry_t;

static functable_entry_t functable[] =
{
{GenericEntityConstruct, EmptyEntityDestruct, EmptyEntityInit, EmptyEntityTick, EmptyEntityPreRender, EmptyEntityRender, EmptyEntityPostRender},  // EMPTY_ENT
{FreeCamEntityConstruct, FreeCamEntityDestruct, FreeCamEntityInit, FreeCamEntityTick, FreeCamEntityPreRender, FreeCamEntityRender, FreeCamEntityPostRender}, // FREECAM_ENT
{AmeConstruct, AmeDestruct, AmeInit, AmeTick, EmptyEntityPreRender, AmeRender, EmptyEntityPostRender}   // Ame
};

edict_entry_t* createEdictHead();

void edict_init(edict_entry_t* head);
void edict_tick(edict_entry_t* head, float delta);
void edict_render(edict_entry_t* head);

void edict_push_back(edict_entry_t* head, int type);
void edict_destruct(edict_entry_t* head);
void edict_clear(edict_entry_t* head);