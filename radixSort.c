#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateArray();
void display(int*, int);
int findBiggest(int*);
int getNumberOfRun();
void radixSort();

int main (int argc, char* argv[]) {
    int* array  = generateArray();
    display(array, 1000);
}

int* generateArray() {
    int* array = malloc(1000 * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
        array[i] = rand();
    }

    return array;
}

void display(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("\n");
}

int findBiggest()