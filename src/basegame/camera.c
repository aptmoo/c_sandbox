#include "camera.h"

void FreeCamEntityConstruct(edict_entry_t* self, float delta)
{
    sceneCam.fovy = 90;
    sceneCam.position = (Vector3){5.0f, 5.0f, 5.0f};
    sceneCam.projection = CAMERA_PERSPECTIVE;
    sceneCam.target = (Vector3){0, 0, 0};
    sceneCam.up = (Vector3){0, 1, 0};
}
void FreeCamEntityDestruct(edict_entry_t* self, float delta){}
void FreeCamEntityInit(edict_entry_t* self, float delta)
{
    SetCameraMode(sceneCam, CAMERA_FREE);
}
void FreeCamEntityTick(edict_entry_t* self, float delta)
{
    UpdateCamera(&sceneCam);
}
void FreeCamEntityPreRender(edict_entry_t* self, float delta)
{
    BeginMode3D(sceneCam);
}
void FreeCamEntityRender(edict_entry_t* self, float delta)
{
    // idk
    DrawGrid(20, 1);
}
void FreeCamEntityPostRender(edict_entry_t* self, float delta)
{
    EndMode3D();
}