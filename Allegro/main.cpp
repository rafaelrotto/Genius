#include <allegro.h>

void init();
void deinit();

int main() {
	//inicialização
	allegro_init();
	install_timer();
	install_keyboard();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	set_window_title("Genius");
	
	
	
	//variaáveis
	
	int x = 100, y = 100;
	
	while(!key[KEY_ESC])
		if(key[KEY_RIGHT]) x += 1;
		if(key[KEY_LEFT]) x -= 1;
		if(key[KEY_UP])  y -= 1;
		if(key[KEY_DOWN]) y += 1;
		
		circlefill(screen, x, y, 100, makecol(255,245,200));
		rest(10);
		
		clear(screen);
	return 0;
}
END_OF_MAIN()

