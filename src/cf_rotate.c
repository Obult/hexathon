#include "hexlst.h"
#include "clusterfuck.h"

int		cf_rotate(t_HexTile **map, int orientation, int rotation)
{
	while (rotation < 0)
		rotation = rotation + 6;
	orientation = (orientation + rotation) % 6;
	cf_gravity_pull(map[orientation], orientation);
	return (orientation);
}