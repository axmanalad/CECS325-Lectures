#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
    // Command line arguments are passed to a C++ main through two parameters:
    // argc: the number of command line arguments. This will always be 1 or larger.
    // argv: an array of C-strings, of length argc. Index 0 is the name of the program.
    //       Index 1 and greater are the arguments passed on the command line.

    // We'll print some debugging info first.
    std::cout << "Running adder" << std::endl
              << "argc: " << argc << std::endl
              << "argv[0]: " << argv[0] << std::endl;

    // Anything beyond argv[0] is not guaranteed to exist, so we check argc before
    // accessing it.
    for (size_t i {1}; i < argc; ++i) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    // When pressing "Run" in CLion, all we ever get is one argument. But we can configure
    // CLion to send more.
    // Use "Edit Configurations..."

    // Arguments are always passed as C-strings. If they are supposed to represent
    // some other data type, we must *parse* them into those types.

    // So here's the real program: adder takes two arguments, which are floating
    // point numbers, and adds them together. The sum is then printed to cout.

    if (argc == 3) {
        // The istringstream class is used to parse strings into other types.
        std::istringstream input1 {argv[1]};
        std::istringstream input2 {argv[2]};

        double float1, float2;
        // We use istringstream like "cin", to read one value from its string at a time
        // into other variables.
        input1 >> float1;
        input2 >> float2;

        double result {float1 + float2};
        std::cout << result << std::endl;
        return 0; // 0 means success.
    }
    else {
        return -1; // any non-zero value means failure.
    }
}
