#include <stdio.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person* create_person(const char *name, int age);

int main(void) {
    printf("program initialized \n");
    return 0;
}

Person* create_person(const char *name, int age) {
    Person *new_person = (Person *)malloc(sizeof(Person));
    if (new_person == NULL) {
        return NULL;
    }

    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->father = NULL;
    new_person->mother = NULL;

    return new_person;
}