#include "definitions.h"
#include "draw.h"


void convert(lsystem *l, line *lines)
{
    /*Starting state */
    state s;
    s.angle = l->angle;
    s.current.x = 0;
    s.current.y = 0;

    /* Stack to push changes onto */
    state *stack = calloc(STACK_SIZE, sizeof(state) );

    for(char *c = l->current; c != '\0'; c++)
    {
        if( *c >= 'A' && *c <= 'Z')
        {
            lines->a.x = s.current.x;
            lines->a.y = s.current.y;

            s.current.x += cos(s.angle);
            s.current.y += sin(s.angle);

            lines->b.x = s.current.x;
            lines->b.y = s.current.y;
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
            memcpy(stack, s, sizeof(state) );
            stack++;
        }
        else if (*c == ']')
        {
            stack--;
            memcpy(s, state, sizeof(state) );
        }

    }
}


