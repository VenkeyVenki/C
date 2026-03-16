/*Develop a Program in C for converting an Infix Expression to Postfix Expression. 
Program should support for both parenthesized and free parenthesized expressions
 with the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.*/
 
#include <stdio.h>
#include <ctype.h>
#define MAX 20
int top = -1; 
char stack[MAX];
void push(char ele) 
{
    if (top == MAX - 1)
        printf("\nStack Overflow!!!");
else 
{
        top = top + 1;
        stack[top] = ele;
    }
}

char pop() 
{
    char del;
if (top == -1) 
{
        printf("\nStack Underflow!!!");
        return '\0'; 
} 
else
{
        del = stack[top];
        top = top - 1;   
        return del;
    }
}
int priority(char c) {
    if (c == '(')
        return 1;
    else if (c == '+' || c == '-')
        return 2;
    else if (c == '*' || c == '/' || c == '%')
        return 3;
    else if (c == '^')
        return 4;
    else
        return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i;     
    int j = 0;  
    printf("\nEnter the Infix Expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) { 
            postfix[j++] = infix[i]; 
        } else if (infix[i] == '(' ) { 
            push(infix[i]); 
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop(); 
            }
            top--;        
        } else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; 
    printf("\nThe Postfix Expression is: %s\n", postfix);

    return 0;
}