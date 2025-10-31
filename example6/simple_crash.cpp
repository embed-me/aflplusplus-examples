#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

using namespace std;

__AFL_FUZZ_INIT();

int main() {

    #ifdef __AFL_HAVE_MANUAL_CONTROL
        __AFL_INIT();
    #endif

    unsigned char *buf = __AFL_FUZZ_TESTCASE_BUF;

    while (__AFL_LOOP(10000))
    {
        int len = __AFL_FUZZ_TESTCASE_LEN;
        string str(reinterpret_cast<char*>(buf), static_cast<size_t>(len));

        if(str.length() < 12) {
            return 0;
        }

        const char *needle = "123deadbeef!";
        if (strcmp(str.c_str(), needle) == 0) {
            abort();
        }
    }
    
    return 0;
}