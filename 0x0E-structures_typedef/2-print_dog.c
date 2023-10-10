#include "dog.h"

/**
 * print_dog - Function to print a struct dog
 * @d: Pointer to where to print from
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", (d->name) ? d->name : "nil");
		printf("Age: %f\n", (d->age) ? d->age : 0);
		printf("Owner: %s\n", (d->owner) ? d->owner : "nil");
	}
}
