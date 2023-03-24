#include <stdlib.h>
#include "dog.h"

unsigned int _strlen(char *);

/**
 * new_dog - creates a new dog with the given parameters
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the owner of the dog
 *
 * Return: a pointer to the new dog, or NULL if allocation fails
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	int name_len, owner_len, i;

	/* check if any of the parameters are NULL */
	if (name == NULL || owner == NULL)
		return (NULL);

	/* allocate memory for the dog struct */
	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	/* get length of name and owner */
	name_len = _strlen(name);
	owner_len = _strlen(owner);

	/* allocate memory for name and owner strings */
	new_dog->name = malloc(sizeof(char) * (name_len + 1));
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}
	new_dog->owner = malloc(sizeof(char) * (owner_len + 1));
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	/* copy name and owner to struct */
	for (i = 0; i <= name_len; i++)
		new_dog->name[i] = name[i];
	new_dog->age = age;
	for (i = 0; i <= owner_len; i++)
		new_dog->owner[i] = owner[i];

	return (new_dog);
}

/**
 * _strlen - returns the length of a string
 * @s: string to get the length of
 * Return: length of the string
 */

unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
