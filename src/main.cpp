#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "line.hpp"

int main(int argc, char** argv) {
    static_cast<void>(argc);
    static_cast<void>(argv);

    al_init();
    al_init_primitives_addon();
    auto display = al_create_display(800, 600);
    auto event_queue = al_create_event_queue();
    
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.06);
    ALLEGRO_EVENT ev;

    auto* timer = al_create_timer(1.0 / 60);

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_start_timer(timer);
    shape* s = new line{};
    while(true) {
        al_clear_to_color(al_map_rgb(0,0,0));
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
        if(ev.type == ALLEGRO_EVENT_TIMER) {
            s->draw();
            s->set_angle(s->get_angle()+0.05);
        }

        al_flip_display();
    }

    delete s;

    return 1;
}
