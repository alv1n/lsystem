#ifndef definitions
#define definitions

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "definitions.h"

#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

#define PI 3.14159265 
#define SCREEN_W 640
#define SCREEN_H 480

#define STRING_SIZE 1000
#define RULES_SIZE 1000
#define RULES_AMOUNT 40
#define MAX_STRING 1000


typedef struct
{
    char *in;
    char *out;
}rule;

typedef struct
{
    char *current;
    rule *rules;
    double angle;
}lsystem;

extern void init(lsystem *l);

extern void iterate(lsystem *l);

extern void takeWhile(char *in, char end, char *out);

#endif
