# GDB log

One dated section per week. Paste the commands you used and the output you saw, then explain what it means in your own words. Pasted output with no explanation earns partial credit at most.

## Week 12 (Lab 12)

### The constructor chain

Commands, in the order you typed them, with one line on what each did:

Backtrace inside `Hangman::Hangman` (paste it):

Backtrace inside `Game::Game` (paste it):

Where `finish` returned to:

Order of destructor breakpoints when the program ended:

Construction order and destruction order, as read from the backtraces:

### What a base pointer shows

`print hangman` (paste it):

`print *g` (paste it):

What is different, and why:

`ptype Hangman` and `ptype g` (paste them):

One sentence on what `ptype Hangman` revealed about inheritance:

## Week 13 (Lab 13)

Each partner writes their own section. Put your name here: Daniel Tinoco

### A Game pointer with a virtual play()

`set print object on`, then `print *g` (paste it). What changed from Week 12?

$2 = (Hangman) {<Game> = {
    _vptr.Game = 0x555555567bb8 <vtable for Hangman+16>,
    m_title = "Hangman", m_last_score = 0}, m_times_played = 0}

Reason: Unlike in Week 12, where dynamic type printing was off and print g* only displayed the base Game fields, when enabling set print object on inspects the vtable pointer like _vptr.Game which correctly reveals the true dynamic derived type in Hangman.


`info vtbl *g` (paste it). Which functions are in the table?

vtable for 'Game' @ 0x555555567bb8 (subobject @ 0x55555557b2b0):
[0]: 0x555555558fb8 <Hangman::~Hangman()>
[1]: 0x555555558fe6 <Hangman::~Hangman()>
[2]: 0x555555558f66 <Hangman::play()>

The functions listed. Here are the virtual destructors like Hangman::~Hangman() and overridden virtual function Hangman::play().

Where `step` into `g->play()` landed, and how that compares with Week 12:

Stepping into play() landed  directrly inside Hangman::play(). In contrast to Week 12 where static dispatch is bound the call based on the compile-time pointer type. Where Lab 13 uses the dynamic dispatch on the vierual table to resolve and execute the derived class method at a run time.




### A Monster pointer

`print *monster` and `ptype monster` with `set print object on` (paste them). Which shows the derived object, and which still shows the base type?

`info vtbl *monster` for a Goblin, then for a Troll (paste both). Compare the entries:

Where `step` into `monster->attack_damage()` landed for each kind:
