#include "hexlst.h"

void	*cf_check_win_lane(t_HexTile *start, int direction, int w_size)
{
	int		counter;

	counter = 1;
	while (start != NULL)
	{
		if (start->neighbour[direction] == NULL)
			return (NULL);
		if (start->content == start->neighbour[direction]->content && start->content != NULL)
			counter++;
		else
			counter = 1;
		if (counter == w_size)
			return (start->content);
		start = start->neighbour[direction];
	}
	return (NULL);
}

void	*cf_check_win(t_HexTile *head, int w_size)
{
	t_HexTile	*h_cpy;
	void		*tmp;

	h_cpy = head;
	if (cf_check_win_lane(head, 3, w_size))
		return (cf_check_win_lane(head, 3, w_size));
	while (h_cpy->neighbour[2])
	{
		h_cpy = h_cpy->neighbour[2];
		tmp = cf_check_win_lane(h_cpy, 3, w_size);
		if (tmp)
			return (tmp);
	}
	while (head->neighbour[4])
	{
		head = head->neighbour[4];
		tmp = cf_check_win_lane(head, 3, w_size);
		if (tmp)
			return (tmp);
	}
	return (NULL);
}