/* Tower of Hanoi puzzle game solution*/
#include <stdio.h>
#include <stdlib.h>

// Function to solve the hanoi puzzle
void hanoi(int n, int source, int destination, int interim){
    // Base case when n is 1
    if(n==1){
        printf("Move disc from %d to %d\n", source, destination);
    }
    // Recurse when n is not 1 using interim rod
    else{
        hanoi(n-1, source,interim, destination);
        printf("Move disc from %d to %d\n", source, destination);
        hanoi(n-1, interim, destination,source);
    }
}

int main(void){
    // Variable declaration
    int h=3;

    // Get the number of discs from the user
    printf("Please enter the number of discs: ");
    scanf("%d", &h);

    printf("Solution for %d discs:\n",h);
    hanoi(h,1,3,2);
    return 0;
}