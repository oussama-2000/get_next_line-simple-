#include "get_next_line.h"

char  *get_next_line(int fd)
{
    static char *buffer;
    char *str_read;
    int bytes;
    char *line;

    bytes = 0;
    while (!search(buffer, '\n'))
    {
        str_read = malloc(BUFFER_SIZE + 1);
        if (!str_read)
            return (NULL);
        bytes = read(fd, str_read, 1);

        if (bytes <= 0)
        {
            free(str_read);
            return (NULL);
        }
        str_read[bytes] = '\0';
        buffer = join(buffer, str_read);
    }
    line = extract_line(buffer);
    update_buffer(&buffer);
    return (line);
}
int main()
{
    int fd = open("file.txt", O_RDONLY);
    // char *result = get_next_line(fd);
    // printf("%s",result);
    // result = get_next_line(fd);
    // printf("%s", result);
    // result = get_next_line(fd);
    // printf("%s", result);
    char *result;
    while((result =  get_next_line(fd)))
    {
        printf("%s",result);
    }
}