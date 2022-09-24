#include <condition_variable>
#include <future>
#include <mutex>
#include <iostream>
#include <atomic>
#include  <thread>
bool readyFlag;
std::mutex readyMutex;
std::condition_variable readyCondVar;
std::atomic<bool> readyFlag1;
void thread1()
{
	std::cout << "<return >" << std::endl;
#ifdef CV
	std::cin.get();
	{
		std::lock_guard<std::mutex> lg(readyMutex);
		readyFlag = true;
	}
	readyCondVar.notify_one();
#else
	readyFlag1.store(true);
#endif
}

void thread2()
{
#ifdef CV
	{
		std::unique_lock<std::mutex> ul(readyMutex);
		readyCondVar.wait(ul, []{return readyFlag;});
	}
#else
	while(!readyFlag1.load()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::cout<<"done"<<std::endl;
#endif
}


int main()
{
	auto f1 = std::async(std::launch::async, thread1);
	auto f2 = std::async(std::launch::async, thread2);
	return 0;
}

