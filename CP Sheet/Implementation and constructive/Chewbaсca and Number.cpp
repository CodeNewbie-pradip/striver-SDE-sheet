#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;
    
    int n = x.length();

    // Process each digit of the number
    for (int i = 0; i < n; ++i) {
        int digit = x[i] - '0'; // Convert char to int
        
        // Invert the digit if it's greater than 4 and it's not the first digit or 
        // if the first digit becomes non-zero after inversion
        if (i == 0 && digit == 9) {
            continue; // We never invert the first digit if it's 9
        }
        
        // Invert the digit if the inverted value is smaller
        if (digit > 4) {
            x[i] = (9 - digit) + '0'; // Convert back to char
        }
    }

    cout << x << endl;
    return 0;
}
