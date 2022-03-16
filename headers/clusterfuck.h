#ifndef CLUSTERFUCK_H
# define CLUSTERFUCK_H

# include "hexlst.h"

void	cf_gravity_pull(t_HexTile *side, int orientation);
void	*cf_check_win(t_HexTile *head, int w_size);
int		cf_rotate(t_HexTile **map, int orientation, int rotation);

#endif