#include<stdio.h>
int main()
{
    int i;
    char alphabet=97;
    for(i=1;i<=26;i++)
    {
        printf("%c ",alphabet);
        alphabet=alphabet+1;
    }
  return 0;
}
