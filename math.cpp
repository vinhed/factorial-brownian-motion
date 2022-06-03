#include "math.h"

float normalDistribution(float location, float scale, int seed)
{
	static bool seedSet = false;
	static std::default_random_engine generator;
	if (!seedSet)
	{
		generator.seed(seed);
		seedSet = true;
	}
	static std::normal_distribution<float> distribution(location, scale);
	return distribution(generator);
}

void cumulativeSum(float* arr, float* values, int n, int d, int MAX_SIZE)
{
	for (int i = 0; i < n; i++)
	{
		float s = 0;
		for (int j = 0; j < i + 1; j++)
		{
			s += arr[j];
		}
		values[i + d * MAX_SIZE] = s;
	}
}

void normalizeArray(float* arr, int start, int n)
{
	float min = 0xFFFFFFF;
	float max = -0xFFFFFFF;
	for (int i = start; i < n + start; i++)
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	float dt = max - min;
	for (int i = start; i < n + start; i++)
	{
		arr[i] = (arr[i] - min) / dt;
		if (arr[i] < 0) arr[i] = 0;
	}
}