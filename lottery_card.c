#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lottery_card.h"

char* getRandomNumbers(char random_numbers[])
{
  int i, n = 6, res;
  time_t t;
  /* Intializes random number generator */
  srand((unsigned) time(&t));

  /* Print 6 random numbers from 0 to 49 */
  for( i = 0 ; i < n ; i++ )
  {
   random_numbers[i] = (rand() % 49);
   printf("%d\n", random_numbers[i]);
  }

  return random_numbers;
}

int printLotteryCard(char* _file_name, char _number_array[6])
{
  int i, j, m, number, res;
  FILE* fp;

  int lotto_card[5][10] = {
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}
  };

  fp = fopen(_file_name,"w");
  if( NULL == fp)
  {
    printf("Couldn't open the file!\n");
    return FILE_ERROR;
  }

  if (NULL == _number_array)
  {
    printf("Error receiving random numbers!\n");
    return PARAMS_ERROR;
  }

  for (i = 0; i < 6; i++)
  {
    number = _number_array[i];
    lotto_card[(number/10)][(number%10)] = '+';
  }

  fprintf(fp, " 0 1 2 3 4 5 6 7 8 9");
  for (j = 0; j < 5; j++)
  {
    fprintf(fp, "\n%d", j);
    for (m = 0; m < 10; m++)
    {
      fprintf(fp, "%c ", lotto_card[j][m]);
    }
  }
  fprintf(fp, "\n");

  res=fclose(fp);
  if(0 != res)
  {
    printf("Couldn't close the file!\n");
    return FILE_ERROR;
  }

  return 0;
}
