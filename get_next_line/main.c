
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("test2.txt", O_RDONLY);
    char *line;
    int i = 1;
    int s;
    while ((s = get_next_line(fd, &line)) > 0 )
    {
        printf("%d: %s\n",i, line);
        i++;
        free(line);
    }
	printf("%d: %s\n",i, line);
    printf("%d:\n", i);
    free(line);
    return 0;
}