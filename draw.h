#ifndef draw
#define draw

#define STACK_SIZE 10000
#define LINE_AMOUNT 100000

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

extern void convert(lsystem *l, line *lines);

extern void draw2(line *lines);

extern void draw3(line *lines);

#endif
