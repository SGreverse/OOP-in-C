#include "Dog.h"
#include "Cat.h"
#include "Zoo.h"

Animal* choose_and_create_animal() {
	int input, check;
	puts("which animal type would you like?\n"
		"	1.animal\n"
		"	2.cat\n"
		"	3.dog\n"
	);
	check = scanf_s(" %d", &input);
	if (check != 1) {
		puts("Please enter a valid number\n");
		while (getchar() != '\n') {} //clear input buffer
		return NULL;
	}
	switch (input) {
		case 1:
			return create_animal();
		case 2:
			return create_cat();
		case 3:
			return create_dog();
		default:
			puts("not an option\n");
			return NULL;
	}
}
int main() {
	Zoo* animal_zoo=create_zoo();
	Animal* current_animal=NULL;
	puts("welcome to the OOP zoo!\n"
		 "In this zoo you can only choose 3 animals- a dog, a cat, or just a generic animal.\n"
		 "you can feed the animals, help them sleep,look at their info and create new animals whenever you want!\n"
		 "and dont worry, all of the animals here are treated exactly the same.\n"
	);
	puts("Options:\n");
	puts("1. Create new animal\n"
		"2. feed the animal\n"
		"3. help them sleep\n"
		"4. hear their voice\n"
		"5. print their info\n"
		"6. print all created animals info\n"
		"7. exit"
	);
	int input,check;
	float feed, sleep;
	while (1) {
		fputs("what would you like to do:",stdout);
		check = scanf_s(" %d", &input);
		if (check != 1) {
			puts("Please enter a valid number\n");
			while(getchar()!='\n'){} //clear input buffer
			continue;
		}
		switch (input) {
		case 1:
			current_animal = choose_and_create_animal();
			if (current_animal) {
				add_Animal(animal_zoo, current_animal);
			}
			break;
		case 2:
			if (!current_animal) {
				puts("No animal created");
				break;
			}
			puts("Choose the amount to feed(0-1):");
			check = scanf_s(" %f", &feed);
			if (check != 1) {
				puts("Invalid float\n");
				while (getchar() != '\n') {} //clear input buffer
				break;
			}
			Poly_EAT(current_animal, feed);
			break;
		case 3:
			if (!current_animal) {
				puts("No animal created");
				break;
			}
			puts("Choose the amount to sleep(0-1):");
			check = scanf_s(" %f", &sleep);
			if (check != 1) {
				puts("Invalid float\n");
				while (getchar() != '\n') {} //clear input buffer
				break;
			}
			Poly_SLEEP(current_animal, sleep);
			break;
		case 4:
			if (!current_animal) {
				puts("No animal created");
				break;
			}
			Poly_SPEAK(current_animal);
			break;
		case 5:
			if (!current_animal) {
				puts("No animal created");
				break;
			}
			Poly_PRINT(current_animal);
			break;
		case 6:
			print_all_animals(animal_zoo);
			break;
		case 7:
			goto END;
		default:
			puts("not an option,try again\n");
			break;

		}
	}
END:
	destroy_zoo(animal_zoo);
	return 0;
}