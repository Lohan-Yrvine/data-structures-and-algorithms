#include <stdio.h>
#include <stdbool.h>

#include "implementation/stack.h"

bool valid_parentheses(char s[], int length)
{
    struct stack *st = new_stack();

    if (length % 2 == 1)
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (is_empty(st) && s[i] == ')')
        {
            return false;
        }
        else if (s[i] == '(')
        {
            push(st, '(');
        }
        else if (s[i] == ')' && peek(st) == '(')
        {
            pop(st);
        }
    }

    if (is_empty(st))
    {
        return true;
    }

    return false;
}

int main(void)
{
    char s1[] = "()(())";
    char s2[] = "())";
    char s3[] = "((()))(())()";

    printf("%d\n", valid_parentheses(s1, 6));
    printf("%d\n", valid_parentheses(s2, 3));
    printf("%d\n", valid_parentheses(s3, 12));

    return 0;
}
