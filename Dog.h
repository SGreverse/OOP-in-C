#pragma once

#include "Animal.h"

enum Boolean{
	FALSE,
	TRUE
};

typedef int bool;

typedef struct {
	Animal super;

	bool dog_is_adopted;
	
}Dog;

void dog_Init(Dog* self,int age, char* name, bool is_adopted);
void dog_Sleep(Animal* self,float sleep_amount);// only called by the virtual table
void dog_Feed(Animal* self, float amount);// only called by the virtual table
void dog_Print(Animal* self); // only called by the virtual table
void dog_Free(Animal *self); // only called by the virtual table