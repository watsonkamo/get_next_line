/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:38:35 by eshintan          #+#    #+#             */
/*   Updated: 2024/02/11 05:43:37 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*list;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read(fd, save);
	if (save == NULL)
		return (NULL);
	list = ft_outputline(save);
	if (list == NULL)
		return (NULL);
	save = ft_leftover(save);
	if (save == NULL && list[0] == '\0')
	{
		free(list);
		return (NULL);
	}
	return (list);
}

char	*ft_read(int fd, char *save)
{
	char	*tmp;
	int		read_rtn;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp == NULL)
		return (NULL);
	read_rtn = 1;
	while (!ft_strchr(save, '\n') && read_rtn != 0)
	{
		read_rtn = read(fd, tmp, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_rtn] = '\0';
		if (save == NULL)
			save = ft_strdup(tmp);
		else
			save = ft_strjoin(save, tmp);
	}
	free(tmp);
	return (save);
}

char	*ft_outputline(char *save)
{
	int		i;
	char	*rtn;

	i = 0;
	if (save == NULL)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	rtn = (char *)malloc(sizeof(char) * (i + 2));
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		rtn[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		rtn[i++] = '\n';
	rtn[i] = '\0';
	return (rtn);
}

char	*ft_leftover(char *save)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	if (save == NULL)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
		return (free(save), NULL);
	rtn = (char *)malloc(ft_strlen(save) - i + 1);
	if (rtn == NULL)
		return (NULL);
	i++;
	while (save[i])
	{
		rtn[j] = save[i];
		i++;
		j++;
	}
	rtn[j] = '\0';
	free(save);
	return (rtn);
}
