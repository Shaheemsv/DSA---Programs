#include <stdio.h>

struct poly  	
{
	int coef;
	int deg;
};

// function to display polynomial
void displayPolynomial(struct poly arr[],int limit){
	for (int i = 0; i < limit ; ++i)
	{
		if(arr[i].deg == 0){
			printf("%d ", arr[i].coef);
		}else{
			printf("%dX^%d ",arr[i].coef,arr[i].deg);
		}
		
		if (i!=limit-1)
		{
			printf("+ ");
		}
	}
	printf("\n");
}

// function to read elements
void readElements(struct poly readPoly[],int limit){

	printf("\nEnter terms as  (ceof  deg) :  \n");
	for(int i = 0; i < limit; i++){
		printf("coefficient : ");
		scanf("%d", &readPoly[i].coef);

		printf("degree : ");
		scanf("%d", &readPoly[i].deg);

		while(readPoly[i].coef > 2 || readPoly[i].deg > 6){
			if(readPoly[i].coef > 2 ){
				printf("coefficient is out of bound...\ntry again...\nEnter coeff (range : 0-2) : ");
				scanf("%d",&readPoly[i].coef);
			}

			if (readPoly[i].deg > 6)
			{
				printf("degree is out of bound...\ntry again...\nEnter degree (range 0-6) : ");
				scanf("%d",&readPoly[i].deg);
			}
			if (readPoly[i].coef <= 2 || readPoly[i].deg <=6 )
			{
				printf("\nEnter next term \n");
			}
		}
	}

}

void sortPolynomials(struct poly arr[],int limit){

	struct poly temp ;

	for (int i = 0; i < limit-1; i++ )
	{
		for(int j = i+1; j < limit; j++ ){
			if (arr[i].deg < arr[j].deg)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}

void finalizedResult(struct poly result[],int limit){
	for (int i = 0; i < limit ; ++i)
	{
		if(result[i].deg == 0){
			printf("%d ", result[i].coef % 3);
		}else{
			printf("%dX^%d ",result[i].coef % 3 ,result[i].deg);
		}
		
		if (i!=limit-1)
		{
			printf("+ ");
		}
	}
	printf("\n");
}

// function for polynomial addition
void addPolynomials(struct poly firstPoly[], int firstPolyLimit, struct poly secondPoly[], int secondPolyLimit, struct poly sumPoly[]){

	int firstPolyIndex = 0, secondPolyIndex = 0, sumPolyIndex = 0; // initialized starting index of each polynomials

	while(firstPolyIndex < firstPolyLimit && secondPolyIndex < secondPolyLimit){  // loop until it reach the limit

		if(firstPoly[firstPolyIndex].deg == secondPoly[secondPolyIndex].deg ){   // incase of both polynomials have same degree
			sumPoly[sumPolyIndex].coef = firstPoly[firstPolyIndex].coef + secondPoly[secondPolyIndex].coef;
			sumPoly[sumPolyIndex].deg = firstPoly[firstPolyIndex].deg;
			firstPolyIndex++; secondPolyIndex++; sumPolyIndex++;
		}
		else if(firstPoly[firstPolyIndex].deg > secondPoly[secondPolyIndex].deg )	// when firstpolynomial with higher degree
		{  
			sumPoly[sumPolyIndex].coef = firstPoly[firstPolyIndex].coef ;
			sumPoly[sumPolyIndex].deg = firstPoly[firstPolyIndex].deg;
			firstPolyIndex++; sumPolyIndex++;
		}
		else if (secondPoly[secondPolyIndex].deg > firstPoly[firstPolyIndex].deg )	// second polynomial with higher degree
		{
			sumPoly[sumPolyIndex].coef = secondPoly[secondPolyIndex].coef;
			sumPoly[sumPolyIndex].deg = secondPoly[secondPolyIndex].deg;
			secondPolyIndex++; sumPolyIndex++;
		}
	}
	// To add the remaining terms in the polynomials
	while (firstPolyIndex < firstPolyLimit){
		sumPoly[sumPolyIndex].coef = firstPoly[firstPolyIndex].coef ;
		sumPoly[sumPolyIndex].deg = firstPoly[firstPolyIndex].deg;
		firstPolyIndex++; sumPolyIndex++;
	}
	while(secondPolyIndex < secondPolyLimit){
		sumPoly[sumPolyIndex].coef = secondPoly[secondPolyIndex].coef;
		sumPoly[sumPolyIndex].deg = secondPoly[secondPolyIndex].deg;
		secondPolyIndex++; sumPolyIndex++;	
	}

	printf("\nResulting polynomial : ");
	displayPolynomial(sumPoly,sumPolyIndex);  // to display result
	printf("\nFinal Result : ");
	finalizedResult(sumPoly,sumPolyIndex);

}



int main (){

	// only allowed coefficient value are 0, 1, 2 and degree is atmost 6.
	int limit_p1, limit_p2 ;

	printf("\nEnter the limit of first polynomial : \n");
	scanf("%d",&limit_p1);	 // limit of first polynomial
	
	struct poly k[limit_p1]; 	 // first polynomial k[x]
	readElements(k,limit_p1);	

	printf("\nEnter the limit of second polynomial : \n");
	scanf("%d",&limit_p2);	 // limit of first polynomial
	
	struct poly m[limit_p2]; 	 // first polynomial k[x]
	readElements(m,limit_p2);

	printf("\nFirst polynomial k[x] : " );
	sortPolynomials(k,limit_p1);
	displayPolynomial(k,limit_p1);

	printf("Second polynomial m[x] : ");
	sortPolynomials(m,limit_p2);
	displayPolynomial(m,limit_p2);

	int maxSize = limit_p1 + limit_p2; 
	struct poly c[maxSize];

	addPolynomials(k,limit_p1, m, limit_p2, c);  //function call

	return 0 ;
}