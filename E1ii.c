/*Barney Dennis, bd0906,  version E */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
	int average = 0;
	int numbers[11];
	int input[1];
	int i = 0;
	int high = 0;
	int low = 100000;
 	
	while (i<=10){
		scanf("%5d", input);
		numbers[i] = input[0];
		if (numbers[i] < low) low = numbers[i];
		if (numbers[i] > high) high = numbers[i];
		i = i++;
	}
	
	numbers[11] = '\0';
	i = 0;
	
	while (i<=10){
		average = average + numbers[i];
		i++;
	}
	
      	average = average - low - high;	
	average = (average/9);

	i = 0;
	
	while (i<=10){
		printf("%d\n", (numbers[i] - average));
		i++;
	}
}
