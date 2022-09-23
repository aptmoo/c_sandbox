#pragma once
#include "pch.h"
#include "entity.h"

void EnvConstruct(edict_entry_t* self, float delta);
void EnvDestruct(edict_entry_t* self, float delta);
void EnvInit(edict_entry_t* self, float delta);
void EnvTick(edict_entry_t* self, float delta);
void EnvRender(edict_entry_t* self, float delta);

// void GenericEntityConstruct(edict_entry_t* self, float delta);
// void EmptyEntityDestruct(edict_entry_t* self, float delta);
// void EmptyEntityInit(edict_entry_t* self, float delta);
// void EmptyEntityTick(edict_entry_t* self, float delta);
// void EmptyEntityPreRender(edict_entry_t* self, float delta);
// void EmptyEntityRender(edict_entry_t* self, float delta);
// void EmptyEntityPostRender(edict_entry_t* self, float delta);