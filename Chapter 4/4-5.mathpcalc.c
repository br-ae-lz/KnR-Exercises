#include <stdio.h>
#include <stdlib.h>     // for atof()
#include <ctype.h>
#include <math.h>

#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found
#define MAXVAL 100      // maximum depth of val stack

// Prompt is as follows:
// Add access to library functions like sin, exp, and pow.

int getop(char []);
void push(double);
double pop(void);
void clear(void);
int getch(void);
void ungetch(int);

// reverse Polish calculator
void main()
{
    int type;
    double top, op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':   // modulo support
            op2 = pop();
            if (op2 != 0.0)
                push((int) pop() % (int) op2);
            else
                printf("error: zero divisor\n");
            break;
        case '(':   // sine support
            push(sin(pop()));
            break;
        case '&':   // exp support
            push(exp(pop()));
            break;
        case '^':   // pow support
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case '!':   // print top element of stack without popping
            top = pop();
            printf("\t%.8g\n", top);
            push(top);
            break;
        case '@':   // duplicate top element of stack
            top = pop();
            push(top);
            push(top);
            break;
        case '#':   // swap top two elements of stack
            top = pop();
            op2 = pop();
            push(top);
            push(op2);
            break;
        case '~':   // clear stack
            clear();
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    system("pause");
}

int sp = 0;             // next free stack position
double val[MAXVAL];     // value stack

// push: push f onto value stack
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// clear: clear all values from stack
void clear(void)
{
    sp = 0;
}

// getop: get next character or numeric operand
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')    // proceed past hyphens
        return c;   // not a number
    
    i = 0;

    // return c if it is a hyphen not denoting a negative number
    if (c == '-')
    {
        // examine next c, but also push it back on input for future operations
        c = getch();    
        ungetch(c);

        if (!isdigit(c) && c != '.')
            return '-';
        // prepare for fractions as you would with non-negatives
        if (c == '.')
            s[++i] = c = getch();
    }
    
    if (isdigit(c)) // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')   // collect fraction part 
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}