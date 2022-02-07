/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:50:48 by ayassin           #+#    #+#             */
/*   Updated: 2022/02/05 14:08:34 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Returns one line in the file discribtor "fd"
**malloc DANGER and possible memory leaks for buffer size > line size*/
char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	int			readsize;

	readsize = BUFFER_SIZE;
	if (!(BUFFER_SIZE >= 1 && read(fd, buff, 0) == 0))
		return (NULL);
	if (buff == NULL)
	{
		buff = (char *)malloc((readsize + 1) * sizeof(char));
		if (buff == NULL)
			return (NULL);
		buff[0] = 0;
	}
	buff[readsize] = 0;
	line = get_next_line_loop(&buff, readsize, fd);
	if (buff && *buff == 0)
	{
		free (buff);
		buff = NULL;
	}
	return (line);
}
