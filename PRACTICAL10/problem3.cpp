#include <iostream>

using namespace std;

const int SIZE = 10;
int slots[SIZE];
void init() {
    for (int i = 0; i < SIZE; i++) {
        slots[i] = -1;
    }
}

int hash1(int id) {
    return id % SIZE;
}
int hash2(int id) {
    return 7 - (id % 7);
}

void addStudent(int id) {
    int index = hash1(id);
    int step = hash2(id);
    int count = 0;

    while (slots[index] != -1) {
        cout << "Collision for ID " << id << " at Slot " << index << " | Jumping " << step << " slots.\n";
        
        index = (index + step) % SIZE;
        count++;

        if (count == SIZE) {
            cout << "Error: Storage Full! ID " << id << " cannot be added.\n\n";
            return;
        }
    }

    slots[index] = id;
    cout << "ID " << id << " assigned to Slot " << index << "\n\n";
}

void display() {
    cout << "--- Final Storage Slots Status ---\n";
    for (int i = 0; i < SIZE; i++) {
        if (slots[i] == -1) {
            cout << "Slot " << i << ": Empty\n";
        } else {
            cout << "Slot " << i << ": Student ID " << slots[i] << "\n";
        }
    }
}

int main() {
    init();
    int StuIDs[] = {10, 20, 30, 25};
    int n = sizeof(StuIDs) / sizeof(StuIDs[0]);

    for (int i = 0; i < n; i++) {
        addStudent(StuIDs[i]);
    }

    display();

    return 0;
}