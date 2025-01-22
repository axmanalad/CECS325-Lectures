// Like "import" in Python; make a library available for us to use.
#include <iostream> // input-output streams, i.e., reading from keyboard and printing to console.

// The "entry point": the first line of code that runs when the application starts. We execute
// line by line starting here. It is ALWAYS* declared as "int main()".
int main() {
    // Above:
    // - int is the return type of the function called "main".
    //   Before this function ends, we must return an integer value. By tradition,
    //   returning 0 indicates the main was successful, and any other value indicates
    //   that we encountered an error.

    // std::cout is used to print. "see-out".
    std::cout << "Please enter the amount of PM2.5, in ug/m^3: ";
    // Unlike Python, strings are ALWAYS in double-quotes ", NEVER in single-quotes '

    // To declare a variable, we MUST start with its DATA TYPE. The C++ compiler will make sure
    // that we ONLY assign that variable with values of the same type.
    double pm25;
    // "double" is a floating-point number type.

    // std::cin is used to read values from the console. "see-in".
    std::cin >> pm25; // give a value to the variable pm25 by reading keyboard input and converting it to a double.

    // We can declare more than one variable of the same type on the same line.
    double cLow, cHigh;
    int iLow, iHigh;
    // int is for integers.

    // Conditional branching is done with "if" statements. The condition is ALWAYS wrapped in parentheses.
    // Matching curly braces { } start and end the "then" block of the branch.
    if (pm25 <= 12.0) {
        cLow = 0.0;
        cHigh = 12.0;
        iLow = 0;
        iHigh = 50;
    }
    // There is no "elif"; we write "else if". && is used for "and".
    else if (pm25 > 12.0 && pm25 <= 35.4) {
        cLow = 12.1;
        cHigh = 35.4;
        iLow = 51;
        iHigh = 100;
    }
    else if (pm25 > 35.4 && pm25 <= 55.4) {
        cLow = 35.5;
        cHigh = 55.4;
        iLow = 101;
        iHigh = 150;
    }
    else if (pm25 > 55.4 && pm25 <= 150.4) {
        cLow = 55.5;
        cHigh = 150.4;
        iLow = 151;
        iHigh = 200;
    }
    else if (pm25 > 150.4 && pm25 <= 250.4) {
        cLow = 150.5;
        cHigh = 250.4;
        iLow = 201;
        iHigh = 300;
    }
    else if (pm25 > 250.4 && pm25 <= 350.4) {
        cLow = 250.5;
        cHigh = 350.4;
        iLow = 301;
        iHigh = 400;
    }
    else if (pm25 > 350.4 && pm25 <= 500.4) {
        cLow = 350.5;
        cHigh = 500.4;
        iLow = 401;
        iHigh = 500;
    }
    else {
        cLow = 500.5;
        cHigh = 999.9;
        iLow = 501;
        iHigh = 999;
    }

    // When arithmetic involves different data types, values are converted into the most-precise type
    // before doing the arithmetic.
    // Break down this expression to recognize which steps are done with integer arithmetic, and which steps
    // are floating point arithmetic.
    double aqi = (iHigh - iLow) / (cHigh - cLow) * (pm25 - cLow) + iLow;
    std::cout << "AQI for PM2.5: " << aqi << std::endl;
    // std::endl is "end line", forcing the *next* cout to start on the next line of the console.

    if (aqi <= 50) {
        std::cout << "Air Quality: Good" << std::endl;
    }
    else if (aqi <= 100) {
        std::cout << "Air Quality: Moderate" << std::endl;
    }
    else if (aqi <= 150) {
        std::cout << "Air Quality: Unhealthy for Sensitive Groups" << std::endl;
    }
    else if (aqi <= 200) {
        std::cout << "Air Quality: Unhealthy" << std::endl;
    }
    else if (aqi <= 300) {
        std::cout << "Air Quality: Very Unhealthy" << std::endl;
    }
    else {
        std::cout << "Air Quality: Hazardous" << std::endl;
    }

    return 0;
}
