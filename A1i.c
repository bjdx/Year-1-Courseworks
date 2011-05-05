

/* Barney Dennis, bd0906, version A */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
	int input[2];
	int num[41];
	int i = 0;
	int count = 0;

	
	while (count < 41){
		scanf("%d", input);
		num[i] = input[0];
		count++;
		i++;
		if (input[0] <1) break;
	}

	i = 0;
	
	while(i!=count){
		printf("%d\n", (num[i]-count) );
		i++;
	}
}




