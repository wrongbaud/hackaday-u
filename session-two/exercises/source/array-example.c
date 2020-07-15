#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * keywords[] = {"hackadayu","software","reverse","engineering","ghidra"};
unsigned char bytecodes[] = {0xC6,0x44,0xC5,0xe3,0xe6};

int main(int argc, char *argv[]){
	
	if(argc != 3){
		printf("Please provide a password index and keycode, ex: 1 p@55w0rd!\r\n");
		return -1;
	}
    int index = atoi(argv[1])+1;
    if(!index || index > 5){
        printf("Improper index provided, try again!\r\n");
        return -1;
    }
    unsigned char keycode = bytecodes[index-1];
    int pwdLen = strlen(keywords[index-1]);
    int count = 0;
    for(count;count<pwdLen;count++){
        char targetVal;
        char curChar = keywords[index-1][count];
        char nxtChar;
        if(count == (pwdLen-1)) { 
            nxtChar = keywords[index-1][0];
        }else{
            nxtChar = keywords[index-1][count+1];
        }
        if (curChar > nxtChar){
            targetVal = ((curChar - nxtChar) + 0x60);
        }else{
            targetVal = ((nxtChar-curChar) +0x60);
        }
        if((char)targetVal != (char)(argv[2][count])){
            printf("Wrong value detected at character %x!\r\n",count);
            return -1;
        }
    }
    printf("Congratulations, you've unlocked the code for value %x, can you get them all?\r\n",index);
}
