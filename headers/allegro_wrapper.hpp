#ifndef ALLEGRO_WRAPPER_HPP
#define ALLEGRO_WRAPPER_HPP

namespace allegro {
	constexpr int fps_limit = 60;

	void init();
	void show_window(int width, int height);

	bool check_exit();
	bool need_refresh();

	void internal_proc();
	void fill_with(unsigned char r, unsigned char g, unsigned char b);
}

#endif // ALLEGRO_WRAPPER_HPP
