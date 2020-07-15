#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[]){
	
	if(argc != 3){
		printf("Please provide two values to generate a code!\r\nExample: ./control-flow-1 100 4300\r\n");
		return -1;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = a+b;
	if(!(a > b)){
		printf("First check failed, try again!\r\n");
		return -1;
	}
	b += b;
	if( b < a){
		printf("Second check failed, try again!\r\n");
		return -1;
	}
	if((c-a) < 100){
		printf("Third check failed, try again!\r\n");
		return -1;
	}
	printf("Proper values provided! Great work!\r\n");
	
	return 0;
}
