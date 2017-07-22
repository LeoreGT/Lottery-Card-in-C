/* #ifndef __LOTTERY_CARD_H__ */
/* #define __LOTTERY_CARD_H__ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 0
#define FILE_ERROR -1
#define PARAMS_ERROR -2

/* Function receives 6 random numbers and           */
/* then prints a lottery card using given numbers   */
/* Leore Golan 18 - 02 - 2017 */



/* Fills given array with random numbers */
char* getRandomNumbers(char random_numbers[6]);

/* Prints out lottery card with given random numbers */
int printLotteryCard(char* _file_name, char _number_array[6]);

/* #endif __LOTTERY_CARD_H__ */
