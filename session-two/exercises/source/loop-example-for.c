#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ASCII_CAP_START  0x41
#define ASCII_CAP_END  0x5A

int main(int argc, char *argv[]){
	
	if(argc != 2){
		printf("Please provide a string!\r\n");
		return -1;
	}
	int argLength = strlen(argv[1]);
	if(argLength != 15){
		printf("Wrong length! Try again!\r\n");
		return -1;
	}
	int counter = 0;
	int capIndex = 0;
	for(counter=0; counter < argLength; counter++){
		if((argv[1][counter] >= ASCII_CAP_START) && (argv[1][counter] <= ASCII_CAP_END)){
		capIndex += 1;
	}
	}
	if(capIndex != 8){
		printf("Not quite what we're looking for ... maybe try again?\r\n");
	}else{
		printf("Congratulations, access granted!\r\n");
	}
	return 0;
}
