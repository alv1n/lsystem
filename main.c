#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "definitions.h"


int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        srand(atoi(argv[1]));
    }
    else
    {
        srand(time(NULL));
    }

    /*Initialise allegro*/
    al_init();
    al_init_primitives_addon();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    
    /*Anti-aliasing */
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

    /*Display to draw to*/
    ALLEGRO_DISPLAY *display = al_create_display(SCREEN_W, SCREEN_H);
    
    /*Creating queue for events, to handle input and closing window*/
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;

    /* Create a timer to refresh display */
    //ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_TIMER *timer = al_create_timer(1.0);

    al_register_event_source( queue, al_get_display_event_source(display));
    al_register_event_source( queue, al_get_keyboard_event_source());
    al_register_event_source( queue, al_get_timer_event_source(timer));

    lsystem *l = calloc(1, sizeof(lsystem) );
    init(l);

    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);
        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            goto exit; 
        }
        

        if(event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if(event.keyboard.keycode == ALLEGRO_KEY_E)
            {
                goto exit;
            }
        }
        if(event.type == ALLEGRO_EVENT_TIMER)
        {
            iterate(l);
            printf("%s\n-----\n", l->current);

            al_flip_display();
            al_clear_to_color(al_map_rgb(255,255,255));
            al_start_timer(timer);
        }
    }
exit:
    al_destroy_event_queue(queue);
    al_destroy_display(display);
    return 0;
}

