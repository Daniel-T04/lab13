# Polymorphism notes

Answer in your own words. Use the words **static dispatch** and **dynamic dispatch**.

## 1. The non-virtual destructor

What did the sanitizer report when `~Game` was not virtual? Explain which destructor ran and which did not.

When ~Game was not virtual, the compiler issued a warning -Wdelete-non-virtual-dtor about deleting an object of an abstract class type through a pointer with a non-virtual destructor. When I deleted a derived Game object, such, as Hangman through a base class pointer (Game *) only the destructor of Game ran, while the destructor of Hangman was never called. This leads to memory leaks and undefined behavior. In addition test files could not compile because destructors that were marked with override could no longer override a -virtual destructor of Game.


## 2. Game is abstract

In two sentences, explain why `Game g;` no longer compiles.

Game is now a base class because it includes a pure virtual function, such as virtual void play(). In C++ you cannot create objects directly from classes since they do not have complete implementations, for all their pure virtual functions.



## 3. override

What does `override` protect you from? Give an example of a mistake it catches.

override protects us from subtle signature mismatches when attempting to override virtual functions in derived classes. For example if you misspell a function name, such, as writing paly() of play() or if you change its parameter list the compiler will see it as a new function unless you use the override keyword. When you write override the compiler will immediately notice the mistake. Give an error.

## 4. Last week versus this week

Repeat the Week 12 experiment: `Game *g = &hangman; g->play();`. What printed last week, and what prints now? Name the kind of dispatch that happened each time


Last week I saw that g->play() printed the base class behavior because the call was resolved by static dispatch, which relies on the compile-time pointer type (Game*). This week because play() is g->play() correctly prints the derived games specific menu/play loop. Here dynamic dispatch is at work using the table such, as vptr or vtbl at runtime.

