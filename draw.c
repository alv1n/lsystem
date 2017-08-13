#include "definitions.h"
#include "draw.h"

void convert(lsystem *l, line *lines)
{
    /*Starting state */
    state s;
    s.angle = 0;
    s.current.x = SCREEN_W / 2 ;
    s.current.y = SCREEN_H / 2 ;

    /* Stack to push changes onto */
    state *stack = calloc(STACK_SIZE, sizeof(state) );

    for(char *c = l->current; *c != '\0'; c++)
    {
        if( *c >= 'A' && *c <= 'Z')
        {
            lines->a.x = s.current.x;
            lines->a.y = s.current.y;

            s.current.x += cos(s.angle);
            s.current.y += sin(s.angle);

            lines->b.x = s.current.x;
            lines->b.y = s.current.y;

            lines++;
        }
        else if (*c == '+')
        {
            s.angle += l->angle;
        }
        else if (*c == '-')
        {
            s.angle -= l->angle;
        }
        else if (*c == '[')
        {
            memcpy(stack, &s, sizeof(state) );
            stack++;
        }
        else if (*c == ']')
        {
            stack--;
            memcpy(&s, stack, sizeof(state) );
        }

    }
}

float min(float a, float b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

float max(float a, float b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

void draw3(line *lines)
{
    /*Find furthest points */
    double x_min = lines[0].a.x;
    double y_min = lines[0].a.y;
    double x_max = lines[0].a.x;
    double y_max = lines[0].a.y;

    for(int i = 0; lines[i].a.x != 0; i++)
    {
        x_min = min(x_min, lines[i].a.x);
        x_min = min(x_min, lines[i].b.x);

        x_max = max(x_max, lines[i].a.x);
        x_max = max(x_max, lines[i].b.x);

        y_min = min(y_min, lines[i].a.y);
        y_min = min(y_min, lines[i].b.y);
        
        y_max = max(y_max, lines[i].a.y);
        y_max = max(y_max, lines[i].b.y);
    }
    printf("%f,%f,%f,%f\n", x_min, x_max, y_min, y_max);
    double dy,dx;
    dx = x_max - x_min;
    dy = y_max - y_min;
    printf("%f,%f\n", dx, dy);

    for(int i = 0; lines[i].a.x != 0; i++)
    { 
        lines[i].a.x = (lines[i].a.x - x_min) / dx * SCREEN_W;
        al_draw_line(lines[i].a.x, lines[i].a.y, lines[i].b.x, lines[i].b.y, al_map_rgb(255,0,0), 3);
    }
}

void draw2(line *lines)
{
    /*Find furthest points */
    double x_min = lines[0].a.x;
    double y_min = lines[0].a.y;
    double x_max = lines[0].a.x;
    double y_max = lines[0].a.y;

    for(int i = 0; lines[i].a.x != 0; i++)
    {
        x_min = min(x_min, lines[i].a.x);
        x_min = min(x_min, lines[i].b.x);

        x_max = max(x_max, lines[i].a.x);
        x_max = max(x_max, lines[i].b.x);

        y_min = min(y_min, lines[i].a.y);
        y_min = min(y_min, lines[i].b.y);
        
        y_max = max(y_max, lines[i].a.y);
        y_max = max(y_max, lines[i].b.y);
    }

    /*Scale points accordingly */
    double dx = x_max - x_min;
    double dy = y_max - y_min;

    for(int i = 0; lines[i].a.x != 0; i++)
    {
        lines[i].a.x = (lines[i].a.x - x_min) / dx * SCREEN_W;
        lines[i].a.y = (lines[i].a.y - y_min) / dy * SCREEN_H;
        lines[i].b.x = (lines[i].b.x - x_min) / dx * SCREEN_W;
        lines[i].b.y = (lines[i].b.y - y_min) / dy * SCREEN_H;
        al_draw_line(lines[i].a.x, lines[i].a.y, lines[i].b.x, lines[i].b.y, al_map_rgb(255,0,0), 3);
    }

}

