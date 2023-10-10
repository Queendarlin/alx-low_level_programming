#include "dog.h"

/**
 * init_dog - Function to initialize a structure
 * @d: Pointer to struct dog initialization
 * @name: Member for the name of the dog
 * @age: Member for the age of the dog
 * @owner: Member for the owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
