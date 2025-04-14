#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    // execl: execute another program in the space of this program.
    // Arguments:
    // 1. Path to the program to execute.
    // 2. The name of the executable file to run.
    // 3. Zero or more command-line arguments, as they would have been typed on a command
    //    line terminal when running the program.
    // 4. The command-line arguments ALWAYS end with a nullptr.
    // execl returns -1 if the O.S. could not start the program.
    if (execl("/bin/ls", "ls", "-l", static_cast<char*>(nullptr)) == -1) {
        std::cout << "There was an error when trying to exec" << std::endl
                  << "Error number " << errno << std::endl;
    }
    else {
        // We will never actually get here. Why?
        std::cout << "Goodbye, world!" << std::endl;
    }
    return 0;
}
