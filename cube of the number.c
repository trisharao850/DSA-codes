#include<stdio.h>
#include<math.h>

int main()
{
    int number,cube;
    printf("Enter a number\n");
    scanf("%d",&number);
    cube=pow(number,3);
    printf("Cube of the given number is %d",cube);
    return 0;
}
