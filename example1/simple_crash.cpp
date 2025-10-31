#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
    string str;

    cout << "enter input string: ";
    getline(cin, str);

    if(str.length() < 4) {
        return 0;
    }

    if (str[0] == 'd') {
        if (str[1] == 'e') {
            if (str[2] == 'a') {
                if (str[3] == 'd') {
                    abort();
                }
            }
        }
    }

    return 0;
}