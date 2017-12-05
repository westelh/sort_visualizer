#ifndef ALLEGRO_WRAPPER_HPP
#define ALLEGRO_WRAPPER_HPP

namespace allegro {
	constexpr int fps_limit = 60;

	void init();
	void show_window(int width, int height);

	bool check_exit();
	bool need_refresh();

	void proc();
	void fill_with(int r, int g, int b);
}

#endif // ALLEGRO_WRAPPER_HPP
