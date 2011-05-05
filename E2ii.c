/*Barney Dennis, bd0906,  version E */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
	char sent[256];
	int i = 0;
	int temp = 0;
	int hold = 0;
	int end = 0;


	while (end < 3) {
		sent[i] = getchar();
		if ((sent[i] == '\n') || (sent[i] == ' ')) end++;
		i = i++;
	}
	
	i = 0;

	while (i<=256){
		if ((sent[i] == '\n') || (sent[i] == ' ')){
			temp = i;
			i = i--;
			for (; i >= hold; i--){
				printf("%c", sent[i]);
			}
			printf(" ");
			i = temp+1;
			hold = i;
		
		}else{
			i = i++;
		}
	}
	printf("\n");
}
