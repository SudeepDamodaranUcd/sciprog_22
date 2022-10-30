#include <stdio.h>
#include <math.h>

//Global variable declaration.
float tan_arr[12];

//Function prototypes
float deg_to_rad(int deg);
float trap_rule(int N);

int main(void){

    //Variable declaration and initialisation
    int N=12, i;
    float area,deg,rad;

    //Calculate the value for tan() for each step value
    for (i = 0; i <= N; i++)
    {
        deg = i * 5.0;
        tan_arr[i]=tan(deg_to_rad(deg));
        printf("tan_arr[%d] = %f\n",i,tan_arr[i]);
    }
    
    //Area calculation by calling trapezoidal function
    area = trap_rule(N);

    printf("\nTrapezoidal result=%f, Exact value=%f\n",area,log(2.0));

    return(0);
}

//Function to convert degree to radian 
float deg_to_rad(int deg){
    return (M_PI * deg)/180.0;
}

//Function to calculate trapezoidal result 
float trap_rule(int N){
    float area;
    int i;
    //Calculate sum = tan(x0) + tan(xn)
    area=tan_arr[0]+tan_arr[N];

    //Calculate the area at points x1,x2...,x11 and add up
    for ( i = 1; i < N; i++)
    {
        area = area + 2*tan_arr[i];
    }
    
    //Multiply area by (b-a)/(2N), (pi/3)/(2*12)
    area= area * deg_to_rad(60.0-0.0)/(2*N);
    return area;
}