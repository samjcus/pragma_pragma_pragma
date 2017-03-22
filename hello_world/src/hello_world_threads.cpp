#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

static std::mutex mutex;

void print_msg(int thread_id)
{
  std::lock_guard<std::mutex> guard(mutex);
  std::cout << "Hello Hazel from thread " << thread_id << std::endl;
}

int main()
{
  std::vector<std::thread> threads;
  int nthreads = 4;
  
  std::cout << "There are " << nthreads << " threads" << std::endl;  

  for (int i=0; i < nthreads; i++)
    {
      threads.push_back(std::thread(print_msg, i));
    }

  for (auto &t : threads)
    {
      t.join();
    }
  return 0;
}
