#include "hexlst.h"
#include "clusterfuck.h"
#include <stdio.h>

int		main(void)
{
	t_HexTile	**map;
	int			orientation;

	orientation = 0;
	map = malloc(sizeof(t_HexTile *) * 6);
	map[0] = create_hexagonal_map(2);
	map[1] = hl_find_tail(map[0], 2);
	map[2] = hl_find_tail(map[1], 3);
	map[3] = hl_find_tail(map[2], 4);
	map[4] = hl_find_tail(map[3], 5);
	map[5] = hl_find_tail(map[4], 0);


	map[0]->content = (void *)0xFFAAFF;

	orientation = cf_rotate(map, orientation, 4);

	hl_free_hexagonal(map[0], NULL);
	free(map);
	// system("leaks clusterfuck.exe");
	return (0);
}
