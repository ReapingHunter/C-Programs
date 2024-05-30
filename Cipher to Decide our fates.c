#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *decode_message(char coded_message[]); 
int main(){
    char coded[30];
    char *decoded;
    printf("The Coded Message Is: ");
    scanf("%s",coded);
    decoded = decode_message(coded);
    printf("The Decoded Message is: %s !!",decoded);
    return 0;
}

char *decode_message(char coded_message[]){
	int i;
    for(i = 0; i < strlen(coded_message); i++){
        switch(coded_message[i]){
            case 'A':
                coded_message[i] = 'N';
                break;
            case 'B':
                coded_message[i] = 'O';
                break;
            case 'C':
                coded_message[i] = 'P';
                break;
            case 'D':
                coded_message[i] = 'Q';
                break;
            case 'I':
                coded_message[i] = 'E';
                break;
            case 'N':
                coded_message[i] = 'A';
                break;
            case 'O':
                coded_message[i] = 'B';
                break;
            case 'P':
                coded_message[i] = 'C';
                break;
            case 'Q':
                coded_message[i] = 'D';
                break;
            case 'E':
                coded_message[i] = 'I';
                break;
        }
    }
    return coded_message;
}
