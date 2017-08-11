#ifndef draw
#define draw

#define STACK_SIZE 100

typedef struct
{
    double x,y;
}point;

typedef struct
{
    point a,b;
}line;

typedef struct
{
    double angle;
    point current;
}state;


#endif
