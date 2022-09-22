#include "edict.h"

edict_entry_t *createEdictHead()
{
    edict_entry_t *temp = NULL;
    // Allocate entity memory
    temp = (edict_entry_t *)malloc(sizeof(edict_entry_t));

    // Constructor
    temp->construct = functable[EMPTY_ENT].construct;
    temp->construct(temp, 0);

    // Destructor
    temp->destruct = functable[EMPTY_ENT].destruct;

    // Funcs
    temp->init = functable[EMPTY_ENT].init;
    temp->init(temp, 0);
    temp->tick = functable[EMPTY_ENT].tick;
    temp->fixedTick = functable[EMPTY_ENT].fixedTick;
    temp->preRender = functable[EMPTY_ENT].preRender;
    temp->render = functable[EMPTY_ENT].render;
    temp->postRender = functable[EMPTY_ENT].postRender;

    temp->next = NULL;

    return temp;
}

// Init all of the entries.
void edict_init(edict_entry_t *head)
{
    edict_entry_t *current;
    while (current != NULL)
    {
        current->init(current, 0);
        current = current->next;
    }
}

// Tick all the edict entries.
void edict_tick(edict_entry_t *head, float delta)
{
    edict_entry_t *current = head;
    while (current != NULL)
    {
        current->tick(current, delta);
        current = current->next;
    }
}
void edict_fixedTick(edict_entry_t* head, float delta)
{
    edict_entry_t *current = head;
    while (current != NULL)
    {
        current->fixedTick(current, delta);
        current = current->next;
    }
}

// Call the render functions in all edict entries.
void edict_render(edict_entry_t *head)
{
    edict_entry_t *current = head;
    while (current != NULL)
    {
        current->preRender(current, 0);
        current = current->next;
    }
    current = head;
    while (current != NULL)
    {
        current->render(current, 0);
        current = current->next;
    }
    current = head;
    while (current != NULL)
    {
        current->postRender(current, 0);
        current = current->next;
    }
}

// Add a node to the end of the edict.
void edict_push_back(edict_entry_t *head, int type)
{
    // The same iteration thing as before.
    edict_entry_t *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    // Allocate memory for the new node.
    current->next = (edict_entry_t *)malloc(sizeof(edict_entry_t));

    // Constructor
    current->next->construct = functable[type].construct;
    current->next->construct(current->next, 0);

    // Destructor
    current->next->destruct = functable[type].destruct;

    // Funcs
    current->next->init = functable[type].init;
    current->next->init(current->next, 0);
    current->next->tick = functable[type].tick;
    current->next->fixedTick = functable[type].fixedTick;
    current->next->preRender = functable[type].preRender;
    current->next->render = functable[type].render;
    current->next->postRender = functable[type].postRender;
    current->next->next = NULL;
}

void edict_destruct(edict_entry_t* head)
{
    edict_entry_t* current = head;
    while(current!= NULL)
    {
        current->destruct(current, 0);
        current = current->next;
    }
}

void edict_clear(edict_entry_t *head)
{
    printf("Edict cleared.\n");
    edict_entry_t* current = head;
    edict_entry_t* next;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}