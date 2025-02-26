#include <iostream>

// A Film consists of a title, a release year, a duration, and a rating.
void printFilm(const std::string& title, int releaseYear, int duration, const std::string& rating) {
    std::cout << title << " (" << releaseYear << "), rated " << rating;
}

int main() {
    printFilm("Dog Man", 2025, 89, "PG");

    // What if we write other functions involving films?
    // What if we decide a film requires more information?
    // Do we really want to copy and paste all these parameters across dozens of functions?
    // What if we want to change one of the parameter types for all those functions?

    // We are stressing over the DETAILS of what a film is, rather than deal with
    // the abstract thought of a Film as a type of data. This code will be very difficult
    // to scale and maintain.
    return 0;
}
