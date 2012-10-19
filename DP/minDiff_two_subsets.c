#include <stdio.h>
#include <string.h>
#include<stdlib.h>
/*Int comparator for sorting*/
int compareInt(const int *a, const int *b)
{
    return *a - *b;
}

/*
This function divides the given array into two parts such that difference of their sum is minimum

Algo:
1. sort the array
2. Starting from the end, put last element into one part and last two into another part
3. From k =  n-2 to 0, compare diffs of
    a. smaller part + a[k] and bigger part
    b. smaller part + last num of bigger part and bigger part - last num of bigger part + a[k]

4. if a is small, add k to smaller part
    else add last number of bigger part to smaller part and a[k] to bigger part
*/
void divide(int a[], int n)
{
    int i;

    /*print the given array*/
    printf("\n\nGiven array: ");

    for(i = 0; i <n; ++i)
        printf("%d ", a[i]);

    printf("\n\n");

    /*sort the array*/
    qsort(a, n, sizeof(int), compareInt);


    /*struct to hold info about each part*/
    typedef struct
    {
        int arr[(n + 1) / 2];
        int *index;
        int sum;
    }Part;


    /*Initialize two parts*/
    Part b, c;

    memset(&b, 0, sizeof(b));
    memset(&c, 0, sizeof(c));

    b.arr[0] = a[n-1];
    c.arr[0] = a[n-2];

    b.index =  b.arr;
    c.index = c.arr;

    b.sum = a[n-1];
    c.sum = a[n-2];

    int k = n-3;
    int diff1, diff2;
    int el;

    //pointers to smaller and bigger parts
    Part *smaller, *bigger;

    while(k >= 0)
    {
        //decide smaller and biggers parts
        if(b.sum < c.sum)
        {
            smaller = &b;
            bigger = &c;
        }
        else
        {
            smaller = &c;
            bigger = &b;
        }

        //now decide where to put a[k] in smaller or bigger part
        el = *(bigger->index); //last element of bigger
        diff1 = smaller->sum + a[k] - bigger->sum;
        diff2 = smaller->sum + (el << 1) - bigger->sum - a[k];

        if(diff2 < diff1) //compare diffs
        {
            (*(++(smaller->index))) = el;

            smaller->sum += el;

            smaller->sum += a[k] - el;

            *(bigger->index) = el;
        }
        else
        {
            (*(++(smaller->index))) = a[k];
            smaller->sum += a[k];
        }

        k--;


    /*print the first part*/
    int *p = b.arr;

    printf("Part1: ");
    while(p <= b.index)
        printf("%d ", *p++);

    printf("\n\n");

    /*print the second part*/
    p = c.arr;

    printf("Part2: ");
    while(p <= c.index)
        printf("%d ", *p++);

    printf("\n\n");


    printf("Sum Diff: %d\n\n", abs(b.sum - c.sum) );
    }
}

int main()
{
    int a[] = {120, 140, 20, 30 ,40 , 50 ,60 ,70 , 800 , 1000, 10, 5};

    divide(a, sizeof(a)/ sizeof(int));
}
