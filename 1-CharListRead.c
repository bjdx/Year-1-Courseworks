#include <stdio.h>
#include <stdlib.h>

typedef struct L {
  char     symbol;
  struct L *next;
} listelem;


listelem *insert_list(char c, listelem *p) {
  listelem *temp = calloc(1,sizeof(listelem));

  temp->symbol = c;
  temp->next = p;
  return temp;
}


listelem *read_list( void ) {
  char c;
  listelem *lp = NULL;

  c = getchar();   
  while (c != '.') {
    lp = insert_list(c,lp);
    c = getchar(); 
  }
  return lp;
}

void find_same_char(listelem *lp){
	char select = 0;
	int count = 0;
	listelem *temp = NULL;
	
	while (lp->next != NULL) {
		if (count == 0){
			select = lp->symbol;
			lp = lp->next;
			count++;
		}else{
			if (select == lp->symbol) printf("%d\n", count);
			select = lp->symbol;
			lp = lp->next;
			count++;
		}
	} 
	if (select == lp->symbol) printf("%d\n", count);
}

int main( void ) {
  listelem *lp = read_list();
  find_same_char(lp);


  return 0;
}
