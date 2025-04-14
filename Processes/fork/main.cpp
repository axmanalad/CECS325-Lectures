#include <iostream>
#include <thread>

#include <unistd.h>
#include <sys/wait.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    int cid {fork()};
    if (cid == 0) {
        // "Sleep_for" will cause this program to pause for X seconds.
        // I'm doing this just so we can see this program in our process/task manager.
        std::this_thread::sleep_for(std::chrono::seconds(10));
        // This is in the new ("child") process. This is where we exec our new program.
        if (execl("/bin/ls", "ls", "-l", static_cast<char*>(nullptr)) == -1) {
            std::cout << "There was an error when trying to exec" << std::endl
                      << "Error number " << errno << std::endl;
        }
        // After this previous line, the child process will skip the "else", return 0, and then terminate.
    }
    else {
        std::cout << "cid " << cid << std::endl;

        // We need to wait for the child process to terminate before we finish. So before we exit the parent,
        // we must....
        int childStatus;
        waitpid(cid, &childStatus, 0);

        std::cout << "Goodbye, world!" << std::endl;
    }
    return 0;
}
