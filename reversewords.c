#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct mylist {
	char x ;
	struct mylist *next ;
} List ;


List *addList( char value, List *pointlast){
	List *pointnew = calloc (1, sizeof(List));
	pointnew->x = value; 
	pointnew->next = pointlast; 
	return pointnew;
}

List *newList(void) {
	List *temporig, *templp;
	int end = 0;
	int counter = 0; 
	int i = 0;
	char value;
	List *pointlast = NULL;
	do {
		value = getchar();
		if (value == '.'){
			end = 1;
			break;
		}
		pointlast = addList(value, pointlast);
	} while (end == 0);


	temporig = pointlast;

	
	while (pointlast->next != NULL){
		if (pointlast->x != '\n'){
			pointlast = pointlast->next;
			counter = counter +1;
		} else {
			templp = pointlast->next;
			pointlast = temporig ;
			while (counter > 0 ){
				while ( i < ( counter - 1 ) ){
					pointlast = pointlast->next;
					i = i + 1;
				}
				i = 0;
				printf("%c", pointlast->x);
				pointlast = temporig;
				counter = counter-1;
			}
			printf("\n") ;
			pointlast = templp;
			counter = 0 ;
			temporig = templp;
		}
	}
	
	counter = counter + 1;
	pointlast = temporig;
	while ( counter > 0 ) {
		while ( i < ( counter - 1 ) ) {
			pointlast = pointlast->next;
			i = i + 1;
		}
		i = 0;
		printf( "%c", pointlast->x );
		pointlast = temporig;
		counter = counter - 1;
	}
		
	return 0;
}


int main(void) {
	List *myList = newList();
	printf("\n");
	return 0;
}
		
