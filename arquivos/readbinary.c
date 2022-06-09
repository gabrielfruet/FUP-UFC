#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Date{
  uint32_t year;
  uint8_t day;
  uint8_t month;
};

struct Person{
  char name[52];
  struct Date born;
  int age;
};

void print_person(struct Person per){
  printf("PERSON: \n");
  printf("NAME: %s\n", per.name);
  printf("AGE: %d\n", per.age);
  printf("BORN DATE: %u/%u/%u\n", per.born.day, per.born.month, per.born.year);
}

int main(){
  struct Person people[5];
  FILE* binary = fopen("./data/people.bin", "rb");
  fread(people, sizeof(struct Person), 5, binary);
  for(int i = 0; i < 5; i++){
    print_person(people[i]);
  }
  fclose(binary);
  return 0;
}

