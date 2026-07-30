#include "zoo.h"
#include "cat.h"
#include "dog.h"
#include <string.h>
Zoo* create_zoo() {
	Zoo* zoo = (Zoo*)malloc(sizeof(Zoo));

	if (!zoo) {
		fputs("Couldn't create the zoo :(", stderr);
		exit(1);
	}
	//initial capacity
	zoo->capacity = 4;

	zoo->animals = (Animal**)malloc(sizeof(Animal*) * zoo->capacity);
	if (!zoo->animals) {
		fputs("Couldn't create the animal list :(", stderr);
		exit(1);
	}
	zoo->size = 0;

	return zoo;
}

void add_Animal(Zoo* zoo, Animal* animal) {
	if (zoo->size >= zoo->capacity) {
		zoo->capacity = zoo->capacity * 2;
		Animal** temp = (Animal**)realloc(zoo->animals, sizeof(Animal*) * zoo->capacity);
		if (!temp) {
			fputs("Couldn't extend the animal list :(", stderr);
			exit(1);
		}
		zoo->animals = temp;
	}
	zoo->animals[zoo->size++] = animal;
}

void destroy_zoo(Zoo* zoo) {
	puts("Freeing all the animals...\n");
	for (size_t i = 0; i < zoo->size; i++) {
		Poly_FREE(zoo->animals[i]); // polymorphic free for every animal
	}
	//free the list
	free(zoo->animals);
	puts("destroying the zoo...\n");
	free(zoo);
	puts("goodbye... hope you had fun");
}

void print_all_animals(Zoo* zoo) {
	puts("\n");

	for (size_t i = 0; i < zoo->size; i++) {
		printf("\nAnimal #%llu:\n", i + 1);
		Poly_PRINT(zoo->animals[i]);
	}
	puts("\n");
}

Animal* create_animal() {
	int age, check;
	char tmp_buffer[51];
	char* name;
	while (1) {
		puts("enter the animal's age:");
		check = scanf_s("%d", &age);
		if (check == 1 && age>0) {
			break;
		}
		puts("invalid,try again\n");
		while (getchar() != '\n') {} //clear input buffer

	}

	puts("what is his name(Up to 50 characters)?");
	scanf_s("%50s", tmp_buffer, (unsigned int)sizeof(tmp_buffer));
	name = _strdup(tmp_buffer);

	Animal* animal = (Animal*)malloc(sizeof(Animal));
	animal_Init(animal, age,name, "Default animal noise");
	return animal;
}
Dog* create_dog() {
	int age, check;
	bool is_adopted;
	char tmp_buffer[51];
	char* name;
	while (1) {
		puts("enter the dog's age:");
		check = scanf_s("%d", &age);
		if (check == 1 && age>0) {
			break;
		}
		puts("invalid number,try again\n");
		while (getchar() != '\n') {} //clear input buffer
	}
	while (1) {
		puts("is he adopted?type 0 for no and any other number for yes");
		check = scanf_s("%d", &is_adopted);
		if (check == 1) {
			is_adopted = is_adopted != 0 ? TRUE : FALSE;
			break;
		}
		puts("invalid number,try again\n");
		while (getchar() != '\n') {} //clear input buffer
	}
	puts("what is his name(Up to 50 characters)?");
	scanf_s("%50s", tmp_buffer, (unsigned int)sizeof(tmp_buffer));
	name = _strdup(tmp_buffer);

	Dog* dog = (Dog*)malloc(sizeof(Dog));
	dog_Init(dog, age, name, is_adopted);
	return dog;

}
Cat* create_cat() {
	int age, check;
	size_t num_of_children;
	char tmp_buffer[51];
	char* name;
	char** children_names = NULL;
	while (1) {
		puts("enter the cat's age:");
		check = scanf_s("%d", &age);
		if (check == 1 && age>0) {
			break;
		}
		puts("invalid number,try again\n");
		while (getchar() != '\n') {} //clear input buffer
	}
	puts("what is his name(Up to 50 characters)?");
	scanf_s("%50s", tmp_buffer, (unsigned int)sizeof(tmp_buffer));
	name = _strdup(tmp_buffer);
	while (1) {
		puts("Congrats! by absolutely pure luck, your cat is pregnant!Enter how many children they have:"
			"and their names");
		check = scanf_s("%d", &num_of_children);
		if (check == 1 && num_of_children > 0) {
			break;
		}
		puts("invalid number,try again\n");
		while (getchar() != '\n') {} //clear input buffer
	}

	children_names = (char**)malloc(num_of_children * sizeof(char*));
	if (!children_names) {
		puts("failed to create children");
		num_of_children = 0;
	}
	for (size_t i = 0; i < num_of_children; i++) {
		printf("Enter child name #%d:", i+1);
		scanf_s("%50s", tmp_buffer, (unsigned int)sizeof(tmp_buffer));
		children_names[i] = _strdup(tmp_buffer);
	}
	Cat* cat = (Cat*)malloc(sizeof(Cat));
	cat_Init(cat, age, name,num_of_children, children_names);
	return cat;
}