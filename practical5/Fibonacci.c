#include <stdio.h>
#include <stdlib.h>

//Input arguments: f(n-1) and f(n-2)
//On exit, they will have values f(n) and f(n-1)
void fibonacci(long *a, long *b);

int main(void) {

    //Variable declaration
    int n,i;
    long f0=0, f1=1;

    printf("Enter a positive integer n\n");
    scanf("%d",&n);

    //Exit if the input number is negative
    if (n<1){
        printf("Number is not postive\n");
        exit(1);
    }

    printf("The fibonacci series is: \n");
    printf("%ld, %ld, ",f0,f1);

    //Loop until n and find next fibonacci number
    for (i = 2; i <= n; i++)
    {
        fibonacci(&f1,&f0);
        printf("%ld, ",f1);
    }  

    return 0;
}

//Function next number in fibonacci series
void fibonacci(long *a, long *b){
    long next;
    //*a=f(n-1), *b=f(n-2) and next = f(n)
    next=*a + *b;

    //*a=f(n), *b=f(n-1)
    *b=*a;
    *a=next;
}