#include <string>
#include <vector>

#include "data_types.h"
#include "classes.h"


class Map{
	static std::string lvl0[5];

	bool valid = true;

	int _load_level(std::string r_lvl[]) {
		ObjectType ret[size.y][size.x];
		
		for (int y = 0; y < size.y; y++) {
			if (r_lvl[y].size() != size.x)
				return -1;

			for (int x = 0; x < size.x; x++) {
				data[y][x] = get_type_from_sprite(r_lvl[y][x]);
			}
		}

		return 0;
	}
	
	public:
		Vector2 size;
		std::vector<std::vector<ObjectType>> data;

		bool is_valid() { return valid; }

		Map(std::string r_lvl[] = lvl0){
			size.x = r_lvl[0].size();
			size.y = r_lvl->size();
			data.resize(
				size.y,
				std::vector<ObjectType>(size.x)
			);

			valid = _load_level(r_lvl) == 0;
		}
};


std::string Map::lvl0[5] = {
	"#####",
	"#   #",
	"#   #",
	"#   #",
	"#####"
};

