/* Find e using Taylor expansion*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Function prototype for factorial
int factorial(int n);

int main(void) {

    //Variable decalration
    int i, order;
    double e, *terms;

    // Accpet information from user
    printf("Please enter the required polynomial order\n");
    if(scanf("%d",&order)!=1){
        printf("Entered more than one number!");
        return 1;
    }

    //Allocate space for terms array using user input
    terms = malloc(order*sizeof(double));
    for (i = 0; i < order; i++)
    {
        terms[i]=1.0/(double)factorial(i+1);
        printf("e term for order %d is %1.14lf\n", order, terms[i]);
    }
    
    // Find f(x) = 1 + x + x^2/2! + ..
    e=1.0;
    for (i = 0; i < order; i++)
    {
        e=e+terms[i];
    }

    // Free memeory allocation
    free(terms);

    printf("\ne is estimated as %.14lf, with difference %.14lf", e, e-exp(1.0));
    
    return 0;
}

// Function to find the factorial of an input number
int factorial(int n){
    if (n<0){
        printf("Error: Number should be postive\n");
        return(-1);
    }
    else if(n==0){
        return(1);
    }
    else{
        return (n*factorial(n-1));
    }
}