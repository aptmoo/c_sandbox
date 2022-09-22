#include "pch.h"
#include "entity.h"

static Camera sceneCam;

void FreeCamEntityConstruct(edict_entry_t* self, float delta);
void FreeCamEntityDestruct(edict_entry_t* self, float delta);
void FreeCamEntityInit(edict_entry_t* self, float delta);
void FreeCamEntityTick(edict_entry_t* self, float delta);
void FreeCamEntityPreRender(edict_entry_t* self, float delta);
void FreeCamEntityRender(edict_entry_t* self, float delta);
void FreeCamEntityPostRender(edict_entry_t* self, float delta);

// void GenericEntityConstruct(edict_entry_t* self, float delta);
// void EmptyEntityDestruct(edict_entry_t* self, float delta);
// void EmptyEntityInit(edict_entry_t* self, float delta);
// void EmptyEntityTick(edict_entry_t* self, float delta);
// void EmptyEntityPreRender(edict_entry_t* self, float delta);
// void EmptyEntityRender(edict_entry_t* self, float delta);
// void EmptyEntityPostRender(edict_entry_t* self, float delta);