#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
int top = -1;
int front = -1, rear = -1;

int stack[MAX_SIZE];
int queue[MAX_SIZE];

typedef struct
{
    char text[100];
    int linie;
} undo;

typedef struct
{
    char text[MAX_SIZE];
    int line;
} Change;

typedef struct
{
    Change *stack;
    int top;
    int capacity;
} UndoStack;

void initStack(UndoStack *stack, int capacity)
{
    stack->stack = (Change *)malloc(capacity * sizeof(Change));
    stack->top = -1;
    stack->capacity = capacity;
}

void addChange(UndoStack *stack, const char *text, int line)
{
    if (stack->top < stack->capacity - 1)
    {
        stack->top++;
        strncpy(stack->stack[stack->top].text, text, MAX_SIZE);
        stack->stack[stack->top].line = line;
    }
    else
    {
        printf("Stiva este plina. Modificarea nu poate fi adaugata.\n");
    }
}

void undo1(UndoStack *stack)
{
    if (stack->top >= 0)
    {
        printf("Undo la linia %d: \"%s\"\n", stack->stack[stack->top].line, stack->stack[stack->top].text);
        stack->top--;
    }
    else
    {
        printf("Nu exista modificari pentru undo.\n");
    }
}

void freeStack(UndoStack *stack)
{
    free(stack->stack);
}

void push(int item)
{
    if(top == MAX_SIZE-1)
    {
        printf("Stiva este plina\n");
        return;
    }
    stack[++top] = item;
}

int pop()
{
    if(top == -1)
    {
        printf("Stiva este goala\n");
        return -1;
    }
    return stack[top--];
}

void display1()
{
    if(top == -1)
    {
        printf("Stiva este goala\n");
        return;
    }
    printf("Elementele din stiva sunt: ");
    for(int i=top; i>=0; i--)
        printf("%d ",stack[i]);
    printf("\n");
}


void enqueue(int item)
{
    if(rear == MAX_SIZE-1)
    {
        printf("Coada este plina\n");
        return;
    }
    if(front == -1)
        front = 0;
    queue[++rear] = item;
}

int dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Coada este goala\n");
        return -1;
    }
    return queue[front++];
}

void display2()
{
    if(front == -1 || front > rear)
    {
        printf("Coada este goala\n");
        return;
    }
    printf("Elementele din coada sunt: ");
    for(int i=front; i<=rear; i++)
        printf("%d ",queue[i]);
    printf("\n");
}

void pushundo(char *text, int linie)
{
    if (top==MAX_SIZE-1)
    {
        printf("limita de modificari atinsa\n");
        return;
    }
    top++;
    strcpy(stack[top].text,text,100);
    stack[top].linie=linie;
}

undo pop()
{
    if(top == -1)
    {
        printf("Nu exista modificari pentru undo\n");
        return undo{.linie=-1};
    }
    return stack[top--];

}

int main()
{
    pop(10);
    pop(20);
    pop(30);
    display1();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display2();
    pushundo("Text adaugat",1);
    UndoStack undoStack;
    initStack(&undoStack, 5);
    addChange(&undoStack, "Prima modificare", 1);
    addChange(&undoStack, "A doua modificare", 2);
    addChange(&undoStack, "A treia modificare", 3);
    undo1(&undoStack);
    addChange(&undoStack, "A patra modificare", 4);
    undo1(&undoStack);
    freeStack(&undoStack);
    return 0;
}
