#include <stdio.h>
#include <string.h>

#define MAX 10
// cricular queue

struct ticket
{
	char name[20];
	int ticketCount;
	int tokenNumber;
};

struct ticket ticketQueue[MAX];
int front = -1 ;
int rear = -1 ;
int token = 1 ;

int isEmpty(){
	return (front==-1);
}
int isFull(){
	return ((rear + 1)%MAX ==front);
}

void enqueue(char name[] , int ticket , int token){
	if (isFull()) {
    printf("Queue is full.., insertion not possible... \n");
    return;
}


	if (isEmpty())
	{
		front = rear = 0 ;
	}else {
		rear = (rear + 1 ) % MAX ;
	}

	strcpy(ticketQueue[rear].name ,name) ;
	ticketQueue[rear].ticketCount = ticket;
	ticketQueue[rear].tokenNumber = token;

}

struct ticket dequeue(){
	if (isEmpty()) {
    printf("Queue is Empty...\nTickets are served...\n");
    struct ticket dummy = {"", 0, -1};
    return dummy;
}


	struct ticket temp = ticketQueue[front];

	if (front == rear)
	{
		front = rear = -1 ;
	}else {
		front = (front + 1 ) % MAX ; 
	}
	temp.ticketCount--;

	if (temp.ticketCount > 0)
	{
		enqueue(temp.name,temp.ticketCount,temp.tokenNumber);
	}


	return temp ;

}


void addCustomer();
void customerDetails();
int countCustomers();

int main(){

	int choice ;

	do{

		printf("---------MENU------------\n");
		printf("1.Add customer \n");
		printf("2.Serve tickets \n");
		printf("3.Current customer being served \n");
		printf("4.Number of customer waiting \n");
		printf("5.List of customers \n");
		printf("6.Exit \n");

		
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice){
			case 1 :
				addCustomer();
				break ;
			case 2 :
				struct ticket temp = dequeue();
				if (temp.tokenNumber != -1)
				{
					printf("Ticket served to %s\n", temp.name);

				}
				

				break ;
			case 3 :
				if (isEmpty())
				{
					printf("Queue is Empty...\n");
				}else{
					printf("Currentlty serving Customer => %s",ticketQueue[front].name);
				}
				break ;
			case 4 :
				if (isEmpty())
				{
					printf("Queue is Empty...\n");
					return 0;
				}
				printf("Customers waiting : %d",countCustomers());
				break ;
			case 5 :
				customerDetails();
				break ;
			case 6 :
				printf("Program exited....\n");
				break ;

		}

	}while(choice != 6);
5

	return 0 ;
}

void addCustomer(){

	char name[20];
	int ticket ;

	printf("Enter Name of customer : ");
	scanf("%s",name);
	printf("Number of ticket : ");
	scanf("%d",&ticket);


	enqueue(name,ticket,token++);

}

void customerDetails(){

	if (isEmpty())
	{
		printf("Queue is Empty...\n");
		return;
	}

	printf("\n--- Customer List ---\n");
	int i = front ;

	while(1){
		printf("Token No : %d - %s : %d tickets \n",
			ticketQueue[i].tokenNumber,
			ticketQueue[i].name,
			ticketQueue[i].ticketCount);


		if (i==rear)
			break;

		i = (i + 1) % MAX ;
	}

}

int countCustomers(){
	if (isEmpty())
		return 0 ;

	if(rear >= front)
		return rear - front + 1 ;

	return MAX - front + rear + 1 ;

}
