#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void f()
{
    system("leaks a.out");
}
int main()
{
    atexit(f);
    int fd_i = open("file.txt", O_RDONLY);
    int fd_o = open("output.txt", O_RDWR);


    char *result;
    
    while((result =  get_next_line(fd_i)))
    {
        write(fd_o,result,len(result));
        // printf("%s", result);
        free(result);
    }

}