#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

struct userinfo {
    int key;
    char dontUse;
    char *username;
    int nameLen;
    char *password;
    int realKey;
    int (*calc)(int a, int b);
};

int keyCalc(int a, int b){
    return ((a+b) << 3);
}

int gen_password(struct userinfo* info){
    int x = 0;
    char * pass = malloc(info->nameLen);
    for(x = 0; x < info->nameLen; x++){
        pass[x] = ((char)info->username[x] + (char)info->key)^ (char)info->realKey;
        pass[x] = pass[x] - 0x13;
    }
    info->password = pass;
    return 0;
}
char * unameFile =  "uname.x";
char * keyFile = "key.y";
char * pwordFile = "pword.z";
    
int main(int argc, char * argv[])
{
    struct userinfo info;
    int key = 0;
    char *username;
    char *password;
    int bytesRead;
    int nameLen = 0;

    int keyFd = open(keyFile,O_RDONLY);
    if(keyFd == -1){
        printf("Could not find key file, please try again!\r\n");
        return -1;
    }else{
        bytesRead = read(keyFd,&key,4);
        if(bytesRead < 4){
            printf("Not enough values in keyfile, please try again!\r\n");
            return -1;
        }
    }
    info.key = key;

    
    int unameFd = open(unameFile,O_RDONLY);
    if(unameFd == -1){
        printf("Could not find username file, please try again!\r\n");
        return -1;
    }else{
        username = malloc(0x255);
        bytesRead = read(unameFd,username,0x255);
        if(bytesRead < 8){
            printf("Not enough values in username file, please try again!\r\n");
            return -1;
        }
        nameLen = bytesRead-1;
    }
    info.nameLen = nameLen;

    int pwordFd = open(pwordFile,O_RDONLY);
    if(pwordFd == -1){
        printf("Could not find password file, please try again!\r\n");
        return -1;
    }else{
        password = malloc(0x255);
        bytesRead = read(pwordFd,password,0x255);
        if(bytesRead < 8){
            printf("Not enough values in password file, please try again!\r\n");
            return -1;
        }
    }


    info.calc = &keyCalc;
    info.realKey = info.calc(info.key,info.key + 0xBEEF);
    info.username = username;
    info.password = password;
    gen_password(&info);
    int pwordLen = 0;
    for(pwordLen = 0; pwordLen < info.nameLen;pwordLen++ ){
        if(password[pwordLen] != info.password[pwordLen]){
            printf("Invalid character in password detected, exiting now!\r\n");
            return -1;
        }
    }
    printf("Correct! Access granted!\r\n");
    free(info.password);
    return 0;
}
