#include "utils.h"

void DrawMultiModel(Model m)
{
    if(m.meshCount == m.materialCount)
    {
        for(int i = 0; i< m.meshCount; i++)
        {
            DrawMesh(m.meshes[i], m.materials[i], m.transform);
        }
    }
}

void SetModelShader(Model m, Shader s)
{
    for(int i = 0; i < m.materialCount; i++)
    {
        m.materials[i].shader = s;
    }
}

Matrix CalculateMatrixFromVars(Vector3 position, Vector3 scale, Quaternion rotation)
{
    return MatrixMultiply(MatrixMultiply(MatrixScale(scale.x, scale.y, scale.z), QuaternionToMatrix(rotation)), MatrixTranslate(position.x, position.y, position.z));
}