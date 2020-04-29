#include <stdio.h>
//#include <pthread.h>
//#include <semaphore.h>
//#include <unistd.h>
#include <chrono>
#include <random>
#include <time.h>

void sleep_to()
{
    srand(time(0));
    int ms = rand()%200 +1;
    clock_t startClock = clock();
    double secondsAhead = ms * CLOCKS_PER_SEC;
    while(clock() < startClock+secondsAhead);
    return;
}
sem_t agentSem = 1;
sem_t tobacco = 0;
sem_t paper = 0;
sem_t match = 0;

bool isTobacco = false;
bool isPaper = false;
bool isMatch = false;

sem_t tobaccoSem = 0;
sem_t paperSem = 0;
sem_t matchSem = 0;
sem_t mutex = 1;


int main()
{
  sem_init(&agentSem, 0, 1);
  sem_init(&tobacco, 0, 0);
  sem_init(&paper, 0, 0);
  sem_init(&match, 0, 0);
  sem_init(&tobaccoSem, 0, 0);
  sem_init(&paperSem, 0, 0);
  sem_init(&matchSem, 0, 0);
  sem_init(&mutex, 0, 1);
}
