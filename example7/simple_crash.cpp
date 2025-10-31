#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

using namespace std;
static constexpr uint MAX_BUF_SIZE = 15;

int main(int argc, char *argv[]) {
    char buf[MAX_BUF_SIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        return 1;
    }

    if (fgets(buf, MAX_BUF_SIZE, file) == NULL) {
        if (!feof(file)) 
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    if (buf[0] == 'd') {
        if (buf[1] == 'e') {
            if (buf[2] == 'a') {
                if (buf[3] == 'd') {
                    abort();
                }
            }
        }
    }
    
    return 0;
}