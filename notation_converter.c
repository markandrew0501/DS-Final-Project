/* Notation Converter CLI:
   This project converts math expressions (infix, prefix, postfix) using
   expression trees.  It supports +, -, *, /, 0-9 operands.

   Discrete Structures 2 - Bicol University College of Science
   Bongon, Mark Andrew
   Callos, Maria Dorothy
   Pielago, Salve Adelle
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h> // for getopt

#define MAX_EXPR_LEN 1024

typedef struct Node {
  char value;
  struct Node *left, *right;
} Node;

typedef struct Stack {            // stack for tree nodes
  Node *data[MAX_EXPR_LEN];
  int top;
} Stack;

void initStack(Stack *stack) {    // initial stack
  stack->top = -1;
}

int isEmpty(Stack *stack) {       // check if stack is empty
  return stack->top == -1;
}

void push(Stack *stack, Node *node) {   //push to stack
  if (stack->top < MAX_EXPR_LEN - 1)
      stack->data[++stack->top] = node;
}

Node* pop(Stack *stack) {         //pop top of stack
  if (!isEmpty(stack))
      return stack->data[stack->top--];
  return NULL;
}

Node* createNode(char value) {    //create nodes
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->left = node->right = NULL;
  return node;
}

int precedence(char op) {         //operator precedence (+-,*/)
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

int isOperator(char c) {         //check if character is operator
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isOperand(char c) {         //check if character is operand
  return (c >= '0' && c <= '9');
}


void printHelp() {              // CLI Help
  printf("Usage:\n");
  printf("notation-converter --from [infix|prefix|postfix] --to [infix|prefix|postfix] \"expression\"\n");
  printf("Options:\n");
  printf("  -h, --help        Show help message\n");
  printf("  --guide           Show detailed guide\n");
}

void printGuide() {           // CLI Help
  printf("Guide:\n");
  printf("- Infix: 3 + 4 * 2\n");
  printf("- Prefix: + 3 * 4 2\n");
  printf("- Postfix: 3 4 2 * +\n");
  printf("Conversions:\n");
  printf("Example: notation-converter --from infix --to postfix \"3 + 4 * 2\"\n");
  printf("Result: 3 4 2 * +\n");
}

int main(int argc, int *argv[]){
  char *from = NULL, *to = NULL, *expression = NULL;

  if (argc < 2) {
    printHelp();
    return 1;
  }

  for (int i = 1; i < argc; i++) {        //store each argument into from, to, or expression
    if (!strcmp(argv[i], "--from")) {
        from = argv[++i];
    } else if (!strcmp(argv[i], "--to")) {
        to = argv[++i];
    } else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
        printHelp();
        return 0;
    } else if (!strcmp(argv[i], "--guide")) {
        printGuide();
        return 0;
    } else if (argv[i][0] != '-') {
        expression = argv[i];
    }
  }

  printf("Hello, World");
  printf("TEST!");
  printf("test s\n");
  return 0;
}