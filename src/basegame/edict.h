#pragma once
#include "pch.h"
#include "entity.h"

/*
    void (*init)(void* self, float delta);
    void (*awake)(void* self, float delta);
    void (*sleep)(void* self, float delta);

    void (*tick)(void* self, float delta);
    void (*preRender)(void* self, float delta);
    void (*render)(void* self, float delta);
    void (*postRender)(void* self, float delta);
*/

// Universal func defs
#define FUNC_TABLE_SIZE 7
#define GENERIC_ENT_CONSTRUCT 0
#define GENERIC_ENT_NULLFUNC 1

// test ent defs
#define TEST_ENT_INIT 2
#define TEST_ENT_AWAKE 3
#define TEST_ENT_SLEEP 4
#define TEST_ENT_TICK 5
#define TEST_ENT_PRERENDER 6
#define TEST_ENT_RENDER 7
#define TEST_ENT_POSTRENDER 8

// Camera ent defs
#define CAM_ENT_INIT 9
#define CAM_ENT_AWAKE 1
#define CAM_ENT_SLEEP 1
#define CAM_ENT_TICK 10
#define CAM_ENT_PRERENDER 11
#define CAM_ENT_RENDER 12
#define CAM_ENT_POSTRENDER 13

#define PREFAB_TEST 0

typedef struct edict_func_table_entry_t
{
    int id;
    void (*action)(edict_entry_t* self, float delta);
}edict_func_table_entry_t;

static edict_func_table_entry_t func_table[] =
{
{GENERIC_ENT_CONSTRUCT, genericEntityConstruct},
{GENERIC_ENT_NULLFUNC, genericEntityNullfunc},
{TEST_ENT_INIT, testEntInit},
{TEST_ENT_AWAKE, testEntAwake},
{TEST_ENT_SLEEP, testEntSleep},
{TEST_ENT_TICK, testEntTick},
{TEST_ENT_PRERENDER, testEntPreRender},
{TEST_ENT_RENDER, testEntRender},
{TEST_ENT_POSTRENDER, testEntPostRender},
};

static edict_prefab_t prefab_table[] = 
{
{GENERIC_ENT_CONSTRUCT, TEST_ENT_INIT, TEST_ENT_AWAKE, TEST_ENT_SLEEP, TEST_ENT_TICK, TEST_ENT_PRERENDER, TEST_ENT_RENDER, TEST_ENT_POSTRENDER} // 0
};

edict_entry_t* createEdictHead();

void edict_init(edict_entry_t* head);
void edict_tick(edict_entry_t* head, float delta);
void edict_render(edict_entry_t* head);

void edict_push_back(edict_entry_t* head, edict_prefab_t data);
void edict_clear(edict_entry_t* head);