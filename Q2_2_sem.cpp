#include <iostream>
#include <thread>
#include <semaphore.h>
using namespace std;

sem_t mySemaphore;

void runMeFirst() {
    cout << "Run me first" << endl;
    sem_post(&mySemaphore);
}

void runMeSecond() {
    sem_wait(&mySemaphore);
    cout << "I run Second" << endl;
}

void runMeThird() {
    sem_wait(&mySemaphore);
    cout << "I run Second" << endl;
}


int main () 
{
    sem_init(&mySemaphore, 0, 0);
    thread t1, t2, t3;
    t1 = thread(runMeFirst, t1);
    t2 = thread(runMeSecond, t2);
    t3 = thread(runMeThird, t3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}