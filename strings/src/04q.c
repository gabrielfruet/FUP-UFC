#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void toLowerWord(char* word){
  size_t size = strlen(word);
  for(int i = 0; i < size; i++){
    word[i] = (char)tolower((int)word[i]);
  }
}

void imprimeTable(const int s, char table[s]){
  printf("[\n");
  for(int i = 0; i < s; i++){
    printf("\t%c : %d,\n", 'A' + i, table[i]);
  }
  printf("]\n");
}

bool isAnagram(const char* pattern, const char* cmp){
  const int table_s = 26;
  size_t pattern_s = strlen(pattern);
  size_t cmp_s = strlen(cmp);
  if(cmp_s != pattern_s)
    return false;
  char pattern_letters[table_s];
  memset(pattern_letters, 0, table_s*sizeof(char));
  for(int i = 0; i < pattern_s; i++){
    if(isalpha(pattern[i]))
      pattern_letters[tolower(pattern[i]) - 'a'] += 1;
  }
  char cmp_letters[table_s];
  memset(cmp_letters, 0, table_s*sizeof(char));
  for(int i = 0; i < cmp_s; i++){
    if(isalpha(cmp[i]))
      cmp_letters[tolower(cmp[i])- 'a'] += 1; 
  }
  for(int i = 0; i < table_s; i++){
    if(cmp_letters[i] != pattern_letters[i])
      return false;
  }
  imprimeTable(table_s, pattern_letters);
  imprimeTable(table_s, cmp_letters);
  return true;
}

int main(){
  char palavra1[100], palavra2[100];
  printf("Digite duas palavras para verificar se sao anagramas: "); 
  scanf(" %s %s", palavra1, palavra2);
  printf("PRIMEIRA PALAVRAS .%s. \nSEGUNDA PALAVRA: .%s.\n", palavra1, palavra2);
  if(isAnagram(palavra1, palavra2)){
    puts("EH ANAGRAM");
  }else{
    puts("NAO EH ANAGRAMA!");
  }
  return 0;
}
