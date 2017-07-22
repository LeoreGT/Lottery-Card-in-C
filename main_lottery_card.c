#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lottery_card.h"

int main()
{
  char random_numbers[6];
  char file_name[40];

  printf("What file would you like your lottory card in?: ");
  scanf(" %s", file_name);
  getRandomNumbers(random_numbers);
  printLotteryCard(file_name, random_numbers);
  return 0;
}
