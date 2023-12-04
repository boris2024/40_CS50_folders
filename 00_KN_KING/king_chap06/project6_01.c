#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*
20221122
Project 6.1, from "C programming, A Modern Approach" by K.N. King, second edition

This program finds the largest number from a set of float numbers entered by the user.
Enter zero or a negative number to stop the process and find the largest number entered so.
Arrays ARE used in this exercise.
*/

int main(void)
{
int n=100; float nmax=0;
float numbers[n];
int counter=0;

for(int i=0; i<n; i++)
{
    printf("\nWrite a number and then press ENTER\n");
    scanf("%f",&numbers[i] );
    counter++;
    if(numbers[i]<=0){  break;  }
}

printf("\n");


for(int k=0; k < counter-1; k++)
{
    if(nmax<numbers[k]) { nmax=numbers[k]; }
}

printf("\nnmax is = %0.2f\n", nmax);
}