/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 13:37:47 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/12/02 15:02:22 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_neg(char	*buff, char	*temp, int n)
{
	free(buff);
	if (temp)
		free(temp);
	return (n);
}

static int	ft_search(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strrealloc(char *str, int size)
{
	char		*newstr;
	int			leng;

	leng = ft_strlen(str);
	newstr = ft_strnew(sizeof(char) * (leng + size + 1));
	if (str != 0)
	{
		ft_strcpy(newstr, str);
		free(str);
	}
	return (newstr);
}

static char	*ft_good_guy_strchr(const char *str, char c)
{
	if (str == 0)
		return (0);
	return (ft_strchr(str, c));
}

int			get_next_line(int const fd, char **line)
{
	static char	*buffer = NULL;
	char		*temp;
	int			i;
	int			c;

	if (line == 0)
		return (-1);
	c = 42;
	temp = ft_strnew(BUFF_SIZE);
	while (ft_good_guy_strchr(buffer, '\n') == 0 && c != 0)
	{
		if ((c = read(fd, temp, BUFF_SIZE)) < 0)
			return (ft_neg(buffer, temp, -1));
		buffer = ft_strrealloc(buffer, BUFF_SIZE);
		ft_strcat(buffer, temp);
	}
	free(temp);
	i = ft_search(buffer);
	if (*buffer == 0)
		return (ft_neg(buffer, 0, 0));
	*line = ft_strsub(buffer, 0, i);
	temp = ft_strsub(buffer, i + 1, ft_strlen(buffer + i + 1));
	free(buffer);
	buffer = temp;
	return (1);
}
