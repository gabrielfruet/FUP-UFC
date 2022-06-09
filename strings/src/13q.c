#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define CAPTCHASIZE 6 
#define UPPER 1<<0
#define LOWER 1<<1 
#define DIGIT 1<<2 
#define toupper &= ~32

/*
 * GENERATES A MACRO-CATPCHASIZE-DIGIT CAPTCHA AND SEND IT TO char* dest
 *
 * #define CAPTCHASIZE ____
 *
 */
void geraCAPTCHA(char* dest){
  srand(time(NULL));
  int flag = 0, pos = 0, aleatorio = 0, type = 0, index = 0;;
  char chosen = 0;
  char numerico[] = "0123456789";
  char maiusc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char minusc[] = "abcdefghijklmnopqrstuvwxyz";
  char* tipos[] = { numerico, maiusc, minusc };
  unsigned int tipos_s[] = { 10, 26, 26 };
  
  for(pos = 0; pos < CAPTCHASIZE; pos++){
    aleatorio = rand();

    type = aleatorio % 3;
    index = aleatorio % tipos_s[type];
    chosen = tipos[type][index];

    if(pos < CAPTCHASIZE - 2){

      dest[pos] = chosen; 
      if(isupper(chosen))       flag |= UPPER;
      else if(islower(chosen))  flag |= LOWER;
      else if(isdigit(chosen))  flag |= DIGIT;

    }else{
      if(!(flag & UPPER)){
        dest[pos] = maiusc[aleatorio % 26]; 
        flag |= UPPER;
      }else if(!(flag & LOWER)){
        dest[pos] = minusc[aleatorio % 26];
        flag |= LOWER;
      }else if(!(flag & DIGIT)){
        dest[pos] = numerico[aleatorio % 10];
        flag |= DIGIT;
      }else{
        dest[pos] = chosen;
      } 
    }
  }
  dest[CAPTCHASIZE] = 0;
}

int main(){
  char CAPTCHA_ORIGINAL[CAPTCHASIZE + 1]; 
  geraCAPTCHA(CAPTCHA_ORIGINAL);
  printf("CAPTCHA: %s\n", CAPTCHA_ORIGINAL);
  char CAPTCHA_user[CAPTCHASIZE + 1];
  printf("Digite o captcha: ");
  fgets(CAPTCHA_user, CAPTCHASIZE + 1, stdin);
  CAPTCHA_user[CAPTCHASIZE] = 0;
  printf("CAPTCHA DIGITADO: %s\n", CAPTCHA_user);
  if(strncmp(CAPTCHA_ORIGINAL, CAPTCHA_user, 6) == 0){
    printf("CAPTCHA CORRETO!\n");
  }else{
    printf("CAPTCHA INCORRETO!\n");
  }

  return 0;
}
