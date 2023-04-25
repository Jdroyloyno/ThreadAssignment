#include <iostream>
#include <thread>
#include <semaphore.h>
#include <cstdlib>
#include <queue>
#include <condition_variable>
#include <mutex>
using namespace std;

void listen () 
{
    for(int i=0; i<20; i++) {
        int k = rand() % 3 + 1;
        this_thread::sleep_for(chrono::seconds(k));
        req.id = counter++;
        req.ip_address = "";
        k = rand()%10;
        req.page_requested = s(k);
        q.enq(req);
        cv.notify_one()

    }
}
void do_request (int id)  
{
   requestStructure r;
   while(true) {
    while(q.empty()) vc.wait();
    r = q.deq();
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Thread id: " << id << " Completed Request" << r.request_id << "asking for page" << r.page_requested << endl;
    }
    
}

int counter = 0;
sem_t mySemaphore;
mutex mtx;
condition_variable cv;
bool ready = false;

struct reqestStructure {
    int request_id; 

    string ip_address;

   string page_requested;

};

string s[10] = {"google.com", "yahoo.com", "duckDuckGo", "Firefox", "Onion", "OperaGX", "Crealx", "SuperSearch", "Bing", "Cortana"};


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