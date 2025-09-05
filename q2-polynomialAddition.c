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

	printf("Enter terms as  (ceof  deg) :  \n");
	for(int i = 0; i < limit; i++){
		scanf("%d %d", &readPoly[i].coef, &readPoly[i].deg);
	}

}

void addPolynomials(struct poly firstPoly[], int firstPolyLimit, struct poly secondPoly[], int secondPolyLimit, struct poly sumPoly[]){

	int firstPolyIndex = 0, secondPolyIndex = 0, sumPolyIndex = 0;

	while(firstPolyIndex < firstPolyLimit && secondPolyIndex < secondPolyLimit){

		if(firstPoly[firstPolyIndex].deg == secondPoly[secondPolyIndex].deg ){
			sumPoly[sumPolyIndex].coef = firstPoly[firstPolyIndex].coef + secondPoly[secondPolyIndex].coef;
			sumPoly[sumPolyIndex].deg = firstPoly[firstPolyIndex].deg;
			firstPolyIndex++; secondPolyIndex++; sumPolyIndex++;
		}
		else if(firstPoly[firstPolyIndex].deg > secondPoly[secondPolyIndex].deg ){
			sumPoly[sumPolyIndex].coef = firstPoly[firstPolyIndex].coef ;
			sumPoly[sumPolyIndex].deg = firstPoly[firstPolyIndex].deg;
			firstPolyIndex++; sumPolyIndex++;
		}
		else if (secondPoly[secondPolyIndex].deg > firstPoly[firstPolyIndex].deg )
		{
			sumPoly[sumPolyIndex].coef = secondPoly[secondPolyIndex].coef;
			sumPoly[sumPolyIndex].deg = secondPoly[secondPolyIndex].deg;
			secondPolyIndex++; sumPolyIndex++;
		}
	}

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

	displayPolynomial(sumPoly,sumPolyIndex);

}

int main (){

	// only allowed coefficient value are 0, 1, 2 and degree is atmost 6.
	int limit_p1, limit_p2 ;

	printf("Enter the limit of first polynomial : \n");
	scanf("%d",&limit_p1);	 // limit of first polynomial
	
	struct poly k[limit_p1]; 	 // first polynomial k[x]
	readElements(k,limit_p1);	

	printf("Enter the limit of second polynomial : \n");
	scanf("%d",&limit_p2);	 // limit of first polynomial
	
	struct poly m[limit_p2]; 	 // first polynomial k[x]
	readElements(m,limit_p2);

	printf("polynomial k[x] : " );
	displayPolynomial(k,limit_p1);

	printf("polynomial m[x] : ");
	displayPolynomial(m,limit_p2);

	int maxSize = limit_p1 + limit_p2;
	struct poly c[maxSize];

	addPolynomials(k,limit_p1, m, limit_p2, c);



	return 0 ;
}