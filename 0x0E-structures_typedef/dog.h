#ifndef DOG_H
#define DOG_H
#include <stdio.h>


/**
 * struct dog - A structure with the name dog
 * @name: The member for the name of the dog
 * @age: The member for the age of the dog
 * @owner: The member for the owner of the dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
