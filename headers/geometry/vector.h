#include "point.h"
#pragma once
#include <math.h>
typedef struct vector_ {
	float x;
	float y;
	float z;
}Vector;

Vector initVector(float x, float y, float z); /* initialise un vecteur à partir de ses coordonnées */

Vector createVectorFromPoints(Point a, Point b); /* initialise un vecteur à partir de deux points */

Vector addVectors(Vector a, Vector b); /* additionne les coord de deux vecteurs */

Vector subVectors(Vector a, Vector b); /* soustrait les coord de 2 vecteurs */

Vector multVector(Vector a, float b); /* multiplie un vecteur par un scalaire */

Vector divVector(Vector a, float b); /* divise un vecteur par un scalaire */

float dotProduct(Vector a, Vector b); /* produit scalaire de deux vecteurs */

float norm(Vector a); /* calcule la norme d'un vecteur */

Vector normalize(Vector a); /* Normalise un vecteur */

Vector vectorProduct(Vector a, Vector b); /* produit vectoriel de 2 vecteurs */

float distanceFromOrigin(Point a, Point o);

Vector negative(Vector a);
