#include <iostream>
#include <ctype.h>
using namespace std;

class infixToPostfix
{
private:
    char *infx;  // pointer to store infix expression
    char *pfx;   // pointer to store postfix expression
    char *stack; // pointer to store stack contents
    int top;     // top pointer
public:
    infixToPostfix(); // constructor
    void getInfix();
    void showInfix();
    void showPostfix();
    void push(char ele);
    char pop();
    void convertToPostfix();
    int precedence(char);
    ~infixToPostfix();
};

infixToPostfix::infixToPostfix(void) // constructor
{
    top = -1;             // initializing top with -1 (stack is empty)
    infx = new char[100]; // allocating memory for infix expression dynamically
    pfx = new char[100];  // allocating memory for postfix expression dynamically
    stack = new char[10]; ////allocating memory for stack dynamically
}

// to read infix expression

void infixToPostfix::getInfix()
{

    cout << "Please enter infix expression:";

    cin >> infx;
}

// to read postfix expression

void infixToPostfix::showInfix()
{
    cout << endl
         << " The given Infix Expression: " << infx << endl;
}

// converts infix expression into postfix expression

void infixToPostfix::convertToPostfix()
{
    int i, j;
    char ch;
    j = 0;

    for (i = 0; *(infx + i) != '\0'; i++) // iterate untill end of infix expression
    {

        if (isalnum(*(infx + i))) // checks if it is an operand
        {
            pfx[j] = *(infx + i); // assining character to postfix expression
            j++;
        }

        else if (*(infx + i) == '(') // checks it is a '('
            push(*(infx + i));       // push it onto the stack

        else if (*(infx + i) == ')') // checks it is a ')'
        {
            while ((ch = pop()) != '(') // pop elements from stack untill left brace is reached
            {

                pfx[j] = ch; // store element into postfix expression

                j++;
            }
        }
        else // operator
        {

            while (precedence(*(infx + i)) <= precedence(stack[top]) && top != -1)
            // precedence of stack[top] should be greater than or equal to precendence of infix[i] and stack should not be empty

            {
                ch = pop(); // pop elements for stack and assign to postfix expression

                pfx[j] = ch;
                j++;
            }
            push(*(infx + i)); // push infix[i] onto the stack
        }
    }
    // check stack is empty or not
    // if stack is not empty pop elements for stack and assign it to postfix expression
    while (top != -1)
    {
        ch = pop();

        pfx[j] = ch;
        j++;
    }

    pfx[j] = '\0';
}

// display's postfix expression

void infixToPostfix::showPostfix()
{
    cout << "Postfix Expression: " << pfx;
}

void infixToPostfix::push(char ele)
{
    if (top == 9) // if stack is full
    {
        cout << "overflow";
    }
    else
    {
        // increase top by one position and insert element at that position
        top++;

        stack[top] = ele;
    }
} // end of push function

char infixToPostfix::pop() // pop function
{
    if (top == -1)
    {
        cout << "underflow";
        return -1;
    }
    else
    {
        char ch = stack[top];
        top--;
        return ch;
    }
} // end of pop()

int infixToPostfix::precedence(char ele) // to find precedence
{
    switch (ele)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
} // end of precedence

infixToPostfix ::~infixToPostfix() // destructor
{
    delete[] infx; 
    delete[] pfx;
    delete[] stack;
}