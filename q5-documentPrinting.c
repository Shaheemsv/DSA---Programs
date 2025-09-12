#include <stdio.h>
#include <stdlib.h>

//printer pool
//speed 30ppm

#define MAX 10
int prizePoolQueue[MAX];

struct print
{
	char name[20];
	int pageCount;
};


int rear = front = -1 ;

void enqueue(int val){
	if(rear == -1){
		rear = front = 0 ;
	}
	rear = (rear + 1) % MAX ;
	prizePoolQueue[rear];;
}

int dequeue(){
	front = (front + 1) % MAX ;
	return prizePoolQueue[front];
}

int main(){

	int choice ;

	printf("\n---------Menu------------\n");
	printf("1. Add new print \n");
	printf("2. Currently printing details \n");
	printf("3. Check Waiting time \n");
	printf("4. Most Waiting person \n");

	printf("Enter your choice : ");
	scanf("%d", &choice);

	switch(choice){
		case 1 :
			addPrint();
			break ;
		case 2 :
			break ;
		case 3 :
			break ;
		case 4 :
			break ;
		default :
			printf("Invalid choice..try again.....\n");
			break;
	}

	

	return 0 ;
}

void addPrint(){

	printf("Enter the Name of the teacher : " );
	gets(name);

	printf("Enter the No : of pages : ");
	scanf("%d",&pageCount);




}
