#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork() {
    using namespace std::literals::chrono_literals;
    int sum = 0;

    std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;
    while(sum < 10) {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(0.5s);
        sum++;
    }
    std::cout << "Work finished!!!" << std::endl; 
}
int main() {
    std::thread worker(DoWork); 

    s_Finished = true;

    worker.join();

    return 0;
}