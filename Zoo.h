#pragma once

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
//fancy name for a dyn list
typedef struct {
	Animal** animals;
	size_t size;
	size_t capacity;
}Zoo;

Zoo* create_zoo();

void add_Animal(Zoo* zoo, Animal* animal);

void destroy_zoo(Zoo* zoo);

void print_all_animals(Zoo* zoo);

Animal* create_animal();

Dog* create_dog();

Cat* create_cat();
