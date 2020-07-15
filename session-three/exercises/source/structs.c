#include<stdio.h>
#include<string.h>
#include<stdlib.h>



struct userinfo {
    int key;
    char dontUse;
    char* username;
    char *password;
    int realKey;
};

int add(int a, int b){
    return a+b;
}

int gen_password(struct userinfo* info){
    int count = strlen(info->username);
    int x = 0;
    char * pass = malloc(count);
    for(x = 0; x < count; x++){
        pass[x] = (char)info->username[x] ^ (char)info->key;
        pass[x] = pass[x] - 0x13;
    }
    info->password = pass;
    return 0;
}
    
int main(int argc, char * argv[])
{
    struct userinfo info;
    int key = 0;
    char *username;
    char *password;

    if(argc != 4){
        printf("Please provide your key, username and password!\r\nExample: 12738 wrongbaud P@55W0rd1\r\n");
        return -1;
    }

    key = atoi(argv[1]);
    if(!key){
        printf("Improper key provided, please provide and integer key!\r\n");
        return -1;
    }
    username = argv[2];
    if((strlen(username) > 0x255) || (strlen(username) < 8)){
        printf("Improper username provided, please check the length!\r\n");
        return -1;
    }
    password = argv[3];
    if((strlen(password) > 0x255) || (strlen(password) < 8)){
        printf("Improper password provided, please check the length!\r\n");
        return -1;
    }
    info.key = key;
    info.realKey = add(info.key,info.key);
    info.username = username;
    gen_password(&info);
    int pwordLen = 0;
    for(pwordLen = 0; pwordLen < strlen(info.password);pwordLen++ ){
        if(password[pwordLen] != info.password[pwordLen]){
            printf("Invalid character in password detected, exiting now!\r\n");
            return -1;
        }
    }
    printf("Correct! Access granted!\r\n");
    free(info.password);
    return 0;
}
