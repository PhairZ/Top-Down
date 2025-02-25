enum ObjectType {
    NONE,
    PLAYER,
    WALL,
    COIN,
};

static const char sprite_table[] = {' ', 'X', '#', '0'};
static ObjectType get_type_from_sprite(char p_c) {
	for (int i = 0; i < sizeof(sprite_table); i++) {
		if (sprite_table[i] == p_c) return (ObjectType)i;
	}

	return NONE;
}

class GameObject {
	public:
		Vector2 position;
		ObjectType type;
		
		GameObject(Vector2 p_pos = Vector2(), ObjectType p_type = NONE) {
			position = p_pos;
			type = p_type;
		}
};

