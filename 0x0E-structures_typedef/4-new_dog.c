#include "dog.h"

/**
 * _strlen - Function to calculate the length of a string
 * @string: The input string to check
 *
 * Return: the length of the string
 */
int _strlen(char *string)
{
	int length;

	length = 0;

	while (string[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strcpy - Function to copy the source string to the destination buffer
 * @dest: A pointer to the destination buffer
 * @src: The source string to be copied
 *
 * Return: A pointer to the destination buffer
 */
char *_strcpy(char *dest, char *src)
{
	int length = 0, index;

	while (src[length] != '\0')
	{
		length++;
	}

	for (index = 0; index < length; index++)
	{
		dest[index] = src[index];
	}
	dest[index] = '\0';

	return (dest);
}

/**
 * new_dog - Function to create a new dog
 * @name: The name of the new dog
 * @age: The age of the new dog
 * @owner: The owner of the new dog
 *
 * Return: A pointer to the newly created dog structure, else NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len_name, len_owner;

	len_name = _strlen(name);
	len_owner = _strlen(owner);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (len_name + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	dog->owner = malloc(sizeof(char) * (len_owner + 1));
	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return (NULL);
	}
	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	return (dog);
}
