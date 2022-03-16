#include "hexlst.h"

// which direction to pull from
void	cf_pull_lane(t_HexTile *start, int direction)
{
	t_HexTile	*tmp;

	tmp = start;
	if (start == NULL)
		return ;
	if (start->content == NULL)
	{
		while (tmp->neighbour[direction])
		{
			if (tmp->neighbour[direction]->content != NULL)
			{
				start->content = tmp->neighbour[direction]->content;
				tmp->neighbour[direction]->content = NULL;
				break ;
			}
			tmp = tmp->neighbour[direction];
		}
	}
	cf_pull_lane(start->neighbour[direction], direction);
}

void	cf_gravity_pull(t_HexTile *side, int orientation)
{
	t_HexTile	*h_cpy;
	int			left = (2 + orientation) % 6;
	int			right = (4 + orientation) % 6;
	int			direction = (3 + orientation) % 6;

	h_cpy = side;
	cf_pull_lane(side, direction);
	while (h_cpy->neighbour[left])
	{
		h_cpy = h_cpy->neighbour[left];
		cf_pull_lane(h_cpy, direction);
	}
	while (side->neighbour[right])
	{
		side = side->neighbour[right];
		cf_pull_lane(side, direction);
	}
}