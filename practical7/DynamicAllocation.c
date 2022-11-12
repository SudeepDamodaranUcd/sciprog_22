#include <stdio.h>
#include <stdlib.h>

// Function to allocate array
int *allocateArray(int n){
    int *p;
    p=(int *) malloc((n)*sizeof(int));

    // Error handling
    if(p==NULL) {printf("Error in allocating the memory\n");}
    return p;
}

// Fill the array with ones
void fillWithOnes(int *array, int n){
    int i;
    for (i = 0; i < n; i++)
    {
        array[i]=1;
    }
}

// Print the array
void printArray(int *array, int n){
    int i;
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, array[i]);
    }
}

// Deallocate array
void freeArray(int *array){
    free(array);
}

int main(void){
    
    // Variable decalration
    int length, *a;
    
    printf("Please enter the size of the array:\n");
    scanf("%d", &length);

    a=allocateArray(length);
    fillWithOnes(a, length);
    printArray(a,length);
    freeArray(a);

    // Allocating null to array as a good coding practice
    a=NULL;
    return 0;
}