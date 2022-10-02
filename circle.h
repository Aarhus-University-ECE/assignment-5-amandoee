#pragma once
typedef struct point {
  //To komponenter af int typer for repræsentation af x,y
	int x;
	int y;
} point;

//Struct der indeholder et punkt p (bestående af int x, int y) og radius.
typedef struct circle {
  point p;
  int r;
} circle;



void fiveCircles(circle c[]);
int circleIsValid(const circle* c);
void translate(circle* c, const point* p);