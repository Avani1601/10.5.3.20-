#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for using malloc function

// Function for convolution
void convolution(const int *array1, int len1, const int *array2, int len2, int *result) {
    int lenResult = len1 + len2 - 1;
    for (int i = 0; i < lenResult; i++) {
        result[i] = 0;
    }
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            result[i + j] += array1[i] * array2[j];
        }
    }
}

// Function for calculating sum of an arithmetic progression
void sum_of_ap(int a, int d, int N) {

    // Generating the AP sequence
    int *x = (int*)malloc(N * sizeof(int)); // Dynamically allocate memory
    for (int i = 0; i < N; i++) {
        x[i] = a + i * d;
    }

    // Creating a sequence of 1s
    int *u = (int*)malloc(N * sizeof(int)); // Dynamically allocate memory
    for (int i = 0; i < N; i++) {
        u[i] = 1;
    }
 
    // Performing convolution
    int *result = (int*)malloc((N + N - 1) * sizeof(int)); // Dynamically allocate memory
    convolution(x, N, u, N, result);
    
    // Writing results to a file (theory.dat)
    FILE *file = fopen("theory.dat", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    for (int i = 0; i < N ; i++) {
        fprintf(file, "%d\n", result[i]);
    }
    fclose(file);

    // Free dynamically allocated memory
    free(x);
    free(u);
    free(result);
}

int main() {
    // Analysis code
    int startingPoint = 5;  // Distance from the bucket to the first potato
    int spacing = 3;        // Spacing between potatoes
    int numPotatoes = 10;   // Number of potatoes

    // Computing the sum of the distances
    sum_of_ap(startingPoint, spacing, numPotatoes);

    // Simulation code
    int totalDistance = 0;
    FILE *simulatedFile = fopen("simulated.dat", "w");
    if (simulatedFile == NULL) {
        printf("Error opening simulated file.\n");
        return 1;
    }
    for (int i = 0; i < numPotatoes; i++) {
        totalDistance += startingPoint + i * spacing;
        fprintf(simulatedFile, "%d\n", totalDistance); // Writing each distance to file
    }
    fclose(simulatedFile);

    return 0;
}

