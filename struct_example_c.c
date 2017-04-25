#include <stdio.h>

struct student
{
    char last[15], first[15];
    int t1, t2, t3;
    float avg;
    char grade;
};

void load(struct student s[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("enter last name\n");
        gets(s[i].last);
        printf("enter first name");
        gets(s[i].first);
        printf("\nenter 3 scores");
        scanf("%d%d%d", &s[i].t1,&s[i].t2,&s[i].t3);
        s[i].avg = (s[i].t1 + s[i].t2 + s[i].t3) / (float)3;

        if (s[i].avg > 70)
            s[i].grade = 'P';
        else
            s[i].grade = 'F';
        fflush(stdin);
    }
}

int main(void)
{
    return 0;
}

