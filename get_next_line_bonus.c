/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:54:46 by ayassin           #+#    #+#             */
/*   Updated: 2022/02/07 08:23:41 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Returns one line in the file discribtor "fd"
**malloc DANGER and possible memory leaks for buffer size > line size*/
char	*get_next_line(int fd)
{
	static	char	*(buff[257]);
	char			*line;
	int				readsize;

	readsize = BUFFER_SIZE;
	if (!(BUFFER_SIZE >= 1 && fd < 257 && read(fd, buff[fd], 0) == 0))
		return (NULL);
	if (buff[fd] == NULL)
	{
		buff[fd] = (char *)malloc((readsize + 1) * sizeof(char));
		if (buff[fd] == NULL)
			return (NULL);
		buff[fd][0] = 0;
	}
	buff[fd][readsize] = 0;
	line = get_next_line_loop(&(buff[fd]), readsize, fd);
	if (buff[fd] && *(buff[fd]) == 0)
	{
		free (buff[fd]);
		buff[fd] = NULL;
	}
	return (line);
}
