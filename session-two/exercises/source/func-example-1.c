#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ASCII_CAP_START  0x41
#define ASCII_CAP_END  0x5A

#define ASCII_LOW_START  0x61
#define ASCII_LOW_END  0x7A

char*  getUpperCase(char *argString,char* uppercase){
	int argLength = strlen(argString);
	uppercase = calloc(argLength,sizeof(char));
	int counter = 0;
	int capIndex = 0;
	for(counter=0; counter < argLength; counter++){
		if((argString[counter] >= ASCII_CAP_START) && (argString[counter] <= ASCII_CAP_END)){
		uppercase[capIndex] = argString[counter];
		capIndex += 1;
	}
	}
	return uppercase;
}

char*  getLowerCase(char *argString,char* uppercase){
	int argLength = strlen(argString);
	uppercase = calloc(argLength,sizeof(char));
	int counter = 0;
	int capIndex = 0;
	for(counter=0; counter < argLength; counter++){
		if((argString[counter] >= ASCII_LOW_START) && (argString[counter] <= ASCII_LOW_END)){
		uppercase[capIndex] = argString[counter];
		capIndex += 1;
	}
	}
	return uppercase;
}


int main(int argc, char *argv[]){
	
	if(argc != 2){
		printf("Please generate a passcode for system usage!\r\n");
		return -1;
	}
	char *uppercase;	
	char *lowercase;	
	uppercase = getUpperCase(argv[1],uppercase);
	lowercase = getLowerCase(argv[1],uppercase);
	if(strlen(uppercase) != strlen(lowercase)){
		printf("Passcode doesn't have enough variety! Please try again\r\n");
		free(uppercase);
		free(lowercase);
		return -1;
	}else{
		printf("Passcode generator passed, good job!\r\n");
		free(uppercase);
		free(lowercase);
	}
	return 0;
}
