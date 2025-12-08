/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:27:51 by oamkhou           #+#    #+#             */
/*   Updated: 2025/12/08 02:05:43 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 7777777
#endif

#ifndef GET_NEX_LINE_H
# define GET_NEX_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	len(char *str);
int	search(char *str, char c);
char	*join(char *s1, char *s2);
char	*extract_line(char *buffer);
void	update_buffer(char **buffer);
char	*get_next_line(int fd);

#endif