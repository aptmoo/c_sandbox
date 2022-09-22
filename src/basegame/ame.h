#pragma once
#include "pch.h"
#include "entity.h"

void AmeConstruct(edict_entry_t* self, float delta);
void AmeDestruct(edict_entry_t* self, float delta);
void AmeInit(edict_entry_t* self, float delta);
void AmeTick(edict_entry_t* self, float delta);
void AmeRender(edict_entry_t* self, float delta);

// void GenericEntityConstruct(edict_entry_t* self, float delta);
// void EmptyEntityDestruct(edict_entry_t* self, float delta);
// void EmptyEntityInit(edict_entry_t* self, float delta);
// void EmptyEntityTick(edict_entry_t* self, float delta);
// void EmptyEntityPreRender(edict_entry_t* self, float delta);
// void EmptyEntityRender(edict_entry_t* self, float delta);
// void EmptyEntityPostRender(edict_entry_t* self, float delta);