#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double extractNumeric(const string& str) {
    bool decimalSeen = false;
    bool isValid = true;
    bool signSeen = false;
    double result = 0.0;
    int multiplier = 1;
    double fractionFactor = 0.1;

    size_t i = 0;

    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            multiplier = -1;
        }
        signSeen = true;
        i++;
    }

    for (; i < str.size(); i++) {
        char c = str[i];

        if (isdigit(c)) {
            if (!decimalSeen) {
                result = result * 10 + (c - '0');
            } else {
                result += (c - '0') * fractionFactor;
                fractionFactor /= 10;
            }
        } else if (c == '.' && !decimalSeen) {
            decimalSeen = true;
        } else {
            isValid = false;
            break;
        }
    }

    return isValid ? (result * multiplier) : -999999.99;
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}
