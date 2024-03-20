#include<stdio.h>
#include<math.h>

int main()
{
    float x1,x2,y1,y2,distance;
    printf("Enter x1,x2,y1,y2\n");
    scanf("%f%f%f%f",&x1,&x2,&y1,&y2);
    distance = sqrt((pow((x2-x1),2))+(pow((y2-y1),2)));
    printf("Distance between two points is %0.2f",distance);
    return 0;

}
