#include "types.h"
#include "user.h"

#define O_RDONLY 00

void head(int fd, int lc) {
    char buf[512];
    int i, fileRead, nlc = 0;

    while ((fileRead = read(fd, buf, sizeof buf)) > 0) {
        for (i = 0; i <= fileRead; i++) {
            if (buf[i] == '\n')
                ++nlc;
            
            if (nlc <= lc)
                printf(1, "%c", buf[i]);
        }
    }
}

int main(int argc, char *argv[]) {

    int fd; // file descriptor

    if (argc <= 1) {

        head(0, 10);
        exit();

    } else if (argc == 2) {

        if ((fd = open(argv[1], O_RDONLY)) < 0){
            head(0, atoi(++argv[1]));
            exit();
        } 

        head(fd, 10);
        close(fd);

    } else if(argc == 3) {

        if ((fd = open(argv[2], O_RDONLY)) < 0){
            printf(1, "Error 2");
            exit();
        }

        head(fd, atoi(++argv[1]));
        close(fd);
    } else {
        printf(1, "Too many args...");
        exit();
    }

    exit();
}
