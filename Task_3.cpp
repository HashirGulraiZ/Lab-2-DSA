#include "List.h"

int main() {
    CustomList<int> list(10);
    int choice, value, rotations;

    do {
        cout << "\nMenu:\n";
        cout << "1. Sum of Prime Numbers\n";
        cout << "2. Second Maximum Even Number\n";
        cout << "3. Second Minimum Odd Number\n";
        cout << "4. Print Duplicates\n";
        cout << "5. Rotate Clockwise\n";
        cout << "6. Rotate Anti-Clockwise\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Sum of Prime Numbers: " << list.sum_ofPrime() << endl;
            break;
        case 2:
            cout << "Second Maximum Even: " << list.secondMaxEven() << endl;
            break;
        case 3:
            cout << "Second Minimum Odd: " << list.secondMinOdd() << endl;
            break;
        case 4:
            cout << "Duplicates: ";
            list.printDuplicates();
            break;
        case 5:
            cout << "Enter number of rotations: ";
            cin >> rotations;
            list.rotateClockwise(rotations);
            cout << "Rotated clockwise." << endl;
            break;
        case 6:
            cout << "Enter number of rotations: ";
            cin >> rotations;
            list.rotateAntiClockwise(rotations);
            cout << "Rotated anti-clockwise." << endl;
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}