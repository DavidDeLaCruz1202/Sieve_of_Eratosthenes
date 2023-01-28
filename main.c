#include <stdbool.h>
#include <stdio.h>

/*
  Author: David De La Cruz
  Date: 1/28/2023
  Program Description:
    In order to find the prime numbers between 1 - 100 we will iterate through the list, erase multiples of 
    each number we come across, but not the number itself. We will also set its multiples to being nonprime.
    For example, when we arrive at 2 we will erase all of its multiples and mark them as nonprime, such as 
    4 and 6, up to 100.

  Goal: Implement Sieve of Eratosthenes algorithm myself before applying parallel programming for efficiency
*/

int main(void) {
  int numbers[100];  // Our list of numbers
  bool isPrime[100]; // Our list of booleans, True = 1 = Prime

  // Size of our array (100)
  int size = sizeof(numbers) / sizeof(int);

  // Fill 'numbers' and 'isPrime'
  for (int i = 0; i < size; i++) {
    numbers[i] = i + 1;
    isPrime[i] = true;
  }

  // Print output message BEFORE algorithm so numbers[0] and numbers[size - 1] aren't 0
  printf("All prime numbers between %d and %d:\n", numbers[0], numbers[size - 1]);
  
  // Perform algorithm
  for (int i = 0; i < size; i++) {
    int currentNum = numbers[i];

    // 1 is a special case
    if (currentNum == 1) {
      numbers[i] = 0;
      isPrime[i] = false;
    }
    if (isPrime[i]) {
      /*
        For loop explanation: 
          1) The corresponding array index is 1 number below currentNum, ex: when currentNum = 3, index = 2
          2) We don't want to erase the prime number itself so we have to jump to its next multiple
          3) 'currentNum*2' is equivalent to adding the prime number to itself, which gives us its next multiple
          4) To correctly get the next multiple's index we then subtract 1 due to step 1), hence index j = currentNum*2 - 1
          5) We increment j by adding the currentNum to it, which gives us the other multiplies of the current prime number
        */
      for (int j = currentNum*2 - 1; j < size ; j += currentNum) {
          numbers[j] = 0;
          isPrime[j] = false;
      }
    }  
  }

  /* Verify correct numbers and booleans:
     2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 */
  for (int i = 0; i < size; i++) {
    if (isPrime[i]) {
      printf("(%d, %d)\n", numbers[i], isPrime[i]);
    }
  }
}