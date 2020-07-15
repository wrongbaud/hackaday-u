#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum months{jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};

struct userinfo {
    int key;
    char dontUse;
    char *username;
    char *password;
    int realKey;
    int (*calc)(int a, int b);
};

void swapNames(char *a, char*b){
    char *tmp = malloc(sizeof(a));
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int keyCalc(int a, int b){
    return ((a+b) << 3);
}

int gen_password(struct userinfo* info){
    int count = strlen(info->username);
    int x = 0;
    char * pass = malloc(count);
    for(x = 0; x < count; x++){
        pass[x] = ((char)info->username[x] + (char)info->key)^ (char)info->realKey;
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
    info.calc = &keyCalc;
    info.realKey = info.calc(info.key,info.key + 0xBEEF);
    info.username = username;
    info.password = password;
    swapNames(&info.username,&info.password);
    printf("Username: %s, Password: %s\r\n",info.username,info.password);
    gen_password(&info);
    if(strcmp(password,info.password)!=0){
        printf("Invalid password provided, try again!\r\n");
        free(info.password);
        return -1;
    }
    printf("Correct! Access granted!\r\n");
    free(info.password);
    return 0;
}
