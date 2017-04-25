#include <stdio.h>

void base_up_left(int base) //prints base-up, left aligned triangle
{

    for (int i = base - 1; i >= 0; i--)
    {
        printf("*");

        for (int j = i; j > 0; j--)
        {
            printf("*");
            base--;
        }
        printf("\n");
    }

}

int main(void)
{
    int base;

    printf("how big is the base?\n");
    scanf("%d", &base);

    base_up_left(base);

    return 0;
}

