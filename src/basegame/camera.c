#include "camera.h"

void FreeCamEntityConstruct(edict_entry_t* self, float delta)
{
    sceneCam.fovy = 90;
    sceneCam.position = (Vector3){5.0f, 5.0f, 5.0f};
    sceneCam.projection = CAMERA_PERSPECTIVE;
    sceneCam.target = (Vector3){0, 0, 0};
    sceneCam.up = (Vector3){0, 1, 0};
    self->position = sceneCam.position;
    self->scale = Vector3One();
    self->rotation = QuaternionIdentity();

    self->shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(self->shader, "viewPos");
}
void FreeCamEntityDestruct(edict_entry_t* self, float delta){} // Nothing.
void FreeCamEntityInit(edict_entry_t* self, float delta)
{
    SetCameraMode(sceneCam, CAMERA_FREE);
}
void FreeCamEntityTick(edict_entry_t* self, float delta)
{
    UpdateCamera(&sceneCam);
    float cameraPos[3] = { sceneCam.position.x, sceneCam.position.y, sceneCam.position.z };
    SetShaderValue(self->shader, self->shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
}
void FreeCamEntityPreRender(edict_entry_t* self, float delta)
{
    BeginMode3D(sceneCam);
}
void FreeCamEntityRender(edict_entry_t* self, float delta)
{
    // idk
    #ifndef NDEBUG
    DrawGrid(20, 1);
    #endif
}
void FreeCamEntityPostRender(edict_entry_t* self, float delta)
{
    EndMode3D();
}