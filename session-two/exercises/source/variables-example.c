#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

char *globalVar = "KeYpress";
int64_t XorMe = 0xDEADBEEFFACECAFE;


int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Please prvide the 8 character keycode");
		return -1;
	}
	if(strlen(argv[1])<8){
		printf("Too short, try again!\r\n");
	}
	char *pass = argv[1];
	int index = 0;
	for(index = 0;index<8;index++){
		unsigned char cmpByte = (XorMe >> (index*8)) & (int64_t)0xFF;
		unsigned char targetVal = cmpByte - (~globalVar[index]);
		if((unsigned char)pass[index] != targetVal){
			printf("Improper character in keycode detected, try again!\r\n");
			return -1;
		}
	}
	printf("Proper keycode supplied, well done!\r\n");
	return 0;
}
