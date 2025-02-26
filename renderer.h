Vector2 get_cursor_pos() {
	printf("\033[6n");
	fflush(stdout);

	int x, y;
	int result = scanf("\033[%d;%dR", &y, &x);

	if (result != 2) {
		return Vector2(-1);
	}

	return Vector2(x, y);
}

void move_cursor(int p_xpos = 0, int p_ypos = 0) {
	printf("\033[%d;%dH", p_ypos, p_xpos);
}

void clear(bool p_from_cursor = false) {
	printf("\033[%dj", ((int)!p_from_cursor)*2);
}
