#include <stdio.h>   //Для puts
#include <unistd.h>   //Для alarm
#include <signal.h>   //Для signal
long int *ptr;

int method()
{
    // Define a variable local in this method 
    int local = 100;

    // Set address of local variable (name of variable is local) 
    // in the ptr pointer
    ptr = &local;

    return -1;
}

int main()
{
    // Call method
    method();   

    // Print value of ptr pointer
    printf("%d\n", *ptr);

    return -1;
}