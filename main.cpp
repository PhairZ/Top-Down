#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "map.h"
#include "renderer.h"



void fullscreen() {
	printf("\033[?1049h\033[?25l");

	struct termios newt;
	tcgetattr(STDIN_FILENO, &newt);
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}


void restore_terminal() {
	printf("\033[?1049l");

	struct termios oldt;
	tcgetattr(STDIN_FILENO, &oldt);
	oldt.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}


int main(int argc, char const *argv[]) {
	fullscreen();

	Map map = Map();
	if (!map.is_valid()) return 69;

	bool running = true;
	while (running) {
		for (int y = 0; y < map.data.size(); y++) {
			for (int x = 0; x < map.data[y].size()*2; x++) {
				move_cursor(x + 1, y + 1);

				if (x % 2 & 1) {
					printf(" ");
				} else {
					printf("%c", sprite_table[map.data[y][x/2]]);
				}
			}
			printf("\n");
		}

		char input;
		read(0, &input, 1);

		switch (input) {
			case 's':
			case 'S':
				printf("down");
				break;
			case 'Q':
				running = false;
				break;
			default:
				break;
		}
	}

	restore_terminal();
    return 0;
}
