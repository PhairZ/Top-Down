#include <iostream>

#include "map.h"
#include "renderer.h"


int32_t main(int argc, char const *argv[]) {
	Vector2 origin = get_cursor_pos();
	if (origin == Vector2(-1)) return 70;

	Map map = Map();
	if (!map.is_valid()) return 69;

	char input;
	while (true) {
		for (int y = 0; y < map.data.size(); y++) {
			for (int x = 0; x < map.data[y].size(); x++) {
				move_cursor(x + origin.x, y + origin.y);
				printf("%c", sprite_table[map.data[y][x]]);
			}
			printf("\n");
		}
	}
	
    return 0;
}
