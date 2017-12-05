#include "allegro5/allegro.h"
#include "allegro_wrapper.hpp"
#include "line.hpp"

int main(int argc, char** argv) {
    static_cast<void>(argc);
    static_cast<void>(argv);

    allegro::init();
    allegro::show_window(800, 600);

    shape* s = new line{};
    while(allegro::check_exit()) {
        if(allegro::need_refresh()) {
            allegro::fill_with(0, 0, 0);
            s->draw();
            s->set_angle(s->get_angle()+0.05);
        }
        allegro::proc();
    }

    delete s;

    return 1;
}
