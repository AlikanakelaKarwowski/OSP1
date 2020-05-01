#include <chrono>
#include <thread>
#include <random>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <iostream>

void sleep(int SleepLength);
void agent1();
void agent2();
void agent3();
void tobaccoPusher();
void paperPusher();
void matchPusher();
void smokerTobacco();
void smokerPaper();
void smokerMatches();

sem_t tobacco;
sem_t paper;
sem_t match;
sem_t agentSem;

bool isTobacco = false;
bool isPaper = false;
bool isMatch = false;

sem_t tobaccoSem;
sem_t paperSem;
sem_t matchSem;
sem_t mutex;

void sleep(int SleepLength)
{
    srand(time(0));
    double ms = rand()%SleepLength +1;
    clock_t startClock = clock();
    double secondsAhead = (ms * CLOCKS_PER_SEC)/100;
    while(clock() < startClock+secondsAhead);
    return;
}

void* agent1(void* args)
{
    std::cout <<"Agent1 called\n";
    for (int i = 0; i < 6; i++)
    {
        sleep(200);
        std::cout <<"agentSem Wait\n";
        sem_wait(&agentSem);
        std::cout <<"paper post\n";
        sem_post(&paper);
        std::cout <<"tobacco post\n";
        sem_post(&tobacco);
    }
    pthread_exit(0);
}

void* agent2(void* args)
{
    std::cout <<"Agent2 called\n";
    for (int i = 0; i < 6; i++)
    {
        sleep(200);
        std::cout <<"agentSem wait\n";
        sem_wait(&agentSem);
        std::cout <<"tobacco post\n";
        sem_post(&tobacco);
        std::cout <<"match post\n";
        sem_post(&match);
    }
    pthread_exit(0);
}

void* agent3(void* args)
{
    std::cout <<"Agent3 called\n";
    for (int i = 0; i < 6; i++)
    {
        sleep(200);
        std::cout <<"agentSem wait\n";
        sem_wait(&agentSem);
        std::cout <<"paper post\n";
        sem_post(&paper);
        std::cout <<"match post\n";
        sem_post(&match);
    }
    pthread_exit(0);
}

void* tobaccoPusher(void* args)
{
    std::cout <<"Tobacco Pusher called\n";
    for (int i = 0; i < 12; i++)
    {
        std::cout <<"tobacco wait\n";
        sem_wait(&tobacco);
        std::cout <<"mutex wait\n";
        sem_wait(&mutex);

        if (isPaper)
        {
            isPaper = false;
            std::cout <<"matchSem post\n";
            sem_post(&matchSem);
        }
        else if (isMatch)
        {
            isMatch = false;
            std::cout <<"paperSem post\n";
            sem_post(&paperSem);
        }
        else
        {
            isTobacco = true;
        }
        std::cout <<"mutex post\n";
        sem_post(&mutex);
    }
    pthread_exit(0);
}

void* matchPusher(void* args)
{
    std::cout <<"Match Pusher called\n";
    for (int i = 0; i < 12; i++)
    {
        std::cout <<"match wait\n";
        sem_wait(&match);
        std::cout <<"mutex wait\n";
        sem_wait(&mutex);

        if (isPaper)
        {
            isPaper = false;
            std::cout <<"tobaccoSem post\n";
            sem_post(&tobaccoSem);
        }
        else if (isTobacco)
        {
            isTobacco = false;
            std::cout <<"paperSem post\n";
            sem_post(&paperSem);
        }
        else
        {
            isMatch = true;
        }
        std::cout <<"mutex post\n";
        sem_post(&mutex);
    }
    pthread_exit(0);
}

void* paperPusher(void* args)
{
    std::cout <<"Paper Pusher called\n";
    for (int i = 0; i < 12; i++)
    {
        std::cout <<"paper wait\n";
        sem_wait(&paper);
        std::cout <<"mutex wait\n";
        sem_wait(&mutex);

        if (isMatch)
        {
            isMatch = false;
            std::cout <<"tobaccoSem post\n";
            sem_post(&tobaccoSem);
        }
        else if (isTobacco)
        {
            isTobacco = false;
            std::cout <<"matchSem post\n";
            sem_post(&matchSem);
        }
        else
        {
            isPaper = true;
        }
        std::cout <<"mutex post\n";
        sem_post(&mutex);
    }
    pthread_exit(0);
}

void* smokerTobacco(void* args)
{
    std::cout <<"Smoker Tobacco\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout <<"tobaccoSem wait\n";
        sem_wait(&tobaccoSem);
        sleep(200);
        std::cout <<"agentSem post\n";
        sem_post(&agentSem);
        sleep(200);
    }
    pthread_exit(0);
}

void* smokerPaper(void* args)
{
    std::cout <<"Smoker Paper\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout <<"paperSem wait\n";
        sem_wait(&paperSem);
        sleep(200);
        std::cout <<"agentSem post\n";
        sem_post(&agentSem);
        sleep(200);
    }
    pthread_exit(0);
}

void* smokerMatches(void* args)
{
    std::cout <<"Smoker Matches\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout <<"matchSem wait\n";
        sem_wait(&matchSem);
        sleep(200);
        std::cout <<"agentSem post\n";
        sem_post(&agentSem);
        sleep(200);
    }
    pthread_exit(0);
}

int main()
{
    
    // agent semaphores
    sem_init(&agentSem, 0, 1);
    sem_init(&tobacco, 0, 0);
    sem_init(&paper, 0, 0);
    sem_init(&match, 0, 0);

    // pusher semaphores
    sem_init(&tobaccoSem, 0, 0);
    sem_init(&paperSem, 0, 0);
    sem_init(&matchSem, 0, 0);
    sem_init(&mutex, 0, 1);

    // create the agent threads
    pthread_t agent1_thread;
    pthread_t agent2_thread;
    pthread_t agent3_thread;
    pthread_create(&agent1_thread, NULL, agent1, NULL);
    pthread_create(&agent2_thread, NULL, agent2, NULL);
    pthread_create(&agent3_thread, NULL, agent3, NULL);

    // create the pusher threads
    pthread_t paperPusher_thread;
    pthread_t matchPusher_thread;
    pthread_t tobaccoPusher_thread;
    pthread_create(&paperPusher_thread, NULL, paperPusher, NULL);
    pthread_create(&matchPusher_thread, NULL, matchPusher, NULL);
    pthread_create(&tobaccoPusher_thread, NULL, tobaccoPusher, NULL);

    // create the smoker threads
    pthread_t smokerTobacco_thread1;
    pthread_t smokerTobacco_thread2;
    pthread_create(&smokerTobacco_thread1, NULL, smokerTobacco, NULL);
    pthread_create(&smokerTobacco_thread2, NULL, smokerTobacco, NULL);

    pthread_t smokerPaper_thread1;
    pthread_t smokerPaper_thread2;
    pthread_create(&smokerPaper_thread1, NULL, smokerPaper, NULL);
    pthread_create(&smokerPaper_thread2, NULL, smokerPaper, NULL);

    pthread_t smokerMatches_thread1;
    pthread_t smokerMatches_thread2;
    pthread_create(&smokerMatches_thread1, NULL, smokerMatches, NULL);
    pthread_create(&smokerMatches_thread2, NULL, smokerMatches, NULL);


    std::cout <<"Join agent threads\n";
    //join all agent threads
    pthread_join(agent1_thread,NULL);
    pthread_join(agent2_thread,NULL);
    pthread_join(agent3_thread,NULL);

    std::cout << "join pusher threads\n";
    //join all pusher threads
    pthread_join(paperPusher_thread,NULL);
    pthread_join(matchPusher_thread,NULL);
    pthread_join(tobaccoPusher_thread,NULL);

    std::cout << "join tobacco threads\n";
    //join the tobacco threads
    pthread_join(smokerTobacco_thread1,NULL);
    pthread_join(smokerTobacco_thread2,NULL);

    std::cout << "join paper threads\n";
    //join the paper threads
    pthread_join(smokerPaper_thread1,NULL);
    pthread_join(smokerPaper_thread2,NULL);

    std::cout << "join matches threads\n";
    //join the matches threads
    pthread_join(smokerMatches_thread1,NULL);
    pthread_join(smokerMatches_thread2,NULL);

    std::cout << "End Scenario\n";

}
