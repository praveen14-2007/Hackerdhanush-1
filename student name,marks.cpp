#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *name;
    int m1, m2, m3, total;

    // getting values from command line
    name = argv[1];
    m1 = atoi(argv[2]);
    m2 = atoi(argv[3]);
    m3 = atoi(argv[4]);

    total = m1 + m2 + m3;

    printf("Student Name: %s\n", name);
    printf("Marks: %d %d %d\n", m1, m2, m3);
    printf("Total = %d\n", total);

    return 0;
}
