#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int writefile(char* filename) {
    FILE *fp;
    fp  = fopen (filename, "w");
    fclose(fp);
}
int main(int argc, char **argv)
{
    char* new_root = argv[1];
    printf("Path: %s\n", new_root);
    
    chdir(new_root);
    int res = chroot(".");
    printf("%d\n", res);

    writefile("/data.txt");
    
    writefile("./data2.txt");
    
    return 0;
}