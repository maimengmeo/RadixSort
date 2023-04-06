#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node_def {
    int number;
    struct node_def *next;
} Node;

typedef struct {
    int nodeCount;
    Node *head;
    Node *tail;
}Queue;

int* generateArray(int);
void display(int*, int);
int findBiggest(int*, int);
int getNumberOfRun();
void radixSort(int*, int);

void enqueue(Queue*, int);
int dequeue(Queue*);
void printQueue(Queue*);
void initQueue(Queue*);
static Node* createNewNode(int);



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

void radixSort(int* array, int size) {

}

static Node* createNewNode(int num) {
    Node *newNode = malloc(sizeof(Node));
    assert(newNode);
    newNode->number = num;
    newNode->next = NULL;

    return newNode;
}

void enqueue(Queue *queue, int num) {

    Node *newNode = createNewNode(num);
    if(queue->head == NULL) {
        queue->head = queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->nodeCount++;


} 

int dequeue(Queue * queue) {
    Node *temp;

    int num = -99999; //rogue number
    
    if(queue->head != NULL) {
        //delete the head
        temp = queue->head;
        num = queue->head->number;
        queue->head == queue->head->next;
        queue->nodeCount--;
        free(temp);
    } else {
        //empty queue - does nothing
        printf("empty queue\n");
    }

    return num;
}

void initQueue(Queue *queue) {
    queue->nodeCount = 0; 
    queue->head = NULL; 
    queue->tail = NULL;
}

void printQueue(Queue *queue) {
    Node *current = queue->head;

    if (queue->head == NULL) {
        printf("empty queue\n");
    }
    else{
        for (int i = 0; i < queue->nodeCount; i++) {
            printf("%d", current->number);
            current = current ->next;
        }
        printf("\n");
    }
}
