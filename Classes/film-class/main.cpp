#include <iostream>
#include "Film.h"

int main() {
    Film f{"Dog Man", 2025, 87, "PG"};
    // We can't access the private fields directly anymore.
    // std::cout << f.m_title << " (" << f.m_releaseYear << "), rated " << f.m_rating;
    // error: m_title is inaccessible.

    // Instead we use the accessors.
    std::cout << f.getTitle() << " (" << f.getReleaseYear() << "), rated "
            << f.getRating() << std::endl;

    f.setRating("Bow wow");
    std::cout << f.getTitle() << " (" << f.getReleaseYear() << "), rated "
            << f.getRating() << std::endl;

    f.setRating("R");
    std::cout << f.getTitle() << " (" << f.getReleaseYear() << "), rated "
            << f.getRating() << std::endl;
    return 0;
}
