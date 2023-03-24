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

/* function prototype for init_dog */
void init_dog(struct dog *d, char *name, float age, char *owner);
/* function protoype for print_dog */
void print_dog(struct dog *d);
/* a new type dog_t as a new name for the type struct dog */
typedef struct dog dog_t;
/*  function prototype for new_dog */
dog_t *new_dog(char *name, float age, char *owner);

#endif /* DOG_H */
