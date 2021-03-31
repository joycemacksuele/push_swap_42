
#include "../includes/libft.h"

int	get_next_line(int fd, char **line)
{
	static char		buf[MAX_FD][BUFFER_SIZE + 1];
	char			*adr;

	if (BUFFER_SIZE < 1 || fd < 0 || !line
		|| fd > MAX_FD || read(fd, buf[fd], 0) == -1)
		return (-1);
	*line = ft_strnew(0);
	adr = NULL;
	if (!*line)
		return (0);
	adr = ft_strchr(buf[fd], '\n');
	while (!adr)
	{
		if (!(join_newstr(line, buf[fd])))
			return (-1);
		ft_memset(buf[fd], 0, BUFFER_SIZE);
		if (!(read(fd, buf[fd], BUFFER_SIZE)))
			return (0);
		adr = ft_strchr(buf[fd], '\n');
	}
	*adr = 0;
	if (!(join_newstr(line, buf[fd])))
		return (-1);
	ft_strncpy(buf[fd], adr + 1, sizeof(buf[fd]));
	return (1);
}
