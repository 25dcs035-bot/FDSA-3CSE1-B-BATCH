#include <iostream>
#include <string>

using namespace std;

const int slots = 10;
int parking[slots];

void init() {
    for (int i = 0; i < slots; i++) {
        parking[i] = -1;
    }
}
void parkVec(int regNum) {
    int startSlot = regNum % 10; 
    int slot = startSlot;
    int count = 0; 
    while (parking[slot] != -1) {
        slot = (slot + 1) % slots; 
        count++;
        if (count == slots) {
            cout << "Vehicle " << regNum << " -> Parking Full! Cannot park.\n";
            return;
        }
    }

    parking[slot] = regNum;
    cout << "Vehicle " << regNum << " assigned Slot " << slot << endl;
}

void display() {
    cout << "\n--- Final Parking  Status ---\n";
    for (int i = 0; i < slots; i++) {
        if (parking[i] == -1) {
            cout << "Slot " << i << ": Empty\n";
        } else {
            cout << "Slot " << i << ": Vehicle " << parking[i] << "\n";
        }
    }
}

int main() {
    init();
    int vehicles[] = {1234, 5674, 9814, 2205, 3315, 7700};
    int n = sizeof(vehicles) / sizeof(vehicles[0]);

    for (int i = 0; i < n; i++) {
        parkVec(vehicles[i]);
    }

    display();

    return 0;
}