#include <iostream>
#include <thread>
#include <semaphore.h>
#include <cstdlib>
#include <queue>
#include <condition_variable>
#include <mutex>
using namespace std;

sem_t mySemaphore;
mutex mtx;
condition_variable cv;
bool ready = false;

struct reqestStructure {
    int request_id; 

    string ip_address;

   string page_requested;

};

string webPages[10] = {"google.com", "yahoo.com", "duckDuckGo", "Firefox", "Onion", "OperaGX", "Crealx", "SuperSearch", "Bing", "Cortana"};

void listen () 
{
    this_thread::sleep_for(chrono::seconds(3));
    srand((unsigned) time(NULL));
    int random = 1 + (rand() % 1-10);

    string ip = " ";

    queue<string> webPages;
    webPages{10}.push(" ")
}
void do_request ()  
{
    if (webPages = empty)
    {
        cv = true;
        cout << "thread thread_id completed request request_id requesting webpage page_requested" << endl;
    }
    
}


int main () 
{
    sem_init(&mySemaphore, 0, 0);
    thread t1, t2;

    t1 = thread(listen);
    t1 = thread(do_request);
    t1.join();
    t2.join();
    return 0;
}