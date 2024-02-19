#include <stdio.h>

#define SIZE 11 // Size of the sequence, from 0 to 10

int main() {
    FILE *fp;
    fp = fopen("values.dat", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    for (n = 0; n <= 10; n++) {
        int y = 3 * n * n + 13 * n + 10;
        fprintf(fp, "%d\n", y);
    }

    fclose(fp);
    return 0;
}

