#pragma once

#include "include.h"

float normalDistribution(float location, float scale, int seed);
void cumulativeSum(float* arr, float* values, int n, int d, int MAX_SIZE);
void normalizeArray(float* arr, int start, int n);