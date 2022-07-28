#include <math.h>
#include "nbody.h"

void bodyForce(body *p, float dt, int n) {

	for (int i = 0; i < n; i++) { 
		float Fx = 0.0f; float Fy = 0.0f; float Fz = 0.0f;

		for (int j = 0; j < n; j++) {
			if (i!=j) {
				float dx = p[j].x - p[i].x;
				float dy = p[j].y - p[i].y;
				float dz = p[j].z - p[i].z;
				double softeningSquared = 1e-3;
				float distSqr = dx*dx + dy*dy + dz*dz + softeningSquared;
				float invDist = 1.0f / sqrtf(distSqr);
				float invDist3 = invDist * invDist * invDist;

				double G = 6.674e-11;
				float g_masses = G * p[j].m * p[i].m;

				Fx += g_masses * dx * invDist3; 
				Fy += g_masses * dy * invDist3; 
				Fz += g_masses * dz * invDist3;
			}
		}

		p[i].vx += dt*Fx/p[i].m; p[i].vy += dt*Fy/p[i].m; p[i].vz += dt*Fz/p[i].m;
	}
}

void integrate(body *p, float dt, int n){
	for (int i = 0 ; i < n; i++) {
		p[i].x += p[i].vx*dt;
		p[i].y += p[i].vy*dt;
		p[i].z += p[i].vz*dt;
	}
}
