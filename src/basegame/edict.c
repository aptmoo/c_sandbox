#include "edict.h"

edict_entry_t *createEdictHead()
{
    edict_entry_t *temp = NULL;
    // Allocate entity memory
    temp = (edict_entry_t *)malloc(sizeof(edict_entry_t));

    temp->construct = genericEntityConstruct;
    temp->construct(temp, 0);

    // There is no such thing as a functional zero entity
    temp->init = testEntInit;
    temp->awake = genericEntityNullfunc;
    temp->sleep = genericEntityNullfunc;
    temp->tick = genericEntityNullfunc;
    temp->preRender = genericEntityNullfunc;
    temp->render = genericEntityNullfunc;
    temp->postRender = genericEntityNullfunc;

    return temp;
}

// Iterate over edict
void edict_init(edict_entry_t *head)
{
    edict_entry_t *current;
    while (current != NULL)
    {
        current->init(current, 0);
        current = current->next;
    }
}

void edict_tick(edict_entry_t *head, float delta)
{
    edict_entry_t *current = head;
    while (current != NULL)
    {
        current->tick(current, delta);
        current = current->next;
    }
}

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

void edict_push_back(edict_entry_t *head, edict_prefab_t data)
{
    edict_entry_t *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (edict_entry_t *)malloc(sizeof(edict_entry_t));

    // Construct and init functions
    current->next->construct = func_table[data.construct].action;
    current->next->construct(current->next, 0);
    current->next->init = func_table[data.init].action;
    current->next->init(current->next, 0);

    // All of the other functions.
    current->next->awake = func_table[data.awake].action;
    current->next->sleep = func_table[data.sleep].action;
    current->next->tick = func_table[data.tick].action;
    current->next->preRender = func_table[data.preRender].action;
    current->next->render = func_table[data.render].action;
    current->next->postRender = func_table[data.postRender].action;

    current->next->next = NULL;
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