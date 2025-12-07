/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:47:23 by oamkhou           #+#    #+#             */
/*   Updated: 2025/12/07 23:36:52 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int len(char *str)
{
    int len;

    len = 0;
    if(!str)
        return (0);
    while(str[len] != '\0')
    {
        len++;
    }
    return (len);
}
int search(char *str, char c)
{
    int i;

    i = 0;
    if(!str)
        return (0);
    while(str[i] != '\0')
    {
        if(str[i] == c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
char    *join(char *s1, char *s2)
{
    char *result;
    int i;
    int j;


    i = 0;
    j = 0;
    if(!s1)
        s1 = s2;
    result = malloc(len(s1)+len(s2) + 1);
    if(!result)
        return (NULL);
    while(s1[i] != '\0')
    {
        result[i] = s1[i];
        i++;
    }
    while(s2[j] != '\0')
    {
        result[i] = s2[j];
        i++;
        j++;
    }
    result[i]='\0';
    return (result);
}

char *extract_line(char *buffer)
{
    int i;
    char *line;

    i = 0;
    if (!buffer || buffer[0] == '\0')
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = malloc(i + (buffer[i] == '\n') + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
        line[i] = '\n';
    line[i + 1] = '\0';
    return (line);
}

void    update_buffer(char **buffer)
{
    char *new_buffer;
    int i;
    int j;

    i = 0;
    while((*buffer)[i] && (*buffer)[i] != '\n')
        i++;
    if(!(*buffer)[i])
    {
        free(*buffer);
        *buffer = NULL;
        return ;
    }
    new_buffer = malloc(len(*buffer) - i + 1);
    if(!new_buffer)
        return ;
    i++;
    j = 0;
    while((*buffer)[i])
    {
        new_buffer[j++] = (*buffer)[i++];
    }
    new_buffer[j]= '\0';
    free(*buffer);
    *buffer = new_buffer;
}

// int main()
// {
//     char s1[]="hello\nw ";
//     char s2[]=" world";
    
//     char *line= extract_line(s1);
//     printf("%s",line);
//     printf("hello\n");
// }