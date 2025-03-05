#include <iostream>
struct Film {
    std::string title;
    int releaseYear;
    int duration;
    std::string rating;
}; // note the semi colon here.

// Print a film, which is taken as a const reference because it is large,
// we don't mutate it, and we can't deal with nullptr.
void printFilm(const Film& film) {
    std::cout << film.title << " (" << film.releaseYear << "), rated " << film.rating;
}

int main() {
    Film f {"Dog Man", 2025, 87, "PG"};
    f.duration = -10;

    printFilm(f);
    return 0;
}
