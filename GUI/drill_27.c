#include <stdlib.h>
#include <stdio.h>

void print_out(const char* p, const int x)
{
    printf("p is\"%s\" and x is %i\n", p, x);
}

int main()
{
    //------1. feladat-------
    printf("Hello World!\n");

    //------2. feladat-------
    char* first = "Hello";
    char* last = "World!";
    printf("%s %s\n", first, last);

    //------3. feladat-------
    print_out("May", 6);
    print_out("Chris", 39);
    print_out("C", 89);
    
    return 0;
}