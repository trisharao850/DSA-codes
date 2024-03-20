#include<stdio.h>
  int main()
  {
      int marks1,marks2,marks3,total_marks;
      float average_marks;
      printf("Enter marks of 3 subjects\n");
      scanf("%d%d%d",&marks1,&marks2,&marks3);
      total_marks=marks1+marks2+marks3;
      average_marks=(float)total_marks/3;
      printf("Total marks is %d\n",total_marks);
      printf("Average_marks is %0.2f\n",average_marks);
      return 0;
  }
