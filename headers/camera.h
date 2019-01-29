#include "geometry/vector.h"

typedef struct camera_{ /* Représente une caméra */
  Point position; /* Position de la caméra */
  Point lookPoint; /* Point regardé */
  Vector haut; /* vecteur haut de la caméra */
  Vector droit; /* vecteur droit de la caméra */
  Vector lookDir; /* vecteur de direction de la caméra */
  Point pointHGVue; /* Point haut gauche de l'image */
  int xRes; /* Resolution en largeur de la caméra */
  int yRes; /* Résolution en hauteur de la caméra */
  float distVue; /* Distance de la caméra à l'image */
  float longVue; /* longueur du champ de vision */
  float largVue; /* largeur du champ de vision */
} Camera;
