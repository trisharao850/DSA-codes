//print lowercase alphabets using looops
#include <stdio.h>
int main(){
    int i;
    printf("print a to z: ");
    //asci value of a=97
    for (i=97;i<=122;i++)
    {
        printf("%c",i);
        if (i==123-1)
            printf(". \n");
        else
            printf(",");
    }
	return 0;
}
