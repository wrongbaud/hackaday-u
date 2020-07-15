#include<stdio.h>

int main(int argc, char* argv[])
{
    char * pword = "hackaday-u";
    if(argc != 2 ){
        printf("Please provide the secret password!\n");
        return -1;
    }

    if(strlen(argv[1]) < 10){
        printf("Come on now ...  you should expect better from us!\n");
        return -1;
    }
    
    
    int x = 0;
    int len = strlen(argv[1]);
    for(x = 0; x < len; x++){
        if((pword[x] + 2) != argv[1][x]){
            printf("Wrong Password!\n");
            return -1;
        }
    }
    printf("Correct! You've entered the right password ... you're getting better at this!\n");
    return 0;
    
}
