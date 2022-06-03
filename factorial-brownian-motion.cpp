#include "factorial-brownian-motion.h"

void FactorialBrownianMotion::generate()
{
	seed = seed == -1 ? time(NULL) : seed;
	srand(seed);
	for (int k = 0; k < d; k++)
	{
		float dtSqrt = sqrt((float)T / (n - 1));
		float* normalDistributionArray = new float[MAX_SIZE];
		normalDistributionArray[0] = 0;
		for (int i = 1; i < n; i++)
		{
			normalDistributionArray[i] = normalDistribution(0, 1, seed) * dtSqrt;
		}
		cumulativeSum(normalDistributionArray, values, n, k, MAX_SIZE);
		
		delete[] normalDistributionArray;
	}
}

void FactorialBrownianMotion::normalize()
{
	for (int i = 0; i < d; i++)
	{
		normalizeArray(values, getStart(i), n);
	}
}

int FactorialBrownianMotion::getStart(int index)
{
	return index * MAX_SIZE;
}

int FactorialBrownianMotion::getStop(int index)
{
	return (index + 1) * MAX_SIZE;
}
