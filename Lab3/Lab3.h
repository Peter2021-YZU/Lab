#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <cstddef>
#include <string>

class Stack
{
private:
    int stackSize;
    int stackPtr;
    char *charStack;

public:
    Stack(int = 1, int = 0, char* = NULL);
    void push(char);
    void charPop();
    void reset();
    bool emptys();
    bool full();
};

#endif // STACK_H_INCLUDED
