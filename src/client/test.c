#include "basegame/edict.h"

int main()
{
    const double dt = 0.03;
    double accumulator = 0.0f;

    edict_entry_t* head = createEdictHead();
    SetTargetFPS(60);
    InitWindow(1280, 720, "thing");

    Shader lit = LoadShader("data/shaders/base.vs", "data/shaders/lit.fs");

    edict_push_back(head, FREECAM_ENT, Vector3Zero(), Vector3One(), QuaternionIdentity(), lit);
    edict_push_back(head, AME_ENT, Vector3Zero(), Vector3One(), QuaternionIdentity(), lit);
    edict_push_back(head, ENVLIHGT_ENT, (Vector3){0.0f, 10.0f, 0.0f}, Vector3One(), QuaternionIdentity(), lit);

    while(!WindowShouldClose())
    {
        edict_tick(head, 10);
        accumulator += GetFrameTime();
        while(accumulator >= dt)
        {
            edict_fixedTick(head, dt);
            accumulator -= dt;
        }

        BeginDrawing();
            ClearBackground(GRAY);
            edict_render(head);

            #ifndef NDEBUG
                DrawFPS(10, 10);
            #endif
        EndDrawing();
    }
    edict_destruct(head);
    edict_clear(head);

    CloseWindow();
}