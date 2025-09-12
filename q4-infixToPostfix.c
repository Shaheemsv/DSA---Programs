#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 20
char stack[MAX];
int top = -1 ;

void push(char val){
	if (top >= MAX-1){
		printf("Stack Overflow...\n");
		exit(1);
	}
	stack[++top]=val;
}

char pop(){
	if (top == -1){
		printf("Stack Underflow..\n");
		exit(1);
	}
	return stack[top--];
}

int precedence (char c ){
	switch(c){

		case '^' :
			return 3 ;
		case '*':
		case '/':
			return 2 ;
		case '+':
		case '-': 
			return 1 ;
		default :
			return 0 ;
	}
}

int postfixStack[MAX];
int postfixTop = -1 ;

void pushVal(int val){
	postfixStack[++postfixTop]=val ;
}

int popVal(){
	return postfixStack[postfixTop--];
}

void infixToPostfix (char infixExp[], char postfixExp[] ){

	int i = 0, j = 0 ;  // i for infix expression index , j for postfix expression index


	while (infixExp[i]!='\0'){
		char ch = infixExp[i];

		if(isalnum(ch))
			postfixExp[j++]=ch;
		else if (ch == '(')
			push(ch);
		else if (ch == ')'){
			char c = pop();
			while (c != '('){
				postfixExp[j++] = c ;
				c = pop();
			}
		}
		else {
			while (precedence(stack[top]) >= precedence(ch)){
				postfixExp[j++] = pop();
			}
			push(ch);

		}
		
		i++;

	}
	while(top != -1)
		postfixExp[j++]=pop();

	postfixExp[j]='\0';

}


void postfixEvaluation(char postfixExp[]){

	
	printf("\npostfix Expression : %s\n",postfixExp);

	int i = 0, j = 0;
	int val , result = 0 ;

	while(postfixExp[i]!='\0'){
		char ch = postfixExp[i];
		if(isalpha(ch)){
			printf("Enter value for %c : ",ch);
			scanf("%d",&val);
			pushVal(val);
		}
		else{
			
			int a = popVal();
			int b = popVal();

			switch(ch){
				case '+' : 
					result = b+a ;
					break;
				case '-' : 
					result = b-a ; 
					break;
				case '*' : 
					result = b*a ; 
					break;
				case '^' : 
					result = (int)pow(b, a);
					break;
				case '/' : 
					if(a==0){
						printf("Math error.. \n");
						exit(0);
					} 
					else
						result = b/a ;
					break;
			}
			pushVal(result);
		}
		i++;
	}

	printf("\nPostfix evaluation \nAnswer : %d \n",popVal());
	top = postfixTop = -1 ;

}


int main()
{

	int choice ;
	char infixExp[30] ; 
	char postfixExp[30] ;

	do{

		printf("\n.......Menu.......\n");
		printf("1. infix to postfix conversion \n");
		printf("2. postfix evaluation \n");
		printf("3. exit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch (choice){

			case 1 :
				printf("\nEnter the infix Experssion  : ");
				scanf("%s",infixExp);
				infixToPostfix(infixExp, postfixExp);
				printf("\nEntered infix Experssion : %s",infixExp);
				printf("\nCorresponding postfix Expression : %s \n",postfixExp);


				break ;
			case 2 :

				postfixEvaluation(postfixExp);
				break ;
			case 3 :
				exit(0);
				break ;
			default :
				printf("Invalid input try again.....\n");
				break ;
		}
	}while(choice!=4);
	
	return 0;
}
