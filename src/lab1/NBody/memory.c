
#include <malloc.h>
#include <stdlib.h>
#include "nbody.h"

body* get_memory(int nBodies)
{
	body *p = (body*)malloc(nBodies*sizeof(body));
	return p;
}

void free_memory(body *p)
{
	free(p);
}

void randomizeBodies(body *data, int n) {
	for (int i = 0; i < n; i++) {
		data[i].m  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;

		data[i].x  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data[i].y  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data[i].z  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;

		data[i].vx = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data[i].vy = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data[i].vz = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
	}
}

