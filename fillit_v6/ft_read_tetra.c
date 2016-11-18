#include "fillit.h"

char				*ft_read_tetra(char	*files)
{
	int				fd;
	char			buf;
	char			*s;
	char			*tmp;
	size_t			index;
	s = ft_memalloc(527);
	ft_bzero(s, 527);
	index = 0;
	tmp = s;
	fd = open(files, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error();
		return (NULL);
	}
	while (read(fd, &buf, 1))
		*s++ = buf;
	if (close(fd) == -1)
	{
		ft_putstr("close() failed");
		return ((char *)-1);
	}
	if (ft_strlen(tmp) == 0)
		return ("error");
	if (ft_check_all(tmp))
		return ("error");
	return (tmp);
}
