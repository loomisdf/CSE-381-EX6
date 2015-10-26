
#include <unistd.h>
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <functional>
#include <stdlib.h>

// Forward declaration for method defined further below
void doSomething(int num, const int threadID);

/**
 * The main method that launched various threads and waits for them to
 * finish.
 *
 * @param args Optional command-line arguments. The first argument is
 * the number of threads. The second argument is the time delay.
 */
int main(int argc, char *argv[]) {
    // Process command-line arguments (if any) or assume default values.
    // Implement the desired functionality of the main method

	int number = 0;

	std::cout << "C++ process PID: " << getpid() << std::endl;
	int thread_count = 5;

	std::vector<std::thread> threads;
	for(int i = 0; i < thread_count; i++) {
		threads.push_back(std::thread(doSomething, number, i));
		//threads[i].join();
	}

    return 0;
}

void doSomething(int num, const int threadID) {
	num++;
	std::cout << "thread " << threadID << ": " <<num << std::endl << std::flush;
}

// End of source code
