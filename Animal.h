#pragma once

#include <stdlib.h>
#include <stdio.h>

#define NUMBER_OF_METHODS (LAST_METHOD_ENUM)

//cast the void* in the v_table to a function pointer
//this is why its needed that all same methods from every object have the exact same signature 
#define Poly_EAT(self, amount) \
	( ((void (*)(Animal*, float))(((Animal*)(self))->V_Table[METHOD_EAT]))((Animal*)(self), (amount)) )

#define Poly_SLEEP(self, amount) \
	( ((void (*)(Animal*, float))(((Animal*)(self))->V_Table[METHOD_SLEEP]))((Animal*)(self), (amount)) )

#define Poly_SPEAK(self) \
	( ((void (*)(Animal*))(((Animal*)(self))->V_Table[METHOD_SPEAK]))((Animal*)(self)) )

#define Poly_PRINT(self) \
	( ((void (*)(Animal*))(((Animal*)(self))->V_Table[METHOD_PRINT]))((Animal*)(self)) )

#define Poly_FREE(self) \
	( ((void (*)(Animal*))(((Animal*)(self))->V_Table[METHOD_FREE]))((Animal*)(self)) )

enum METHODS { //maps method "names" to offsets in the virtual table
	METHOD_EAT,
	METHOD_SLEEP,
	METHOD_SPEAK ,
	METHOD_PRINT,
	METHOD_FREE ,
	LAST_METHOD_ENUM //replacment for a magic value for the virtual methods amount
	//must always stay the last enum, all new functions come before it
};

typedef struct {
	//both the pointer and the value the v_table points to is const
	const void* const* V_Table;//virtual method table

	int animal_age;
	char* animal_voice;
	char* animal_name;
	float animal_fullness;
	float animal_sleepness;
	char* type;
	
}Animal;


void animal_Init(Animal* self,int age,char* name, char* voice);
void animal_Sleep(Animal* self,float sleep_amount);
void animal_Speak(Animal* self);
void animal_Feed(Animal* self,float amount);
void animal_Print(Animal* self);
void animal_Free(Animal* self);