#include <stdio.h>

int main(void) {
    int *ptr = 6;
    *ptr = NULL;
    *ptr = 6;
    return 0;
}
