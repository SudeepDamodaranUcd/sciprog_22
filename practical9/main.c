/* Main function to determine if a matrix is magic square*/
#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"

// Defining maximum size of the file name
#define MAX_FILE_NAME 100

// Function to find the number of lines in the input file
int get_num_lines(char filename[MAX_FILE_NAME]){
    //Variable declaration
    FILE *fp;
    char ch_read;
    int count=0;
    
    fp = fopen(filename,"r");

    // Read the file until end of file and count new lines (\n)
    while((ch_read=fgetc(fp))!=EOF){
        if(ch_read == '\n'){
            count++;
        }
    }
    printf("Number of lines is: %d\n", count);
    
    fclose(fp);
    return(count);
}

int main(void){

    // Variable declaration
    FILE *f;
    char filename[MAX_FILE_NAME];
    int n,i,j,flag;

    // Get file name from the user
    printf("Please enter the file name: ");
    scanf("%s", filename);

    // Get the number of lines
    n =get_num_lines(filename);
    f=fopen(filename, "r");

    // Allocate memory for the matrix
    int **magicSquare = malloc(n*sizeof(int *));
    for ( i = 0; i < n; i++)
    {
        magicSquare[i]=malloc(n*sizeof(int ));
    }
    
    // Read the file entries and create the fill the matrix
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            fscanf(f, "%d", &magicSquare[i][j]);
        }
    }
    
    // Call isMagicSquare function
    flag=isMagicSquare(magicSquare,n);

    if(flag==1){
        printf("This matrix is magic!\n");
    }
    else{
        printf("This matrix is not magic!\n");
    }

    // Free memory and close the input file
    for ( i = 0; i < n; i++)
    {
        free(magicSquare[i]);
    }
    free(magicSquare);
    fclose(f);

    return 0;
}