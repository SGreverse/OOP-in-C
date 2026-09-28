# C-OOP Zoo Simulation

 This is a personal project I put together to see how far I could push raw C to behave like an object-oriented language. It's a simple Zoo simulator, but the real goal was to manually implement concepts like polymorphism, inheritance, and virtual tables from scratch, without relying on C++.

## How it works

* **Inheritance:** I used struct embedding. By making the base `Animal` struct the very first member of the `Dog` and `Cat` structs, the memory aligns perfectly. This lets me safely cast pointers between derived and base types.
* **Polymorphism (Dynamic Dispatch):** I built a custom v-table architecture. It uses macros (like `Poly_EAT` or `Poly_SLEEP`) to hide the messy function pointer casting,but the same code runs for dog, cat and animal yet different functions are called.
* **Calling Super:** You can bypass the virtual table entirely to call base class methods directly from overridden methods, which works exactly like using `super()` in Java or `base` in C#.
* **Memory Management:** I wrote custom destructors that cascade the cleanup. For example, it ensures a cat's dynamically allocated array of kittens is completely freed before it moves on to free the base animal struct.

## Project Layout

* `Animal.c` and `Animal.h`: The base class. This contains the generic struct, the v-table definition, and the polymorphic macros.
* `Dog.c/h` and `Cat.c/h`: The derived classes. These override specific methods like sleeping and feeding, while inheriting others.
* `Zoo.c` and `Zoo.h`: The collection manager. It uses `realloc` to manage a dynamic array of polymorphic animal pointers.
* `main.c`: A simple CLI that lets you build a zoo, instantiate animals, and trigger their behaviors.

## Trying it out

If you want to compile and run it yourself, you just need a standard C compiler like `gcc`.
Since it was built in VS 2022 i just attached the .c and .h files needed, and anyone can copy them to a new project in the IDE of their liking and run it themselves, or just look at the source code.
