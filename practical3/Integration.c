#include <stdio.h>
#include <math.h>

int main(void){

    //Variable declaration and initialisation
    int N=12, i;
    float a=0.0, b_deg=60.0;
    float b_rad, area, mult_rad;

    //Convert degree to radians
    b_rad=(M_PI * b_deg)/180.0;

    //Calculate sum, tan(a) + tan(b_rad);
    area=tan(a)+tan(b_rad);

    //Calculating the area at points x1,x2,...,x11 by mutltiplying by 2
    //adding them together
    for (i = 5; i < 60; i=i+5)
    {
        area = area + 2*tan((M_PI*i)/180);
    }
    
    //Multiply partial area by (b-a)/2*N, (pi/3)/(2*12)
    //after converting it into radians
    mult_rad = (M_PI*((b_deg)/(2*N)))/180;
    area=mult_rad*area;

    //Print the result of the formula and summation for the comparison
    printf("Approximated value=%f, Exact value=%f\n",area,log(2.0));

    return(0);
}