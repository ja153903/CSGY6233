#include "types.h"
#include "stat.h"
#include "user.h"

char buf[1024];

void tail(char* filepath, int fd, int lc) {
    int i, fileRead, nlc = 0;
    
    char* temp_buf;
    temp_buf = (char*) malloc(500000);
    int temp_buf_size = 0;
    
    while ((fileRead = read(fd, buf, sizeof buf)) > 0) {
        for (i = 0; i < fileRead; i++) {
            temp_buf[temp_buf_size++] = (char)buf[i];
            if (buf[i] == '\n')
                ++nlc;
        }
    }
   
    int nnlc = 1;

    for (i = 0; i < temp_buf_size; i++) {
        if (temp_buf[i] == '\n')
            ++nnlc;
        if (nnlc >= nlc - lc + 1) {
            printf(1, "%c", temp_buf[i]);
        }
    }
    
    free(temp_buf);
}

int main(int argc, char *argv[]) {

    int fd;
    
    if (argc == 1) {
        tail("", 0, 10);
        exit();
    } else if (argc == 2) {
        if ((fd = open(argv[1], 00)) < 0) {
            tail("", 0, atoi(++argv[1]));
            exit();
        }
        tail(argv[1], fd, 10);
        close(fd);
    } else if (argc == 3) {
        if ((fd = open(argv[2], 00)) < 0) {
            printf(1, "Error...");
            exit();
        }
        tail(argv[2], fd, atoi(++argv[1]));
        close(fd);
    } else {
        printf(1, "too many args...");
        exit();
    }

    exit();
}
    

    
    
     
 
