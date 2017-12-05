#include <thread>
#include <chrono>
#include "allegro5/allegro.h"
#include "allegro_wrapper.hpp"
#include "array_visualizer.hpp"

constexpr int data_size = 100;

int main(int argc, char** argv) {
    static_cast<void>(argc);
    static_cast<void>(argv);

    allegro::init();
    allegro::show_window(800, 600);

    array_visualizer<data_size> array(pos(50, 800));

    bool stop = false;
    std::thread th{[&](){
        for (size_t i=0; i<data_size; ++i) {
            for (size_t j=0; j<(data_size-i)-1; ++j) {
                if (array[j]>array[j+1]) {
                    int temp = array.at(j);
                    array.at(j) = array.at(j+1);
                    array.at(j+1) = temp;

                    std::this_thread::sleep_for(std::chrono::milliseconds(3));
                }
                if(stop) break;
            }
            if (stop) break;
        }
        array.set_rgb(0, 255, 0);
    }};

    while(allegro::check_exit()) {
        if(allegro::need_refresh()) {
            allegro::fill_with(0, 0, 0);
            array.draw();
        }
        allegro::internal_proc();
    }

    stop = true;
    th.join();
    return 1;
}
