#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int char_num = 0;

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
	int end = 0;
	char value;
	List *pointlast = NULL;
	while (end == 0){
		value = getchar();
		if (value == '.') end = 1;
		pointlast = addList(value, pointlast);
	}
	while (pointlast != NULL) {
		printf("%c", pointlast->x);
		pointlast = pointlast->next;
	}
	return 0;
}


int main(void) {
	List *myList = newList();
	printf("\n");
	return 0;
}
		
