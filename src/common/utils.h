#pragma once
#include "pch.h"

void DrawMultiModel(Model m);

void SetModelShader(Model m, Shader s);

Matrix CalculateMatrixFromVars(Vector3 position, Vector3 scale, Quaternion rotation);
