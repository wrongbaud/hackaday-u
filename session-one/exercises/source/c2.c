#include<stdio.h>

int main(int argc, char** argv)
{
   if(argc !=2) {
        printf("Please supply the password!\r\n");
        return -1;
    }

    if(strlen(argv[1]) < 5){
        printf("We'd never use a password that short!\n");
        return -1;
    }
    if(argv[1][0] == 'h' && argv[1][4] == 'u'){
        printf("Correct -- maybe we should pay attention to more characters...\n");
        return 0;
    }else{
        printf("Wrong answer! Try again\n");
        return -1;
    }
}
