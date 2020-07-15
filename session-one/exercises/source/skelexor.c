#include<stdio.h>
#include<string.h>

int main(int argc, char **argv)
{
	const char * skelekey = "skeletor";
	char  key[8]= {8,9,10,11,12,13,14,15};
	int x = 0;

	if(argc != 2){
		printf("Please provide the password to enter castle greyskull!\r\n");
		return 0;
	}

	if(strlen(argv[1]) < strlen(skelekey)){
		printf("Wrong length, better luck next time!\r\n");
		return -1;
	}
	
	for(x=0;x<8; x++){
		if((skelekey[x] ^ key[x]) != argv[1][x]){
			printf("Wrong answer\r\n");
			return -1;
		}
	}
	printf("Correct! You have the power!\r\n");

	return 0;
}
