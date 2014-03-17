#include "libft.h"

char*	ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		c;
	char				leng;
	char				*chaine;

	leng = ft_strlen(s) + 1;
	chaine = malloc(leng * sizeof(*chaine));
	c = 0;
	while (s[c] != '\0')
	{
		chaine[c] = f(c, s[c]);
		c++;
	}
	chaine[c] = '\0';
	return (chaine);
}
