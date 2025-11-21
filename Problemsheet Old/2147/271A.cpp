#include <iostream>
using namespace std;

int main() {
    int y;
    cin >> y;

    while (true) {
        y++;
        
        int thousands = y / 1000;
        int hundreds = (y / 100) % 10;
        int tens = (y / 10) % 10;
        int units = y % 10;

        if (thousands != hundreds && thousands != tens && thousands != units &&
            hundreds != tens && hundreds != units &&
            tens != units) {
            
            cout << y << endl;
            
            break;
        }
    }
}
