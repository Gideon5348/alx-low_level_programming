#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A structure representing a dog
 * @name: The name of the dog
 * @age: The age of the dog
 * @owner: The name of the owner of the dog
 *
 * Description: This structure represents a dog,
 * including its name, age, and owner's name.
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */
