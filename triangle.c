#include <stdio.h>
int main()
{
    int i, space, input, k=0;

    printf("Enter the number of rows in the triangle: ");
    scanf("%d",&input);

    for(i=1; i<=input; i++, k=0)
    {
        for(space=1; space<=input-i; space++)
        {
            printf("  ");
        }

        while(k != 2*i-1)
        {
            printf("* ");
            k++;
        }

        printf("\n");
    }
    
    return 0;
}
