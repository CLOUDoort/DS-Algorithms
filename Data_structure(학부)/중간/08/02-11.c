#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;

precedence stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
char postfix_expr[MAX_EXPR_SIZE];
int top = -1;
int cnt = 0;
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};

void push(precedence token);
precedence pop();
void printToken(precedence token);
void postfix();
precedence getToken(char *symbol, int *n);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    fscanf(fp, "%s", expr);
    postfix();

    fclose(fp);
    return 0;
}

precedence getToken(char *symbol, int *n) {
    *symbol = expr[(*n)++];
    switch(*symbol) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}

void printToken(precedence token) {
    switch(token) {
        case 0: {
            printf("( ");
            postfix_expr[cnt++] = '(';
            break;
        }
        case 1: {
            printf(") ");
            postfix_expr[cnt++] = ')';
            break;
        }
        case 2: {
            printf("+ ");
            postfix_expr[cnt++] = '+';
            break;
        }
        case 3: {
            printf("- ");
            postfix_expr[cnt++] = '-';
            break;
        }
        case 4: {
            printf("* ");
            postfix_expr[cnt++] = '*';
            break;
        }
        case 5: {
            printf("/ ");
            postfix_expr[cnt++] = '/';
            break;
        }
        case 6: {
            printf("%% ");
            postfix_expr[cnt++] = '%';
            break;
        }
        default: break;
    }
}

void postfix() {
    char symbol; precedence token;
    int n = 0; int top = 0;
    stack[0] = eos;
    for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
        if(token == operand) {
            printf("%c ", symbol);
            postfix_expr[cnt++] = symbol;
        }
        else if(token == rparen) {
            while(stack[top] != lparen) {
                printToken(pop());
            }
            pop();
        }
        else {
            while(isp[stack[top]] >= icp[token]) {
                printToken(pop());
            }
            push(token);
        }
    }
    while((token = pop()) != eos) printToken(token);
    printf("\n"); 
}

void push(precedence token) {
    if(top >= MAX_STACK_SIZE-1) {
        printf("FUll\n");
        exit(1);
    }
    stack[++top] = token;
}
precedence pop() {
    if(top < 0) {
        printf("Empty\n");
        exit(1);
    }
    return stack[top--];
}