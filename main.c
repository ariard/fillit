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
	i = 0;
	s = ft_read_tetra(argv[1]);
	tab = ft_generate(s);
	while (i < ft_count_tetra(s) - 1)
	{
		printf("tetra %c\nx1 : %d y1 : %d\nx2 : %d y2 : %d\nx3 : %d y3 : %d\nx4 : %d y4 : %d\n\n", (*tab[i]).print, (*tab[i]).shape[0].x, (*tab[i]).shape[0].y, (*tab[i]).shape[1].x, (*tab[i]).shape[1].y, (*tab[i]).shape[2].x, (*tab[i]).shape[2].y, (*tab[i]).shape[3].x, (*tab[i]).shape[3].y);
		i++;	
	}
	return (0);
}
