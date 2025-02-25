struct Vector2 {
	int x, y;
	
	Vector2() : x(0), y(0) {}

	Vector2(int p_x, int p_y) : x(p_x), y(p_y) {}

	Vector2(int p_n) : x(p_n), y(p_n) {}

	bool operator==(const Vector2 other) const {
		return x == other.x && y == other.y;
	}
};

