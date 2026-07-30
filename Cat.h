#pragma once

#include "Animal.h"
typedef struct {
	Animal super;
	size_t cat_children_amount;
	char** cat_children_names;

}Cat;

void cat_Init(Cat* self, int age, char* name, int num_of_children,char** children_names);
void cat_Sleep(Animal* self, float sleep_amount);// only called by the virtual table
void cat_Feed(Animal* self, float amount);// only called by the virtual table
void cat_Print(Animal* self); // only called by the virtual table
void cat_Free(Animal* self); // only called by the virtual table