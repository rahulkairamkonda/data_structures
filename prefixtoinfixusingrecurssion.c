/*
 ============================================================================
 Name        : prefixtoinfixusingrecurssion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int isAlpha(char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return 1;
	return 0;
}
typedef struct stack {
	char data[10][200];
	int top;
} stk;

void push(stk*p, char str[10]) {

	if (p->top == 9) {
		printf("Stack is full");

	} else
		strcpy(p->data[++p->top], str);

}

char* pop(stk*p) {
	if (p->top != -1)
		return p->data[p->top--];
	else
		printf("Nothing to pop");
	return 0;
}
void stringRev(char *str) {
	int i, j, len;
	char temp;
	for (len = 0; str[len]; len++)
		;
	for (i = 0, j = len - 1; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
char* pretoin(stk **s, char* ch) {

	return 123;
}
int main(void) {
	char exp[100], temp[10];
	int i = 0;
	stk s1;
	s1.top = -1;
	printf("Enter the Prefix Expression:\n");
	scanf("%s", exp);
	stringRev(exp);
	pretoin(&s1, exp);
	printf("%s", &s1);
	return EXIT_SUCCESS;
}
