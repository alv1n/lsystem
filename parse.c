#include "definitions.h"

void init(lsystem *l)
{ 
    /* Allocate memory */
    l->current  = calloc(STRING_SIZE, sizeof(char) );
    l->rules  = calloc(RULES_AMOUNT, sizeof(rule) );
    for(int i = 0; i < RULES_AMOUNT; i++)
    {
        l->rules[i].in = calloc(RULES_SIZE, sizeof(char) );
        l->rules[i].out = calloc(RULES_SIZE, sizeof(char) );
    }

    /*Import the rules */
    char *rules = calloc(MAX_STRING , sizeof(char) ); //Alloc for rules to parse 
    char *num = calloc(MAX_STRING , sizeof(char) ); //Alloc for number

    FILE *f;
    f = fopen("rules.txt", "r");
    fgets(l->current, STRING_SIZE, f);
    fgets(rules, MAX_STRING, f);
    fgets(num, MAX_STRING, f);
    l->angle = atof(num);

    rule *start= l->rules;
    for(int i = 0; rules[i] != '\0' && rules[i] != '\n'; i++)
    {
        switch(rules[i])
        {
            case '(':
                takeWhile(&rules[i+1], '>', l->rules->in);
                break;
            case '>':
                takeWhile(&rules[i+1], ')', l->rules->out);
                printf("%s,%s\n", l->rules->in, l->rules->out);
                (l->rules)++;
                break;
            default:
                break;
            *l->rules->in = '\0';
        }
    }
    l->rules = start;
}

void iterate(lsystem *l)
{
    static unsigned int string_size = STRING_SIZE;
    if(strlen(l->current) * 3 > string_size)
    {
        string_size *= 3;
    }
    
    char *new = calloc(string_size, sizeof(char) );
    char *start = new;
    
    for(char *cur = l->current; *cur != '\0'; cur++)
    {
        for(rule *cur_rule = l->rules; cur_rule->in != '\0'; cur_rule++)
        {
            if( *cur == cur_rule->in[0])
            {
                for(char *cur_out = cur_rule->out; *cur_out != '\0'; cur_out++)
                {
                    *new = *cur_out;
                    new++;
                }
            }
        }
    }
    l->current = realloc(l->current, string_size * sizeof(char) );
    memcpy(l->current, start, new - start);
}

void takeWhile(char *in, char end, char *out)
{
    while(*in != '\0' && *in != end)
    {
        *out = *in;
        out++;
        in++;
    }
    *out = '\0';
}
