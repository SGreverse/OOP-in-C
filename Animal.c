#include "Animal.h"
#include <stdlib.h>
#include <stdio.h>

//single static v_table for every single animal object
static const void* const animal_vtable[NUMBER_OF_METHODS] = {
	[METHOD_EAT] = animal_Feed,
	[METHOD_SLEEP] = animal_Sleep,
	[METHOD_SPEAK] = animal_Speak,
	[METHOD_PRINT] = animal_Print,
	[METHOD_FREE] = animal_Free
};

void animal_Init(Animal* self,int age,char* name, char* voice) {
	
	self->animal_age = age;
	self->animal_voice = voice;
	self->animal_name = name;
	self->animal_sleepness = 1;
	self->animal_fullness = 0;
	self->type = "Animal";
	//inits the virtual table
	self->V_Table = animal_vtable;
}

void animal_Sleep(Animal* self,float sleep_amount) {
	float  sleep_diff;
	if (self->animal_sleepness == 0) {
		puts("animal is not sleepy\n");
		return;
	}

	if (sleep_amount < 0 || sleep_amount>1) {
		puts("not in range\n");
		return;
	}

	sleep_diff = self->animal_sleepness - sleep_amount;
	self->animal_sleepness = sleep_diff > 0 ? sleep_diff : 0;

	puts("the animal has slept\n");

}

void animal_Speak(Animal* self) {
	printf("the %s said %s\n",self->animal_name,self->animal_voice);
}

void animal_Feed(Animal* self, float feed_amount) {
	if (self->animal_fullness == 1) {
		puts("the animal is full\n");
		return;
	}

	if (feed_amount < 0 || feed_amount>1) {
		puts("not in range\n");
		return;
	}
	self->animal_fullness = self->animal_fullness - feed_amount < 1 ? self->animal_fullness + feed_amount : 1;
	puts("the animal has eaten\n");
}

void animal_Print(Animal* self) {
	printf("his type is:%s\nhe's called:%s\nhis age is:%d\nhe is %.2f%% full\nand is %.2f%% sleepy\n",
		self->type,
		self->animal_name,
		self->animal_age,
		self->animal_fullness * 100,
		self->animal_sleepness * 100);
}
void animal_Free(Animal* self) {
	free(self->animal_name);
	free(self);
}