#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>      /* Definition of SYS_* constants */
#include <errno.h>


void logText(char* text){
    printf(text);
}

int pivot_root(const char *new_root, const char *put_old) {
    int opresult = syscall(SYS_pivot_root,  *new_root, *put_old);
    if (opresult != 0) {
        printf("%d\n",errno);
        printf(strerror(errno));
    }
    return opresult;
}

int writefile(char* filename) {
    FILE *fp;
    fp  = fopen (filename, "w");
    fclose(fp);
}

int main(int argc, char **argv) {
    char* new_root = argv[1];
    
    printf("Path: %s\n", new_root);
    
    pivot_root(new_root,new_root);
    logText("Pivot done\n");
    
    writefile("/data.txt");
    writefile("./data2.txt");
    logText("End\n");
}