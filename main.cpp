#include <iostream>
#include <atomic>

int main() {
    std::atomic<int>  a = {0};

    int vale = a.fetch_add(2);
    vale = a.fetch_add(1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
