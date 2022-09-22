#pragma once
typedef struct point {
	int x;
	int y;
} point;


typedef struct circle {
  point p;
  int r;
} circle;


/*add your definition of circle here. You need to call it "circle"*/


//TEST3


void fiveCircles(circle c[]);
int circleIsValid(const circle* c);
void translate(circle* c, const point* p);