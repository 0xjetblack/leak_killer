# leak_killer
A simple library to manage memory allocation through out the program's lifetime.
This is a basic implementation of the Garbage collector concept(actually it is a stupid garbage collector, since it frees memory only when asked).
The goal is to not worry a lot about memory leaks while working on big projects. It is always good to free allocated memory when it has done it's job, but sometimes a few bytes slip, and thats when Leak Killer comes in handy!

I advice you to go learn a little bit about how garbage collectors work, then think of a simple implementation and code your own library. If you are stuck you can always read the code, it is simple and straight forward, trust me!

## How to use
Actually, it is very simple to use the library, all you need to do is to clone the repo `git clone git@github.com:0xjetblack/leak_killer.git`.
Then run make to get the `leak_killer.a` file so you can use it in your program.

## Coding examples
Basic functionality:
```c
int main(void)
{
  int *arr;
  arr = lfmalloc(1337 * sizeof(int)); // lfmalloc stand for leak free malloc
                                      // it is just an interface between you and malloc()
  for (int i = 0; i < 100; i++;)
    arr[i] = i + 1337;
  lfree(arr); // this is also an interface between you and free()
              // use lfree() instead of free() so you don't run into double free issues in free(heap);
  return 0;
}
```
Leak free example:
```c
#include <string.h>

int  main(void)
{
  char *str;

  str = lfmalloc(10 * sizeof(char));
  str = lfmalloc(17 * sizeof(char); // this causes us to lose the old allocated memory
                                    // since we track the memory this will be freed with free_heap
  free_heap();  // Magic!
  return 0;
}
```

## TODO:
1. Better documentation.
2. Extensive testing.
