#include "Dog.h"

// in real OOP languages this table would be designed during compilation time
//here its predefined for efficency sake
static const void* const dog_vtable[NUMBER_OF_METHODS] = {
	[METHOD_EAT] = dog_Feed,
	[METHOD_SLEEP] = dog_Sleep,
	[METHOD_SPEAK] = animal_Speak,
	[METHOD_PRINT] = dog_Print,
	[METHOD_FREE] = dog_Free
};


void dog_Init(Dog* self, int age,char* name, bool is_adopted) {
	Animal* super = (Animal*)self;
	animal_Init(super,age,name,"Woof Woof");

	self->dog_is_adopted = is_adopted;
	super->animal_name = name;
	super->type = "Dog";
	super->V_Table = dog_vtable;
	
}
void dog_Sleep(Animal* self,float sleep_amount) {
	float sleep_diff;
	if (self->animal_sleepness == 0) {
		puts("dog is not sleepy\n");
		return;
	}

	if (sleep_amount < 0 || sleep_amount>1) {
		puts("not in range\n");
		return;
	}
	puts("the dog has slept\n");
	sleep_diff = self->animal_sleepness - sleep_amount;
	self->animal_sleepness = sleep_diff > 0 ? sleep_diff : 0;
}
void dog_Feed(Animal* self, float feed_amount) {
	if (self->animal_fullness == 1) {
		puts("dog is full\n");
		return;
	}

	if (feed_amount < 0 || feed_amount>1) {
		puts("not in range\n");
		return;
	}
	puts("the dog has eaten\n");
	self->animal_fullness = self->animal_fullness - feed_amount < 1 ? self->animal_fullness + feed_amount : 1;
}
void dog_Print(Animal* self) {
	animal_Print(self);
	printf("and he is %s\n",((Dog*)self)->dog_is_adopted?"adopted":"not adopted");
}
void dog_Free(Animal* self) {
	animal_Free(self);// since the dog is an extension of the same memory,freeing the animal would free the entire dog struct.
	//if any other things are allocated only by dog, we would free only them before we call animal free
}