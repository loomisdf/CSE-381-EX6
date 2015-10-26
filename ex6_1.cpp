
#include <unistd.h>
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <functional>

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
