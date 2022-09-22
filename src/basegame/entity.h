#pragma once
#include "pch.h"

typedef struct edict_entry_t
{
    // Common stuff
    Model mdl;
    ModelAnimation *anims;
    int animCount, currentAnimFrame;
    Shader shader;

    // Texture for billboards and skyboxes
    Texture2D tex;

    Vector3 position;
    Vector3 scale;
    Quaternion rotation;

    // Construction and destruction functions.
    void (*construct)(void* self, float delta);
    void (*destruct)(void* self, float delta);
 
    void (*init)(void* self, float delta);
    void (*tick)(void* self, float delta);
    void (*fixedTick)(void* self, float delta);
    void (*preRender) (void* self, float delta);
    void (*render) (void* self, float delta);
    void (*postRender) (void* self, float delta);


    struct edict_entry_t* next;
}edict_entry_t;

void GenericEntityConstruct(edict_entry_t* self, float delta);

void EmptyEntityDestruct(edict_entry_t* self, float delta);
void EmptyEntityInit(edict_entry_t* self, float delta);
void EmptyEntityTick(edict_entry_t* self, float delta);
void EmptyEntityFixedTick(edict_entry_t* self, float delta);
void EmptyEntityPreRender(edict_entry_t* self, float delta);
void EmptyEntityRender(edict_entry_t* self, float delta);
void EmptyEntityPostRender(edict_entry_t* self, float delta);