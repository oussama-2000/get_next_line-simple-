#include "get_next_line_bonus.h"
int main()
{
    int fd = open("file.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);


    char *result;
    int i = 0;
    while((result =  get_next_line(0)))
    {
        printf("[%d] %s",i ,result);
        free(result);
        i++;
    }
    // while((result =  get_next_line(fd)))
    // {
    //     printf("%s",result);
    //     free(result);
    // }
    
}