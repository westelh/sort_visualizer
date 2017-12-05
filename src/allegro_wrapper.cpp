#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro_wrapper.hpp"

namespace {
	ALLEGRO_EVENT ev;
	ALLEGRO_DISPLAY* display = nullptr;
	ALLEGRO_EVENT_QUEUE* event_queue = nullptr;
	ALLEGRO_TIMER* timer = nullptr;
}

void allegro::init() {
	al_init();
    al_init_primitives_addon();

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0/fps_limit);
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
}

void allegro::show_window(int width, int height) {
	if (display == nullptr) display = al_create_display(width, height);
    al_register_event_source(event_queue, al_get_display_event_source(display));
	al_start_timer(timer);
}

bool allegro::check_exit() {
	al_wait_for_event(event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) return false;
	else return true;
}

bool allegro::need_refresh() {
	if (ev.type == ALLEGRO_EVENT_TIMER) return true;
	else return false;
}

void allegro::fill_with(unsigned char r, unsigned char g, unsigned char b) {
	al_clear_to_color(al_map_rgb(r, g, b));
}

void allegro::internal_proc() {
	al_flip_display();
}


