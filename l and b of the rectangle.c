#include<stdio.h>

int main()
{
    float l,b,p;
    printf("Enter length and breadth of rectangle\n");
    scanf("%f%f",&l,&b);
    p=2*(l+b);
    printf("Perimeter of the rectangle is %0.2f\n",p);
    return 0;

}
