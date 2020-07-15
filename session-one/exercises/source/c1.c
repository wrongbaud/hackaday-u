#include<stdio.h>

int main(int argc, char** argv)
{
   if(argc !=2) {
        printf("Please supply the password!\r\n");
        return -1;
    }

    char* pword = "hackadayu"; 
    if(strncmp(argv[1],pword,strlen(pword))){
        printf("Wrong answer, we'd never use %s as the password!\r\n",argv[1]);
        return -1;
    }else {
        printf("Correct! The password was %s this whole time!\r\n",argv[1]);
        return 0;
    }
}
