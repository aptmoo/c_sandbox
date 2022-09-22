#include "entity.h"

void GenericEntityConstruct(edict_entry_t* self, float delta){printf("Constructed!\n");}

void EmptyEntityDestruct(edict_entry_t* self, float delta){printf("Destructed!\n");}
void EmptyEntityInit(edict_entry_t* self, float delta){printf("Inited!!\n");}
void EmptyEntityTick(edict_entry_t* self, float delta){}
void EmptyEntityPreRender(edict_entry_t* self, float delta){}
void EmptyEntityRender(edict_entry_t* self, float delta){;}
void EmptyEntityPostRender(edict_entry_t* self, float delta){}

