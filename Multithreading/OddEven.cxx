// Online C++ compiler to run C++ program online
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
using namespace std;

int num = 0;
std::mutex m;
std::condition_variable cv;
void printOddNum()
{
    while(num < 500)
    {
        std::unique_lock<mutex> lock(m);
        cv.wait(lock, []{return num & 1;});
        cout << "Odd thread: " << num << endl;
        ++num;
        lock.unlock();
        cv.notify_one();
    }
}

void printEvenNum()
{
    while(num < 500)
    {
        std::unique_lock<mutex> lock(m);
        cv.wait(lock, []{return num % 2 == 0;});
        cout << "Even thread:" << num << endl;;
        ++num;
        lock.unlock();
        cv.notify_one();
    }
}

int main() {
    // Write C++ code here
    std::thread oddThread(printOddNum);
    std::thread evenThread(printEvenNum);
    
    oddThread.join();
    evenThread.join();

    return 0;
}
