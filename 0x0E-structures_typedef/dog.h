#ifndef DOG_H
#define DOG_H
/**
 * struct dog - Defines a dog's information
 * @name: The dog's name
 * @age: The dog's age
 * @owner: The dog's owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

#endif
