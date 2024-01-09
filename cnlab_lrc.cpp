#include <iostream>
#include <string>
using namespace std;
int main() {
    string message;
    int numColumns, numRows, columnSum, lrc;
    // get binary message from user
    cout << "Enter binary message: ";
    cin >> message;
    // get number of columns and rows in message
    cout << "Enter number of columns: ";
    cin >> numColumns;
    numRows = message.length() / numColumns;
    // calculate LRC parity
    for (int i = 0; i < numColumns; i++) {
        columnSum = 0;
        for (int j = i; j < message.length(); j += numColumns) {
            columnSum += message[j] - '0'; // convert char to int
        }
        lrc ^= columnSum; // calculate parity
    }
    // output LRC parity
    cout << "LRC parity: " << lrc << endl;
    return 0;
}

