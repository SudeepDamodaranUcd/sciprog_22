#include <stdio.h>
#include <math.h>

//Function prototypes
double arctanh1(const double x, const double delta);
double arctanh2(const double x);

int main(void) {

    //Variable declaration 
    double delta, x;

    printf("Enter the precision for Maclaurin series\n");
    scanf("%lf",&delta);

    int length=1000;
    double tan1[length]; //Store the result of arctanh1 for each x
    double tan2[length]; //Store the result of arctanh2 for each x

    int j=0; //array length
    x=-0.9;

    while (x<=0.9 && j <length)
    {
        tan1[j]=arctanh1(x,delta);
        tan2[j]=arctanh2(x);
        printf("The difference at x=%lf between them is %.10lf\n",x,fabs(tan1[j]-tan2[j]));
        j++;
        x=x+.1;
    }

    return 0;
}

double arctanh1(const double x, const double delta){
    double arcTan=0; //approximated result
    double elem, val;
    int n =0; //sum parameter

    //loop until element in the series is greater than delta
    do{
        val = 2*n+1;
        elem=pow(x,val)/val;
        arcTan += elem;
        n++;
    } while(fabs(elem)>=delta);

    return arcTan;
}

//Function to calculate the arctanh using natural logarithm
double arctanh2(const double x){
    return((log(1+x)-log(1-x))/2);
}