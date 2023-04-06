#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateArray(int);
void display(int*, int);
int findBiggest(int*, int);
int getNumberOfRun();
void radixSort();

int main (int argc, char* argv[]) {
    int size = 1000;
    int* array  = generateArray(size);
    display(array, 1000);
    printf("Biggest number is: %d\n", findBiggest(array, size)) ;
    printf("Number of run: %d\n", getNumberOfRun(array, size));
}

int* generateArray(int size) {
    int* array = malloc(size * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
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

int findBiggest(int* array, int size) {
    int biggest = array[0];
    for (int i = 0; i < size - 1; i++) {       
        if (array[i+1] > biggest) {
            biggest = array[i];
        }
    }

    return biggest;
}

int getNumberOfRun(int* array, int size) {
    int biggest = findBiggest(array, size);
    int run = 0;

    while (biggest != 0)
    {
        biggest = biggest/10;
        run++;
    }

    return run;
    
}

