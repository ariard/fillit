#include "fillit.h"
#include <stdio.h>

size_t		ft_count_tetra(char *s);

t_tetra		**ft_generate(char *s);



int			main(int argc, char **argv)
{
	size_t	i;
	char		*s;
	t_tetra		**tab;

	if (argc == 1)
		return (0);
	if (argc > 2)
		ft_putstr("error");
	i = 1;
	s = ft_read_tetra(argv[1]);
	tab = ft_generate(s);
	while (i < ft_count_tetra(s))
	{
		printf("x1 : %d y1 : %d x2 : %d y2 : %d x3 : %d y3 : %d x4 : %d y4 : %d\n", tab[0]->shape[0].x, tab[0]->shape[0].y, tab[0]->shape[1].x, tab[0]->shape[1].y, tab[0]->shape[2].x, tab[0]->shape[2].y, tab[0]->shape[3].x, tab[0]->shape[3].y);
		tab++;
		i++;	
	}
	return (0);
}
