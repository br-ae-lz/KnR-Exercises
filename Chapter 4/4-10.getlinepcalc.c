#include <stdio.h>
#include <stdlib.h>     // for atof()
#include <ctype.h>

#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found
#define MAXVAL 100      // maximum depth of val stack
#define MAXLEN 100

// Prompt is as follows:
// An alternate organization uses getline to read an entire input line; this makes 
// getch and ungetch unnecessary. Revise the calculator to use this approach.
// (getline is renamed to getaline due to conflicting with a standard library function.)

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
int getaline(int [], int);

// reverse Polish calculator
void main()
{
    int type;
    double op2;
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
        case '\n':
            printf("\t%.8g\n", pop());
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


int linecheck = 0;  // indicates when a new line must be read
int c = 0;          // position in current line
int in[MAXLEN];    // where current line is stored

// getop: get next character or numeric operand
int getop(char s[])
{
    // get line if necessary
    if (linecheck == 0)
    {
        getaline(in, MAXLEN);
        linecheck++;
    }

    int i = 0;

    while ((s[i] = in[c]) == ' ' || in[c] == '\t')
        c++;
    s[1] = '\0';

    if (!isdigit(in[c]) && in[c] != '.')
    {
        if (in[c] == '\n')  // end of line; read another
        {
            c = 0;
            linecheck--;
            return '\n';
        }
        return in[c++];   // not a number
    }

    if (isdigit(in[c])) // collect integer part
        while (isdigit(s[++i] = in[++c]))
            ;
    if (in[c] == '.')   // collect fraction part 
        while (isdigit(s[++i] = in[++c]))
            ;

    s[i] = '\0';
    return NUMBER;
}

/* getaline: get line into s, return length */
// (to make program operate as the previous model did, now deals with an int 
// array to store EOFs (stores them like \n's) and provides line length error)
int getaline(int s[], int lim)
{
    int c, i;
    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n' || c == EOF)
        s[i++] = c;

    if (lim <= 0)
    {
        printf("error: max line length exceeded\n");
        s[0] = '\n';
    }

    return i;
}