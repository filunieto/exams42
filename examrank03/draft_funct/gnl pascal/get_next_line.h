/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:36:52 by fnieves-          #+#    #+#             */
/*   Updated: 2022/11/03 10:58:15 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>


# include <stdlib.h>
# include <unistd.h>

//#include <stdlib.h> and <unistd.h> for *malloc(), free(), & read()*.

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);



#endif
