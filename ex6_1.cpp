
#include <unistd.h>
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <functional>
#include <stdlib.h>

// Forward declaration for method defined further below
void timer(const int MaxTime, const int threadID);

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

	int thread_count = 5;
	int sleep_time = 2400;

	if(argc > 1) {
		thread_count = atoi(argv[1]);
	}
	if(argc > 2) {
		sleep_time = atoi(argv[2]);
	}

	std::cout << "sleep time " << sleep_time << std::endl;
	std::cout << "C++ process PID: " << getpid() << std::endl;
	std::cout << "Starting up " << thread_count << " threads." << std::endl;

	std::vector<std::thread> threads;
	for(int i = 0; i < thread_count; i++) {
		threads.push_back(std::thread(timer, sleep_time, i));
		threads[i].join();
	}

    return 0;
}

// ------------------------------------------------------------------
//         DO  NOT  MODIFY  CODE  BELOW  THIS  LINE
// ------------------------------------------------------------------

/**
 * The thread method.
 *
 * This method simply sleeps for 1 second and prints the time
 * remaining until the specified MaxTime (seconds) has elapsed.
 *
 * \param[in] MaxTime The maximum number of seconds this thread must
 * sleep.
 *
 * \param[in] threadID A logical index number for the thread.
 */
void timer(const int MaxTime, const int threadID) {
    for (int i = MaxTime; (i > 0); i--) {
        if (threadID == 0) {
            std::cout << "\r" << i << " seconds left..." << std::flush;
        }
        std::chrono::milliseconds duration(1000);
        std::this_thread::sleep_for(duration);
    }
}

// End of source code
