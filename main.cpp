#include <iostream>


struct Vector2 {
    int x, y;

    Vector2(int p_x = 0, int p_y = 0) {
        x = p_x, y = p_y;
    }
};


enum ObjectType {
    NONE,
    PLAYER,
    WALL,
    COIN,
};


struct GameObject {
    Vector2 position;
    ObjectType type;

    GameObject(Vector2 p_pos = Vector2(), ObjectType p_type = NONE) {
        position = p_pos;
        type = p_type;
    }
};


int32_t main(int argc, char const *argv[])
{
    GameObject test_object = GameObject(Vector2(6, 9), PLAYER);
    printf("%d", test_object.position.x);

    return 0;
}
