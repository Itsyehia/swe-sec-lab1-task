#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const unsigned int SEED = 12345;

string encryption( string input) {
    string encrypted = input;
    srand(SEED);
    for (int  i = 0; i < input.length(); ++i) {
        char randomShift = static_cast<char>(rand() % 26);

        // XOR
        encrypted[i] = input[i] ^ randomShift;
    }
    return encrypted;
}

string decryption( string encrypted) {
    string decrypted = encrypted;
    srand(SEED);
    for (int  i = 0; i < encrypted.length(); ++i) {
        char randomShift = static_cast<char>(rand() % 26);
        decrypted[i] = encrypted[i] ^ randomShift;
    }
    return decrypted;
}

int main() {
    string input = "message";
    cout << "Original: " << input << endl;

    string encrypted = encryption(input);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = decryption(encrypted);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
