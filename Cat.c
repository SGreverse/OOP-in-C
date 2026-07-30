#include "Cat.h"

static const void* const cat_vtable[NUMBER_OF_METHODS] = {
	[METHOD_EAT] = cat_Feed,
	[METHOD_SLEEP] = cat_Sleep,
	[METHOD_SPEAK] = animal_Speak,
	[METHOD_PRINT] = cat_Print,
	[METHOD_FREE] = cat_Free
};

void cat_Init(Cat* self, int age, char* name,int num_of_children, char** children_names) {
	Animal* super = (Animal*)self;
	animal_Init(super,age,name,"Mewww");// same as a static/compile-time method dispatching

	self->cat_children_names = children_names;
	self->cat_children_amount = num_of_children;
	super->animal_name = name;
	super->type = "Cat";
	super->V_Table = cat_vtable;

}
void cat_Sleep(Animal* self, float sleep_amount) {
	float sleep_diff;
	if (self->animal_sleepness == 0) {
		puts("cat is not sleepy\n");
		return;
	}

	if (sleep_amount < 0 || sleep_amount>1) {
		puts("not in range\n");
		return;
	}
	puts("the cat has slept\n");
	sleep_diff = self->animal_sleepness - sleep_amount;
	self->animal_sleepness = sleep_diff > 0 ? sleep_diff : 0;
}
void cat_Feed(Animal* self, float feed_amount) {
	if (self->animal_fullness == 1) {
		puts("cat is full\n");
		return;
	}

	if (feed_amount < 0 || feed_amount>1) {
		puts("not in range\n");
		return;
	}
	puts("the cat has eaten\n");
	self->animal_fullness = self->animal_fullness - feed_amount < 1 ? self->animal_fullness + feed_amount : 1;
}
void cat_Print(Animal* self) {
	animal_Print(self);
	Cat* this = (Cat*)self;
	printf("and the cat has %d children:\n", this->cat_children_amount);
	for (size_t i = 0; i < this->cat_children_amount; i++) {
		printf("%llu.%s\n", i+1, this->cat_children_names[i]);
	}
}
void cat_Free(Animal* self) {
	Cat* this = (Cat*)self;
	for (size_t i = 0; i < this->cat_children_amount; i++) {
		free(this->cat_children_names[i]);
	}
	free(this->cat_children_names);//free the child list
	animal_Free(self);// since the cat is an extension of the same memory,freeing the animal would free the entire cat struct
}