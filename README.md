# 42_cpp04

A C++ module for the 42 cursus.

## Description
Subtype polymorphism, abstract classes, interfaces.

## ex00
### Description
In this exercise I will create a class Animal, but I will not implement a pure virtual function.  My function will be implemented in the base class and in the derived class will be reimplemented. Therefore I add the keyword virtual to the function makeSound in the class Animal to indicate that the function will be RE-implemented in the derived class.
```
class Animal {
	public:
		virtual void makeSound( void ) const;
	[...]
}
```

There is a class WrongAnimal that shows the wrong implementation of the function makeSound.  


To demonstrate the incorrect overriding behavior, we need to:

- Create a base class (WrongAnimal) with a non-virtual makeSound method.
- Create a derived class (WrongCat) that overrides the makeSound method.
- Observe that the base class's makeSound method is still called when accessing the derived class object through a base class pointer.


```cpp
#include <iostream>

class WrongAnimal {
public:
    void makeSound() const {
        std::cout << "Generic animal sound\n";
    }
};

class WrongCat : public WrongAnimal {
public:
    void makeSound() const override {
        std::cout << "Meow!\n";
    }
};

int main() {
    WrongAnimal* animal = new WrongCat();
    animal->makeSound(); // Will output "Generic animal sound"
    delete animal;
    return 0;
}
```

### Testing
In each exercise I created a test_cpp folder in which I test creating different objects of the class Animal and WrongAnimal and verifying the order of the constructors and destructors. 
 
## ex01 - Deep Copy
### Description
Now the animals cat and dogs get a brain too... this is tricky because the brain contains an array of ideas. It is easy to forget that an array is a pointer to 
the first element of the array. So they hope that we forget to make a deep copy in the copy constructors of the Brain class and fail the exercise. Of course we will not forget that.

## ex02 - Abstract classes
Change the Animal class to abstract.
### Description
An abstract class is a base class that cannot be instantiated directly. It serves as a blueprint for derived classes, defining a common interface but leaving the implementation details to the derived classes.
Key Characteristics of Abstract Classes:
- At least one pure virtual function: A pure virtual function is a virtual function declared with = 0 in the class declaration. It has no implementation in the base class.
- Cannot be instantiated: You cannot create objects of an abstract class.
- Force implementation in derived classes: Derived classes must provide implementations for all inherited pure virtual functions to become concrete (non-abstract).

## ex03 - Interface 
### Description
> Interfaces don’t exist in C++98 (not even in C++20). However, pure abstract classes
are commonly called interfaces - From the 42 subject. 

In C++, the concept of an "interface" as a distinct language feature 
does not exist like it does in some other languages such as Java or C#. 
However, the concept of an interface as a contract for how a class should 
behave is still very much present in C++. This is typically achieved through 
the use of pure abstract classes.

A pure abstract class in C++ is a class that has at least one pure virtual 
function. A pure virtual function is a function that is declared in a 
base class and has no implementation in the base class. Derived classes 
are required to provide an implementation for this function. 
If a class contains only pure virtual functions (and possibly also 
static data members), it is often referred to as an "interface" 
because it defines a set of operations that derived classes must support, 
but does not provide any default implementation for these operations.

Where is the difference between Interfaces and Abstract Classes in C++?

- Definition: An abstract class with only pure virtual functions.
- Purpose: Defines a contract that derived classes must adhere to.
- Features: Contains only pure virtual functions. No data members or constructors allowed. Supports multiple inheritance through virtual inheritance.

### The goal
Complete the definition of the following AMateria class and implement the necessary
member functions.
```cpp
class AMateria
{
	protected:
	[...]
	public:
	AMateria(std::string const & type);
	[...]
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
}
```
Then implement the Materias concrete classes Ice and Cure

### Subtype polymorphism
allows objects of different types to be treated as if they were objects of a common supertype. This is achieved through inheritance and virtual functions.   
ex:
```cpp
int main() {
    Animal* animals[2] = {new Dog(), new Cat()};
    for (int i = 0; i < 2; ++i) {
        animals[i]->makeSound();
    }
}
```


### Dynamic Dispatch: Arrays of Objects vs. Arrays of Pointers
Understanding the Difference:  

- Dynamic dispatch is the mechanism by which a virtual function call is resolved at runtime based on the actual type of the object, rather than the static type of the pointer or reference.

When considering arrays of objects versus arrays of pointers in the context of dynamic dispatch, the key difference lies in how the objects are stored and accessed.
Array of Objects:
- Direct storage: Objects are stored directly in the array.
- No indirection: Accessing elements is direct and efficient.
- Limited polymorphism: While you can use base class pointers to access array elements, the actual type of the objects is fixed.
- Less flexible: Adding or removing elements is less flexible compared to arrays of pointers.

Array of Pointers:
- Indirect storage: The array stores pointers to objects, which are allocated elsewhere.
- Indirection overhead: Accessing elements involves an extra level of indirection, which can have a slight performance impact.
- Greater flexibility: You can store pointers to different derived types in the same array, enabling true polymorphism.
- Memory management: Careful management of pointer allocation and deallocation is required to avoid memory leaks.

When to Use Which:
- Array of objects: Suitable when you know the exact types of objects at compile time and don't need to change them dynamically. Offers better performance due to direct access.
- Array of pointers: Ideal when dealing with polymorphic objects, where the actual type of the object might vary. Provides more flexibility at the cost of potential performance overhead.

## Honorable mention
Not used in this project, but C++ 11 brings smart pointer types std::unique_ptr and std::shared_ptr to provide automatic memory management. They are designed to help prevent memory leaks by automatically releasing the memory associated with the object they point to when they go out of scope.
### std::unique_ptr
- Ownership: Represents exclusive ownership of the object it points to.  
- Lifetime: The object is destroyed when the unique_ptr goes out of scope.  
- Copy and Move: Cannot be copied, but can be moved. This prevents multiple pointers from managing the same object.  
- Use cases: When only one owner is needed for an object.   

### std::shared_ptr  
- Ownership: Multiple shared_ptrs can share ownership of an object.  
- Reference Counting: Keeps track of the number of shared_ptrs pointing to the object. The object is destroyed when the last shared_ptr goes out of scope.  
- Copy and Move: Can be copied and moved.  
- Use cases: When multiple owners might need to access the same object.  

Remember that shared_ptr has a reference counting overhead.

Example 
```cpp
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "Constructor called\n"; }
    ~MyClass() { std::cout << "Destructor called\n"; }
};

int main() {
    // unique_ptr
    std::unique_ptr<MyClass> uniquePtr(new MyClass()); // Ownership

    // shared_ptr
    std::shared_ptr<MyClass> sharedPtr1(new MyClass());
    std::shared_ptr<MyClass> sharedPtr2(sharedPtr1); // Shared ownership

    return 0;
}
```
No need to duse delete to free the memory.

## malloc vs. new: Error Handling
In C, using malloc requires a null pointer check because it returns NULL on failure. This is crucial for preventing crashes.  
In C++, new throws a std::bad_alloc exception on failure. This is generally considered better error handling because it allows you to gracefully handle the situation using try-catch blocks.  
If your program is designed to terminate on memory allocation failure, you can let the exception propagate. Or else you can use a try catch block to gracefully exit but this is not very common.


## Links
https://en.wikipedia.org/wiki/Polymorphism_(computer_science)  
