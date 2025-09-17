#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//printer pool
//speed 30ppm

#define MAX 10

struct printer
{
	char name[20];
	int pageCount;
};

struct printer printerQueue[MAX];

int front = -1 ;
int rear = -1 ;

int isFull(){
	return ((rear + 1) % MAX == front);
}

int isEmpty(){
	return (front == -1);
}

void enqueue(char name[],int val){

	if (isFull())
	{
		printf("Queue is full....\n");
		return;
	}

	if (isEmpty())
	{
		front = rear = 0; 
	}else {
		rear = (rear + 1 ) % MAX ;
	}

	strcpy(printerQueue[rear].name, name) ;
	printerQueue[rear].pageCount = val;
}

struct printer dequeue(){

	if (isEmpty())
	{
		printf("Queue is Empty...\n");
	}
	struct printer temp = printerQueue[front];

	if (front == rear)
	{
		front = rear = -1 ;
	}else{
		front = (front + 1) % MAX ;
	}
		
	return temp;
}

void addPrint();
void check();

int main(){

	int choice ;

	do{
		printf("\n---------Menu------------\n");
		printf("1. Add new print \n");
		printf("2. Currently printing details \n");
		printf("3. Check Waiting time \n");
		printf("4. Most Waiting person \n");
		printf("5. Exit \n");

		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice){
			case 1 :
				addPrint();
				break ;
			case 2 :
				if (isEmpty())	
				{
					printf("No job is Currently printing...\n");
				} else {
					struct printer temp = dequeue();
					printf("%s is Currently printing %d pages",temp.name,temp.pageCount);

				}
				
				break ;
			case 3 :
				check();
				break ;
			case 4 :
				if (isEmpty()) {
   					printf("No one is in the queue.\n");
				} else {
				    printf("%s has been waiting the longest.\n", printerQueue[rear].name);
				}

				break ;
			default :
				printf("Invalid choice..try again.....\n");
				break;
		}
	}while(choice != 5);

	

	return 0 ;
}

void addPrint(){

	char name[20];
	int pageCount ;

	printf("Enter the Name of the teacher : " );
	scanf("%s",name);

	printf("Enter the No : of pages : ");
	scanf("%d",&pageCount);


	enqueue(name,pageCount);

}

void check(){

	char name[20]; 
	printf("Enter the name of the teacher : ");
	scanf("%s",name);

	int time = 0;
	int temp = front;
	int found = 0;

	while (1) {
	    if (strcmp(printerQueue[temp].name, name) == 0) {
	        found = 1;
	        break;
	    }

	    time += printerQueue[temp].pageCount;

	    if (temp == rear) break;  // prevent infinite loop
	    temp = (temp + 1) % MAX;
	}

	if (!found) {
	    printf("%s is not found in the queue.\n", name);
	} else if (temp == front) {
	    printf("No Waiting time Needed...\n");
	} else {
	    printf("%s needs to wait for %d seconds\n", name, time / 30);
	}


}
