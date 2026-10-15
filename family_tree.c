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
void link_parents(Person *child, Person *father, Person *mother);
void print_family_relationships(const Person *me);
void free_family_tree(Person *people[], int count);


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

    // relationships
    link_parents(father, pat_gf, pat_gm);
    link_parents(mother, mat_gf, mat_gm);
    link_parents(me, father, mother); 

    // printing time
    print_family_relationships(me);

    // freeing
    Person *people[] = {pat_gf, pat_gm, mat_gf, mat_gm, father, mother, me};
    free_family_tree(people, 7);

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

void link_parents(Person *child, Person *father, Person *mother) {
    child->father = father;
    child->mother = mother;
}

void print_family_relationships(const Person *me) {
printf("===FAMILY TREE RELATIONSHIPS=== \n");
    printf("You: \n");
    printf("Name: %s | Age: %d\n", me->name, me->age); 

    printf("Parents: \n");
    printf("Father: %s | Age: %d \n", me->father->name, me->father->age);
    printf("Mother: %s | Age: %d \n", me->mother->name, me->mother->age);

    printf("Paternal grandparents:\n");
    printf("Grandfather: %s | Age: %d \n", me->father->father->name, me->father->father->age);
    printf("Grandmother: %s | Age: %d \n", me->father->mother->name, me->father->mother->age);

    printf("Maternal grandparents:\n");
    printf("Grandfather: %s | Age: %d \n", me->mother->father->name, me->mother->father->age);
    printf("Grandmother: %s | Age: %d \n", me->mother->mother->name, me->mother->mother->age);

}

void free_family_tree(Person *people[], int count) {
    for (int i = 0; i< count; i++) {
        free(people[i]);
    }
}