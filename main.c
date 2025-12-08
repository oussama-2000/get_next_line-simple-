#include "get_next_line.h"
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
        free(result);
    }
}