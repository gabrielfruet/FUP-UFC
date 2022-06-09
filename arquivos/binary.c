#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct Date{
  uint32_t year;
  uint16_t day;
  uint16_t month;
};

struct Person{
  char name[52];
  struct Date born;
  int age;
};

int main(){
  struct Person people[5];
  printf("SIZE OF PERSON: %lu\n", sizeof(struct Person));
  printf("SIE OF ALL PERSON MENBER: %lu\n",52*sizeof(char) + sizeof(struct Date) + sizeof(int) );
  printf("SIZE OF DATE: %lu\n", sizeof(struct Date));
  printf("SIZE OF ALL DATE MENBERS: 8\n");
  strcpy(people[0].name, "GABRIEL");
  people[0].age = 18;
  people[0].born.day = 9;
  people[0].born.month = 12;
  people[0].born.year = 2003;
  strcpy(people[1].name, "FRANCISCO");
  people[1].age = 12;
  people[1].born.day = 5;
  people[1].born.month = 7;
  people[1].born.year = 2010;
  strcpy(people[2].name, "BIA");
  people[2].age = 18;
  people[2].born.day = 21;
  people[2].born.month = 8;
  people[2].born.year = 2003;
  strcpy(people[3].name, "JONAS");
  people[3].age = 18;
  people[3].born.day = 9;
  people[3].born.month = 12;
  people[3].born.year = 2003;
  strcpy(people[4].name, "LUCAS");
  people[4].age = 28;
  people[4].born.day = 3;
  people[4].born.month = 2;
  people[4].born.year = 1994;
  FILE* binary = fopen("./data/people.bin", "wb");
  fwrite(people, sizeof(struct Person), 5, binary);
  fclose(binary);
  return 0;
}
