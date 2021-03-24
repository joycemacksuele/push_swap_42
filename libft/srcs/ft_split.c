
#include "../includes/libft.h"

int	split_counter(char const *s, char c)
{
	char	*spliter;
	int		i;

	i = 0;
	while (s && *s)
	{
		spliter = ft_strchr(s, c);
		if ((spliter - s) != 0)
			i++;
		if (spliter)
			s = spliter + 1;
		else
			s = NULL;
	}
	return (i + 1);
}

static char const	*ternarie_ret(char const *s, char *adr)
{
	if (adr)
		s = adr + 1;
	else
		s = NULL;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*adr;
	int		i;

	tab = (char **)malloc(sizeof(*tab) * split_counter(s, c));
	if (!tab)
		return (NULL);
	i = 0;
	while (s && *s)
	{
		adr = ft_strchr(s, c);
		if ((adr - s) != 0)
		{
			if (adr)
				tab[i] = ft_substr(s, 0, adr - s);
			else
				tab[i] = ft_substr(s, 0, ft_strlen(s));
			if (!tab[i++])
				return (ft_freetab(tab));
		}
		s = ternarie_ret(s, adr);
	}
	tab[i] = NULL;
	return (tab);
}
