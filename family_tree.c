#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc 

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person* create_person(const char *name, int age);
void read_person_info(const char *role, char *name_out, int *age_out);
int main(void) {
    printf("program initialized \n");
    char name[50];
    int age;
    //grandparents
    read_person_info("paternal grandfather", name, &age);
    Person *pat_gf = create_person(name, age);
    read_person_info("paternal grandmother", name, &age);
    Person *pat_gm = create_person(name, age);
    read_person_info("maternal grandfather", name, &age);
    Person *mat_gf = create_person(name, age);
    read_person_info("maternal grandmother", name, &age);
    Person *mat_gm = create_person(name, age);

    //parents
    read_person_info("father", name, &age);
    Person *father = create_person(name, age);
    read_person_info("mother", name, &age);
    Person *mother = create_person(name, age);

    //me
    read_person_info("you", name, &age);
    Person *me = create_person(name, age);

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

void read_person_info(const char *role, char *name_out, int *age_out) {
    printf("%s's name: ", role);
    scanf("%s", name_out);


    printf("%s's age: ", role);

    scanf("%d", age_out);

}