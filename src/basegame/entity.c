#include "entity.h"

void GenericEntityConstruct(edict_entry_t* self, float delta)
{
    self->position = Vector3Zero();
    self->scale = Vector3One();
    self->rotation = QuaternionIdentity();
}

void EmptyEntityDestruct(edict_entry_t* self, float delta){}
void EmptyEntityInit(edict_entry_t* self, float delta){}
void EmptyEntityTick(edict_entry_t* self, float delta){}
void EmptyEntityFixedTick(edict_entry_t* self, float delta){}
void EmptyEntityPreRender(edict_entry_t* self, float delta){}
void EmptyEntityRender(edict_entry_t* self, float delta){}
void EmptyEntityPostRender(edict_entry_t* self, float delta){}

