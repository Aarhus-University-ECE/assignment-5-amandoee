//#include <malloc.h>
#include <stdlib.h>
#include "circle.h"
#include <stdbool.h>
#include <stdio.h>

circle c[5];

void fiveCircles(circle c[]) {
for (int i = 0; i < 5; i++) {

    //Sætter værdier for c[i] cirkel i array.
    c[i].p.x = i;
    c[i].p.y = i;
    c[i].r = i;
  }
}


//Funktion tjekker hvorvidt radius er større end 0, og returnerer tilsvarende værdi for sand/falsk
int circleIsValid(const circle * c) {
if ((c->r) > 0) {
    return true;
  } else {
    return false;
  }
}

//funktion der summerer x og y komponenter fra en cirkel med et punkt, og et andet punkt.
void translate(circle* c, const point* p) {
c->p.x = (c->p.x) + (p->x);
c->p.y = (c->p.y) + (p->y);
}



