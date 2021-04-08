#include "methode.h"

float deriv2tdd_decentree_droite(float f(float), float h, float t0) {
	return (f(t0+h)-f(t0))/h;
}

float deriv2tdd_decentree_gauche(float f(float), float h, float t0) {
        return (f(t0)-f(t0-h))/h;
}

float deriv2tdd_centree(float f(float), float h, float t0) {
        return (f(t0+h)-f(t0-h))/(2*h);
}
