#include <stdio.h>

struct student
{
    int roll;
    float marks;
};

int main()
{
    struct student s1, s2;

    printf("Enter roll number: ");
    scanf("%d", &s1.roll);

    printf("Enter marks: ");
    scanf("%f", &s1.marks);

    // copy one structure to another
    s2 = s1;

    printf("\nFirst student:\n");
    printf("Roll = %d\n", s1.roll);
    printf("Marks = %.2f\n", s1.marks);

    printf("\nSecond student (copied):\n");
    printf("Roll = %d\n", s2.roll);
    printf("Marks = %.2f\n", s2.marks);

    return 0;
}
