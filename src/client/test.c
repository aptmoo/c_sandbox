#include "basegame/edict.h"

int main()
{
    edict_entry_t* head = createEdictHead();
    SetTargetFPS(60);
    InitWindow(1280, 720, "thing");

    edict_push_back(head, prefab_table[PREFAB_TEST]);

    while(!WindowShouldClose())
    {
        edict_tick(head, 10);
        BeginDrawing();
            ClearBackground(GRAY);
            edict_render(head);
        EndDrawing();
    }
    edict_close(head);

    CloseWindow();
}