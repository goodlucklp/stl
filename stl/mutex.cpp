#include <future>
#include <mutex>
#include <iostream>
#include <string>

std::mutex printMutex;

void print(const std::string& s)
{
    std::lock_guard<std::mutex> l(printMutex);
    for (char c: s) {
        std::cout.put(c);
    }
    std::cout << std::endl;
}

int main()
{
    auto f1 = std::async(std::launch::async, print, "Hello form a first thread");
    auto f2 = std::async(std::launch::async, print, "Hello from a second thread");
    print("Hello from the main thread");
    return 0;
}
