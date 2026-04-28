#include <stdio.h>

struct student
{
    int marks;
};

int main()
{
    int n, i;
    float total = 0, avg;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student s[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter marks of student %d: ", i+1);
        scanf("%d", &s[i].marks);
        total = total + s[i].marks;
    }

    avg = total / n;

    printf("Total = %.2f\n", total);
    printf("Average = %.2f\n", avg);

    return 0;
}
