#include "basegame/edict.h"
#include "assert.h"

int main()
{
    edict_entry_t* head = createEdictHead();
    SetTargetFPS(60);
    InitWindow(1280, 720, "thing");

    edict_push_back(head, EMPTY_ENT);
    edict_push_back(head, FREECAM_ENT);

    while(!WindowShouldClose())
    {
        edict_tick(head, 10);
        BeginDrawing();
            ClearBackground(GRAY);
            edict_render(head);
        EndDrawing();
    }
    edict_destruct(head);
    edict_clear(head);

    CloseWindow();
}