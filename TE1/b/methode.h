#ifndef METHODE_H
#define METHODE_H
float deriv2tdd_decentree_droite(float f(float), float h, float t0);
float deriv2tdd_decentree_gauche(float f(float), float h, float t0);
float deriv2tdd_centree(float f(float), float h, float t0);
#endif
