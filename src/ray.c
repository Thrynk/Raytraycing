#include "../headers/ray.h"

Ray initRay(Camera a, int posX, int posY) {
	Ray r;
	r.vecDir.x = (a.pointHGVue.x - a.position.x) + a.droit.x * (a.largVue / a.xRes) * posX - a.haut.x * ( a.longVue / a.yRes ) * posY;
	r.vecDir.y = (a.pointHGVue.y - a.position.y) + a.droit.y * (a.largVue / a.xRes) * posX - a.haut.y * (a.longVue / a.yRes) * posY;
	r.vecDir.z = (a.pointHGVue.z - a.position.z) + a.droit.z * (a.largVue / a.xRes) * posX - a.haut.z * (a.longVue / a.yRes) * posY;

	r.origin.x = a.position.x;
	r.origin.y = a.position.y;
	r.origin.z = a.position.z;

	return r;
}

Vector reflect(Vector rayLight, Vector normal){
	Vector reflectedRay;
	float coef = 2 * dotProduct(rayLight, normal);
	reflectedRay = subVectors(rayLight, multVector(normal, coef));
	return reflectedRay;
}
