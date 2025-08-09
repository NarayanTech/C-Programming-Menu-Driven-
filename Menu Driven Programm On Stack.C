#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <conio.h>

#define MAX 100

// Stack Structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Stack Functions
void push(Stack *s, char item) {
    if (s->top == MAX - 1) {
	printf("Stack Overflow\n");
	return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (s->top == -1) {
	printf("Stack Underflow\n");
	return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (s->top == -1)
	return '\0';
    return s->items[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}
   int i=0,j=0,A,B,result,value;
   char ch,elem;

// 1. Recursion Functions
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
	printf("\nMove disk 1 from rod %c to %c\n", from_rod, to_rod);
	return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("\nMove disk %d from rod %c to %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int fact(int n) {
    return (n <= 1) ? 1 : n * fact(n - 1);
}

// 2. Postfix Expression Evaluation
int evaluatePostfix(char postfix[]) {
    Stack s;
    s.top = -1;

    for (i = 0; i < strlen(postfix); i++) {
	char ch = postfix[i];

	if (isdigit(ch)) {
	    push(&s, ch - '0');  // Convert char to integer and push
	} else if (isalpha(ch)) { // Check if ch is a variable (a-z, A-Z)
	    printf("Enter the value of %c: ", ch);
	    scanf("%d", &value);
	    push(&s, value); // Push the user-provided integer
	} else {
	    // Ensure there are at least two operands in the stack before popping
	    if (s.top < 1) {
		printf("Error: Invalid postfix expression\n");
		return -1;
	    }
	    A = pop(&s);
	    B = pop(&s);

	    switch (ch) {
	    case '^':
		result = pow(B, A);
		break;
	    case '*':
		result = B * A;
		break;
	    case '/':
		if (A == 0) {
		    printf("Error: Division by zero\n");
		    return -1;
		}
		result = B / A;
		break;
	    case '+':
		result = B + A;
		break;
	    case '-':
		result = B - A;
		break;
	    default:
		printf("Error: Invalid operator '%c'\n", ch);
		return -1;
	    }
	    push(&s, result);
	}
    }

    // Check if only one result remains in the stack
    if (s.top != 0) {
	printf("Error: Invalid postfix expression\n");
	return -1;
    }

    return pop(&s);
}


// 3. Infix to Postfix Conversion
int priority(char elem) {
    if (elem == '+' || elem == '-') return 1;
    if (elem == '*' || elem == '/') return 2;
    if (elem == '^') return 3;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    s.top = -1;

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s); // Remove '('
        } else {
            while (!isEmpty(&s) && priority(peek(&s)) >= priority(ch))
                postfix[j++] = pop(&s);
            push(&s, ch);
        }
    }

    while (!isEmpty(&s))
        postfix[j++] = pop(&s);

    postfix[j] = '\0';
}

// 4. Parenthesis Matching
int isBalanced(char *exp) {
    Stack s;
    s.top = -1;


    for ( i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];
        if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            if (isEmpty(&s))
                return 0;
            pop(&s);
        }
    }
    return isEmpty(&s);
}

// Recursion Menu
void recursionMenu() {
    int choice, num, a, b;
    do {
        printf("\n======================================\n");
        printf("\n          RECURSION-MENU              \n");
        printf("\n======================================\n");
        printf("\n1. Tower of Hanoi\n");
        printf("2. GCD of Two Numbers\n");
        printf("3. Factorial of a Number\n");
        printf("4. Back to Main Menu\n");
        printf("\n=====================================\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of Disks: ");
            scanf("%d", &num);
            towerOfHanoi(num, 'A', 'C', 'B');
            break;
        case 2:
            printf("Enter Two Numbers: ");
            scanf("%d %d", &a, &b);
            printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
            break;
        case 3:
            printf("Enter a Number: ");
            scanf("%d", &num);
            printf("Factorial of %d = %d\n", num, fact(num));
            break;
        case 4:
            return;
        default:
            printf("Invalid Choice! Try again.\n");
        }
    } while (choice != 4);
}

// Operations Menu
void operationsMenu() {
    int choice;
    char infix[MAX], postfix[MAX];

    do {
        printf("\n======================================\n");
        printf("\n          OPERATIONS-MENU             \n");
        printf("\n======================================\n");
        printf("\n1. Evaluate Postfix Expression\n");
        printf("2. Convert Infix to Postfix\n");
        printf("3. Check Parenthesis Matching\n");
        printf("4. Back to Main Menu\n");
        printf("\n=====================================\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a Postfix Expression: ");
            scanf("%s", postfix);
            printf("Postfix Evaluation Result: %d\n", evaluatePostfix(postfix));
            break;
        case 2:
            printf("Enter an Infix Expression: ");
            scanf("%s", infix);
            infixToPostfix(infix, postfix);
            printf("Postfix Expression: %s\n", postfix);
            break;
        case 3:
            printf("Enter an Expression: ");
            scanf("%s", infix);
            printf("The Expression is %sBalanced.\n", isBalanced(infix) ? "" : "Not ");
            break;
        case 4:
            return;
        default:
            printf("Invalid Choice! Try again.\n");
        }
    } while (choice != 4);
}

// Main Function
int main() {
    int choice;
    clrscr();
    do {
        printf("\n======================================\n");
        printf("\n          MAIN-MENU                   \n");
        printf("\n======================================\n");
        printf("\n1. Recursion Functions\n");
        printf("2. Other Operations\n");
        printf("3. Exit\n");
        printf("\n=====================================\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            recursionMenu();
            break;
        case 2:
            operationsMenu();
            break;
        case 3:
            printf("Exiting program.\n");
	    getch();
        default:
            printf("Invalid Choice! Try again.\n");
        }
    } while (choice != 3);
    return 0;
}