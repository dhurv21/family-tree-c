#include <stdio.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;

} Person;

int main(void) {
    printf("program initialized\n");
}
