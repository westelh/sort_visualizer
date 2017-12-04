#include "allegro5/allegro.h"

int main(int argc, char** argv) {
    static_cast<void>(argc);
    static_cast<void>(argv);

    al_init();
    auto display = al_create_display(800, 600);
    auto event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.06);
    ALLEGRO_EVENT ev;
    while(true) {
        bool got_event = al_wait_for_event_until(event_queue, &ev, &timeout);
        if(got_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
    }

    return 1;
}
