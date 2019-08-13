#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_STR 81
#define ERROR_MSG_NUM_ARGS "Wrong number of arguments"
#define ERROR_MSG_INV_INT "The argument is not a valid integer"
#define PRINT_CIPHER 2
#define ENCRYPT 3
#define ALPHABET_SIZE 26
 
void printErrorMessage(char* message);
void printCipher(int shift, int lowerCase);
void encrypt(int shift, char* input);
int getShiftedOffset(int ch, int shift);
char convertChar(int shift, char character);
 
int main(int argc, char* argv[]) {
    int shift;              //used to store first argument
   
  if(argc < PRINT_CIPHER || argc > ENCRYPT){     //checks for correct number of arguments
      printErrorMessage(ERROR_MSG_NUM_ARGS);
      return 1;
  }
 
  int checkError = sscanf(argv[1], "%d", &shift);
  if(checkError < 1){    //checks for valid shift argument
      printErrorMessage(ERROR_MSG_INV_INT);
      return 1;
  }
 
    if(argc == PRINT_CIPHER){ //prints out shifted alphabet
        printCipher(shift, 1);
        printf("\n");
        printCipher(shift, 0);
    }

    else if(argc == ENCRYPT){ //prints original and encrypted text
        char* msg;
        int len = strlen(msg);
        sscanf(argv[2], "%[^\t\n]", msg);
        printf("%s\n", msg);
        encrypt(shift, msg);

    }
 
  return 0;
}
 
void printErrorMessage(char* message) {
    fprintf(stderr, "Usage: Caesar Cipher <letter shift> %s", message);
}
 
int getShiftedOffset(int ch, int shift){
   int shifted = ch + shift;
   //shifts for lowercase
   if(ch >= 'a' && ch <= 'z'){
    //finds offset of shifted character, and checks if in bound
       if(shifted < 'a') { 
           shifted = 'z' - ('a' - shifted) + 1;
       }
       else if(shifted > 'z'){
           shifted = (shifted - 'z') + 'a' - 1;
       }
   }
   //shifts for uppercase
   else {
       if(shifted < 'A'){
           if(shifted < 'A') {
               shifted = 'Z' - ('A' - shifted) + 1;
           }
           else if(shifted > 'Z'){
               shifted = (shifted - 'Z') + 'A' - 1;
           }
       }
       
   }
   return shifted;
}
 
 //converts character with correct offset
char convertChar(int shift, char character){
     int ch = (int) character;
     shift %= ALPHABET_SIZE;
     return (char)( getShiftedOffset(ch, shift) );
}
 
 //prints complete alphabet, either upper or lower case
void printCipher(int shift, int lowerCase){
    shift = shift % ALPHABET_SIZE;
    char s;
    if (lowerCase == 1) {
        for(int i = 'a'; i <= 'z'; i++){
            printf("%c", i);
        }
        printf("\n");
        for(int i = 'a'; i <= 'z'; i++){
            s = convertChar(shift, i);
            printf("%c", s);
        }
    }
    else {
        for(int i = 'A'; i <= 'Z'; i++){
            printf("%c", i);
        }
        printf("\n");
        for(int i = 'A'; i <= 'Z'; i++){
            s = convertChar(shift, i);
            printf("%c", s);
        }
    }
}

//shifts inputted text 
void encrypt(int shift, char* input) {
    shift = shift % ALPHABET_SIZE;
    char s;
    for(int i = 0; i < strlen(input); i++){
        if(*(input+i) == ' ') {
            printf("%c", *(input+i));
        }
        else {
            s = convertChar(shift, *(input+i));
            printf("%c", s);
    
        }
    }
}