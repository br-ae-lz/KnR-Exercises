#include <stdio.h>
#include <stdlib.h>     // for atof()
#include <ctype.h>
#include <math.h>

#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found
#define VAR '\0'        // signal that a var operation was performed
#define MAXVAL 100      // maximum depth of val stack

// Prompt is as follows:
// Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter 
// names.) Add a variable for the most recently printed value.

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void defVar(void);
double retVar(int);
int getch(void);
void ungetch(int);
// (only definable variables are capital letters in ASCII and z, the most recently printed value)
double var[27];     // definable variable array

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
        case VAR:
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
            var[26] = pop();
            printf("\t%.8g\n", var[26]);
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

// defVar: if the next character of input is a definable variable, define it as the top value
// of the stack
void defVar(void)
{
    int c;

    // isolate next input char
    while ((c = getch()) == ' ' || c == '\t')
        ;
    // if char is a definable variable, define it, otherwise print error
    if (c >= 'A' && c <= 'Z')
    {
        var[c-65] = pop();
        push(var[c-65]);
    }
    else
        printf("error: '%c' is not a definable variable\n", c);
}

// retVar: return the value of the input variable
double retVar(int c)
{
    if (c >= 'A' && c <= 'Z')
        return var[c-65];
    if (c == 'z')
        return var[26];
}

// getop: get next character or numeric operand
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    
    s[1] = '\0';
    // proceed past hyphens, d's, definable variables, and z's
    if (!isdigit(c) && c != '.' && c != '-' && c != 'd' && !(c >= 'A' && c <= 'Z') && c != 'z')
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

    // return if c is a d not comprising a def command, otherwise commence def routine
    if (c == 'd')
    {
        c = getch();
        if (c != 'e')
        {
            ungetch(c);
            return 'd';
        }
        c = getch();
        if(c != 'f')
        {
            ungetch(c);
            ungetch('e');
            return 'd';
        }
        defVar();
        return VAR;
    }

    // if c is a definable variable or z, place its value on the stack
    if (c >= 'A' && c <= 'Z' || c == 'z')
    {
        push(retVar(c));
        return VAR;
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