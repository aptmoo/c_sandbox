#pragma once
#include "pch.h"

// Edict entry, aka an entity.
typedef struct edict_entry_t
{
    Texture2D tex;

    Vector3 position;
    Vector3 scale;
    Quaternion rotation;

    void (*construct)(void* self, float delta);

    void (*init)(void* self, float delta);
    void (*awake)(void* self, float delta);
    void (*sleep)(void* self, float delta);

    void (*tick)(void* self, float delta);
    void (*preRender)(void* self, float delta);
    void (*render)(void* self, float delta);
    void (*postRender)(void* self, float delta);

    struct edict_entry_t* next;
}edict_entry_t;

// Edict entry prefab data.
typedef struct edict_prefab_t
{
    int construct;
    int init;
    int awake;
    int sleep;
    int tick;
    int preRender;
    int render;
    int postRender;
}edict_prefab_t;

//Generic int constructs.
void genericEntityConstruct(edict_entry_t* self, float delta);
void genericEntityNullfunc(edict_entry_t* self, float delta);

// Test funcs.
void testEntInit(edict_entry_t* self, float delta);
void testEntAwake(edict_entry_t* self, float delta);
void testEntSleep(edict_entry_t* self, float delta);
void testEntTick(edict_entry_t* self, float delta);
void testEntPreRender(edict_entry_t* self, float delta);
void testEntRender(edict_entry_t* self, float delta);
void testEntPostRender(edict_entry_t* self, float delta);