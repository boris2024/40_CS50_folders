#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/*
20221130 exercise 8.2.6, page pdf 177 from KN Kings "C programming, a modern approach"
*/
int main(void)
{
    const int segments[10][7]=
    {   {1,1,1,1,1,1,0},    // this is 0
        {0,1,1,0,0,0,0},    // this is 1
        {1,1,0,1,1,0,1},    // this is 2
        {1,1,1,1,0,0,1},    // this is 3
        {0,1,1,0,0,1,1},    // this is 4
        {1,0,1,1,0,1,1},    // this is 5
        {1,0,1,1,1,1,1},    // this is 6
        {1,1,1,0,0,0,0},    // this is 7
        {1,1,1,1,1,1,1},    // this is 8
        {1,1,1,1,0,1,1}     // this is 9
    };
}