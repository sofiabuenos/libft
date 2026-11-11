*This project has been created as part of the 42 curriculum by sobueno.*

<div align="center">

```
  ██╗     ██╗██████╗ ███████╗████████╗
  ██║     ██║██╔══██╗██╔════╝╚══██╔══╝
  ██║     ██║██████╔╝█████╗     ██║
  ██║     ██║██╔══██╗██╔══╝     ██║
  ███████╗██║██████╔╝██║        ██║
  ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝
```

### My very first own library

*A static C library of general-purpose functions, rebuilt from scratch.*

![language](https://img.shields.io/badge/language-C-00599C?style=flat-square)
![output](https://img.shields.io/badge/output-libft.a-2ea44f?style=flat-square)
![flags](https://img.shields.io/badge/flags--Wall%20--Wextra%20--Werror-informational?style=flat-square)
![school](https://img.shields.io/badge/42-curriculum-000000?style=flat-square)

</div>

> [!NOTE]
> **Work in progress.** Everything in the reference below is written, except the entries marked 🚧: `ft_split` and the linked-list functions (Part 3), which are still being implemented.

---

## 📑 Table of contents

- [Description](#-description)
- [Instructions](#-instructions)
- [Library reference](#-library-reference)
- [Technical choices](#-technical-choices)
- [Testing](#-testing)
- [Project structure](#-project-structure)
- [Resources](#-resources)

---

## 📖 Description

**Libft** is the first project of the 42 common core. The goal is to build your own C library: a collection of functions you will reuse in every later project, instead of depending on the standard ones.

Writing it teaches how those everyday functions really work: how memory is read and written byte by byte, why `memmove` exists next to `memcpy`, what a string actually is, and how a program asks the system for memory and must give it back.

The library is split in three parts, as the subject asks:

| Part | What it is | Examples |
|:---:|---|---|
| **1** | **Re-implementations of libc functions.** Same prototype and behaviour as the original, only the name changes (`strlen` → `ft_strlen`). | `ft_memcpy`, `ft_strlcpy`, `ft_atoi`, `ft_calloc` |
| **2** | **Additional functions** that are not in the libc, or exist in a different form. | `ft_substr`, `ft_strtrim`, `ft_itoa`, `ft_putnbr_fd` |
| **3** | **Linked-list functions**, built on a `t_list` node. | `ft_lstnew`, `ft_lstadd_back`, `ft_lstmap` 🚧 |

Everything is packaged into one **static library**, `libft.a`, so any future project can link against it.

> **Why a static library?** A `.a` file is just an archive of compiled `.o` files, made with `ar`. When a program is linked against it, the linker copies the needed code into the executable at build time, so the program does not depend on the library at run time.

---

## 🚀 Instructions

### Requirements

- `cc` (clang or gcc), `make` and `ar`
- A Unix-like system (developed on macOS, meant to build on the Linux machines of the 42 campus)

### Build

```bash
make
```

This compiles every source file with `cc -Wall -Wextra -Werror` and archives the objects into `libft.a` at the root of the repository.

| Rule | What it does |
|---|---|
| `make` / `make all` | Builds `libft.a`. Running it again with nothing changed does nothing (no relinking). |
| `make clean` | Removes the object files (`.o`). |
| `make fclean` | Removes the object files **and** `libft.a`. |
| `make re` | `fclean` followed by `all`: a clean rebuild. |

The `.o` files are rebuilt whenever their `.c` file **or** `libft.h` changes.

### Use it in your own program

Include the header and link against the library:

```c
#include "libft.h"

int	main(void)
{
	char	*s;

	s = ft_strjoin("hello, ", "42");
	if (!s)
		return (1);
	ft_putendl_fd(s, 1);
	free(s);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror -I. main.c -L. -lft -o demo
./demo
```

`-I.` tells the compiler where `libft.h` is, `-L.` where `libft.a` is, and `-lft` links the library (`libft.a` → `ft`).

---

## 📚 Library reference

Every prototype is declared, and documented, in [`libft.h`](libft.h). The functions are grouped by part, then by family, and listed alphabetically inside each family.

### Part 1: libc functions

**Character tests and conversion** (`ctype.h`)

| Function | Description |
|---|---|
| `ft_isalnum` | Returns `1` if the character is a letter or a digit, `0` otherwise. |
| `ft_isalpha` | Returns `1` if the character is a letter, `0` otherwise. |
| `ft_isascii` | Returns `1` if the value is in the ASCII range (0–127), `0` otherwise. |
| `ft_isdigit` | Returns `1` if the character is a decimal digit, `0` otherwise. |
| `ft_isprint` | Returns `1` if the character is printable (space included), `0` otherwise. |
| `ft_tolower` | Converts an uppercase letter to lowercase; anything else is returned unchanged. |
| `ft_toupper` | Converts a lowercase letter to uppercase; anything else is returned unchanged. |

**Memory** (`string.h`)

| Function | Description |
|---|---|
| `ft_bzero` | Sets the first `n` bytes of a memory area to zero. |
| `ft_memchr` | Finds the first occurrence of a byte in a memory area. |
| `ft_memcmp` | Compares the first `n` bytes of two memory areas. |
| `ft_memcpy` | Copies `n` bytes from one area to another. The areas must not overlap. |
| `ft_memmove` | Like `ft_memcpy`, but the areas **may** overlap: the copy direction is chosen so no byte is overwritten before it is read. |
| `ft_memset` | Fills the first `n` bytes of a memory area with a given byte. |

**Strings** (`string.h`)

| Function | Description |
|---|---|
| `ft_strchr` | Finds the first occurrence of a character in a string (the `'\0'` counts as part of it). |
| `ft_strdup` | Duplicates a string into newly allocated memory. |
| `ft_strlcat` | Appends a string to another, never letting the total exceed the buffer size; returns the length it tried to create. |
| `ft_strlcpy` | Copies a string into a buffer of limited size, always `'\0'`-terminated; returns the length of the source. |
| `ft_strlen` | Returns the length of a string. |
| `ft_strncmp` | Compares at most `n` characters of two strings. |
| `ft_strnstr` | Finds the first occurrence of a string inside another, searching at most `len` characters. |
| `ft_strrchr` | Finds the **last** occurrence of a character in a string. |

**Number conversion and allocation** (`stdlib.h`)

| Function | Description |
|---|---|
| `ft_atoi` | Converts the beginning of a string to an `int` (skips whitespace, accepts a sign). |
| `ft_calloc` | Allocates zero-initialised memory for `count` elements of `size` bytes each. |

### Part 2: additional functions

**Building new strings** (all allocate memory and return `NULL` if the allocation fails)

| Function | Description |
|---|---|
| `ft_itoa` | Converts an integer to its decimal string, negative numbers included. |
| `ft_split` 🚧 | Splits a string on a delimiter character into a `NULL`-terminated array of newly allocated strings. |
| `ft_strjoin` | Concatenates two strings into a new one. |
| `ft_strmapi` | Applies a function to every character (index and character as arguments) and builds a new string from the results. |
| `ft_strtrim` | Removes a set of characters from both ends of a string. |
| `ft_substr` | Extracts a substring given a start index and a maximum length. |

**Iterating over a string**

| Function | Description |
|---|---|
| `ft_striteri` | Applies a function to every character of a string, passing its index and its address so it can be modified in place. |

**Writing to a file descriptor**

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline. |
| `ft_putnbr_fd` | Writes an integer in decimal. |
| `ft_putstr_fd` | Writes a string. |

### Part 3: linked lists 🚧

Built on this node, declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

`content` can point to any kind of data, and `next` is the address of the following node (or `NULL` at the end of the list).

| Function | Description |
|---|---|
| `ft_lstnew` 🚧 | Creates a node holding the given content, with `next` set to `NULL`. |
| `ft_lstadd_front` 🚧 | Adds a node at the beginning of the list. |
| `ft_lstsize` 🚧 | Counts the nodes of the list. |
| `ft_lstlast` 🚧 | Returns the last node of the list. |
| `ft_lstadd_back` 🚧 | Adds a node at the end of the list. |
| `ft_lstdelone` 🚧 | Frees a node's content with the given function, then the node itself (never the next one). |
| `ft_lstclear` 🚧 | Deletes a node and all its successors, then sets the list pointer to `NULL`. |
| `ft_lstiter` 🚧 | Applies a function to the content of every node. |
| `ft_lstmap` 🚧 | Builds a new list from the results of a function applied to each content; cleans up if an allocation fails. |

---

## 🛠 Technical choices

- **Only `malloc`, `free` and `write`** are used from the outside; everything else is built inside the library.
- **No global variables.** Helper functions are `static`, so their scope stays inside their own file and they never leak into the library's public symbols.
- **Every allocating function returns `NULL` when `malloc` fails**, and releases what it had already allocated before returning.
- **No `restrict` qualifier** in the prototypes and no `-std=c99`, as the subject requires.
- **Written to the 42 Norm** (`norminette`): at most 25 lines and 5 variables per function, at most 5 functions per file.
- **The Makefile never relinks** and rebuilds an object when its source or the header changes.
- **Unsigned arithmetic is handled with care**: lengths are `size_t`, so subtractions and sums that could wrap around are checked first.

---

## ✅ Testing

The test programs are **not part of this repository**. While developing, each function was checked in a separate folder against the system libc and against the cases listed in the subject, using:

- `-fsanitize=address,undefined` to catch invalid memory access and undefined behaviour;
- `leaks --atExit` (macOS) to look for memory leaks;
- `norminette` on every source file and on `libft.h`;
- `nm -u libft.a` to confirm that only the allowed external functions are used.

---

## 🗂 Project structure

```
.
├── Makefile        # builds libft.a (all, clean, fclean, re)
├── libft.h         # every prototype, documented, plus the t_list node
├── README.md
└── ft_*.c          # one function per file
```

---

## 🔗 Resources

### References

- `man 3` pages of the functions being re-implemented (`man 3 memmove`, `man 3 strlcpy`, `man 3 calloc`, …)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html): rules, automatic variables, substitution references and `.PHONY`
- [GCC manual, Overall Options](https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html): what `-c` does and where compilation stops
- [cppreference: C string library](https://en.cppreference.com/c/string/byte) and [`size_t`](https://en.cppreference.com/c/types/size_t)
- [norminette](https://github.com/42School/norminette): the official checker for the 42 Norm

### 🤖 How AI was used

I used **Claude** (Anthropic), through Claude Code, as a study assistant, together with two tutor agents I built myself (see [My study agents](#-my-study-agents)). It was set up not to hand over solutions, and the logic of every function in this library was written by me.

**What AI helped with**

- **Learning concepts:** explanations of compilation stages, static versus dynamic libraries, pointers and `void *`, `memcpy` versus `memmove` and memory overlap, `size_t` and unsigned wrap-around, two's complement, why some libc functions take an `int` (`EOF`), Makefile syntax, and linked lists with `t_list **`. It also asked diagnostic questions to check my understanding.
- **Study planning and note-taking:** my *Code Prof* agent read the subject, listed the rules that would make the project fail and the concepts I needed to learn, and wrote my study plan; my *Escriba* agent organised my raw notes into concept notes.
- **Tooling and housekeeping:** fixing the Makefile (full source list, header dependency, colour variables), adding `static` to a helper function, fixing Norm formatting issues (spacing, end-of-file newlines, line wrapping), and organising `libft.h` with function descriptions based on the signatures I had already written.
- **Verification:** writing test programs, kept outside the repository, that compare my functions against the system libc with sanitizers; running `norminette`, `nm -u` and `leaks`.
- **Code review:** pointing out the file and line of bugs and edge cases (for example integer overflows). I wrote the fixes myself.
- **This README** was drafted by Claude and reviewed by me.

**What AI did not do:** write the implementation of any function in `ft_*.c`.

### 🎓 My study agents

42 gives you a subject and no course material, so I built myself two tutors with Claude Code. They run on my own machine and keep their notes in an [Obsidian](https://obsidian.md) vault. Neither of them is allowed to write the code of a project: their job is to make me understand it well enough to write it, and to defend it.

| Agent | What it does |
|---|---|
| **Code Prof** | Reads a project's subject and lists the rules that would make it fail. Maps the concepts I need, with sources, and asks short diagnostic questions to find out what I already know. Then writes a study plan sized to my deadline. |
| **Escriba** | Turns my raw notes (a scratch file, a photo of my notebook) into organised, linked concept notes. |

Both were used in this project, for the planning and note-taking described above.

If you'd like any of my concept notes, just ask me. I'm happy to share them! (Solutions stay out of it, so everyone gets to do their own learning.)
