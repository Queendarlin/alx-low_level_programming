#include "dog.h"

/**
 * free_dog - Function to free dogs
 * @d: Pointer to the freed dogs
 *
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		if (d->name != NULL)
			free(d->name);
		if (d->owner != NULL)
			free(d->owner);
	}
}
