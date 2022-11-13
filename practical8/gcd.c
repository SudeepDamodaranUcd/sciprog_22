/* 
* Iterative and recursive versions of Euclid's algorithm
*/

#include <stdio.h>

// Function decalrations
int iterativeGCD(int a, int b);
int recursiveGCD(int a, int b);

int main(void){
    
    // Variable declarations
    int a, b;

    // Take user input and validate it
    printf("Please input two positive integers:\n");
    if(scanf("%d %d",&a,&b)!=2){
        printf("Please enter only two integers!\n");
        return 1;
    }

    // Check if numbers are positive
    if (a<=0 || b <=0){
        printf("Numbers are not positive!\n");
        return 1;
    }

    // Call functions
    printf("IterativeGCD(%d,%d) = %d\n", a,b, iterativeGCD(a,b));
    printf("RecursiveGCD(%d,%d) = %d\n", a,b, recursiveGCD(a,b));

    return 0;
}

// Function to find the GCD using iterative method
int iterativeGCD(int a, int b){
    int temp;
    while (b != 0){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

//Function to find the GCD using recursive method
int recursiveGCD(int a, int b){
    if (b==0){
        return a;
    }
    else{
        return recursiveGCD(b, a%b);
    } 
}
