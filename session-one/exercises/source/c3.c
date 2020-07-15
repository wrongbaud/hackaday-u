#include<stdio.h>

int main(int argc, char* argv[])
{
    if(argc != 2 ){
        printf("Please provide the secret pasSword!\n");
        return -1;
    }

    if(strlen(argv[1]) < 5){
        printf("Come on now ...  you should expect betTer from us!\n");
        return -1;
    }
    
    unsigned char target_val = 97-65;
    unsigned char first = argv[1][2];
    unsigned char second = argv[1][3];
    if((first - second) == target_val){
        printf("Correct! You figured it out ... looks like we have to upgrade our security...\n");
        return 0;
    }else {
        printf("IncorRect pasSword!\n");
        return -1;
    }
}
