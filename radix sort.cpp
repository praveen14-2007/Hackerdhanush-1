#include <stdio.h>

int getMax(int a[], int n)
{
    int i, max = a[0];
    for(i = 1; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}

void countSort(int a[], int n, int exp)
{
    int output[n];
    int count[10] = {0};
    int i;

    for(i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for(i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];

    for(i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for(i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n)
{
    int exp;
    int max = getMax(a, n);

    for(exp = 1; max / exp > 0; exp = exp * 10)
        countSort(a, n, exp);
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &a[i]);
    }

    radixSort(a, n);

    printf("\nSorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
