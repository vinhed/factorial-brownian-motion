#pragma once

#include "include.h"
#include "math.h"

#define MAX_SIZE 16384
#define MAX_COUNT 16384

struct FactorialBrownianMotion
{
	float* values = new float[MAX_SIZE * MAX_COUNT];

	int seed = 0;
	int n = 0;
	int d = 0;
	float T = 0;

	FactorialBrownianMotion(int seedS, int nS, int dS, float TS) 
	{
		if (nS > MAX_SIZE)
		{
			std::cout << "Too many values! n = " << MAX_SIZE << std::endl;
			nS = MAX_SIZE;
		}

		seed = seedS;
		n = nS;
		d = dS * 6;
		T = TS;
	}

	void generate();
	void normalize();
	int getStart(int index);
	int getStop(int index);
};

