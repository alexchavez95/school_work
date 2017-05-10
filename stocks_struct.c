#include <stdio.h>
#define SIZE 2 //size=2 or 3 for testing
/*
 * User inputs stock transaction data n times and
 * the data is sorted by highest to lowest net total.
 * Data is printed and written to/read from a text file
 * and the same for a binary file (for practice purposes).
*/


//holds data for stock name, buying/selling prices, buying total cost
//and selling total earnings, and profit or loss
struct stock
{
    char name[15];
    float shares, buyPrice, nowPrice, buyCost, nowValue, profit;
};

//gets stock data from user
void getData(struct stock s[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("enter stock name\n");
        scanf("%s", &s[i].name);
        printf("\nenter number of shares\n");
        scanf("%f", &s[i].shares);
        printf("enter buy price and current price\n");
        scanf("%f%f", &s[i].buyPrice, &s[i].nowPrice);
        s[i].buyCost = s[i].shares * s[i].buyPrice;
        s[i].nowValue = s[i].shares * s[i].nowPrice;
        s[i].profit = s[i].nowValue - s[i].buyCost;

        fflush(stdin);
    }
}

//prints all stock and transaction data
void printStocks(struct stock s[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("name: %s\n", s[i].name);
        printf("buying price: %.2f, current price: %.2f, buying cost: "
               "%.2f, and current value: %.2f\n", s[i].buyPrice,
               s[i].nowPrice, s[i].buyCost, s[i].nowValue);
        printf("profit %.2f\n\n", s[i].profit);
    }
}

//sorts stocks by profit from least to greatest
void sort(struct stock s[], int n)
{
    int i, j;
    struct stock t;

    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-1; j++)
        {
            if (s[j].profit < s[j+1].profit)
            {
                t = s[j];
                s[j] = s[j+1];
                s[j+1] = t;
            }
        }
    }
    printf("\nList of highest to lowest profit:\n");
}

//counts how many stocks gained, lost, or broke even
void netChange(struct stock s[], int n)
{
    int i;
    int gain = 0;
    int loss = 0;
    int even = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i].profit > 0)
        {
            gain++;
        }
        else if (s[i].profit < 0)
        {
            loss++;
        }
        else
        {
            even++;
        }
    }
    printf("stocks with net gain: %d\nstocks with net loss: %d"
           "\nstocks that broke even: %d\n\n", gain, loss, even);
}

void saveText(struct stock s[], int n) //reads in data to a text file
{
    int i;
    FILE *f;
    f = fopen("\\home\\alex_chavez\\dev\\stock_struct\\stocks.txt", "w");
    for (i = 0; i < n; i++)
    {
        fprintf(f, "%s\n", s[i].name);
        fprintf(f, "%f %f %f %f %f\n", s[i].buyPrice ,s[i].nowPrice,
                s[i].buyCost, s[i].nowValue, s[i].profit);
    }
    fclose(f);
}

void getText(struct stock s[], int n) //writes data from a text file
{
    int i;
    FILE *f;
    f = fopen("\\home\\alex_chavez\\dev\\stock_struct\\stocks.txt", "r");

    for (i = 0; i < n; i++)
    {
        fgets(s[i].name, sizeof(s[i].name),f);
        fscanf(f, "%f%f%f%f%f", &s[i].buyPrice, &s[i].nowPrice,
               &s[i].buyCost, &s[i].nowValue, &s[i].profit);
    }

    fclose(f);
}

void savebin(struct stock s[], int n) //reads in data to a binary file
{
    FILE *f;
    f = fopen("\\home\\alex_chavez\\dev\\stock_struct\\stocks.bin", "wb");
    fwrite(s, sizeof(s[0]), n, f);
    fclose(f);
}

void getbin(struct stock s[], int n) //writes data from a binary file
{
    FILE *f;
    f = fopen("\\home\\alex_chavez\\dev\\stock_struct\\stocks.bin", "rb");
    fread(s, sizeof(s[0]), n, f);
    fclose(f);
}


void main()
{
    struct stock s[SIZE];

    getData(s, SIZE);
    printStocks(s, SIZE);

    sort(s, SIZE);
    printStocks(s, SIZE);

    netChange(s, SIZE);
    printStocks(s, SIZE);

    saveText(s, SIZE);
    getText(s, SIZE);
    printStocks(s, SIZE);

    printf("the following are binary files\n\n");

    savebin(s, SIZE);
    getbin(s, SIZE);
    printStocks(s, SIZE);
}



