#include "List.h"

int main() {
    MyList<int> list(10);
    int choice, value, index;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Element at First Index\n";
        cout << "2. Add Element at Last Index\n";
        cout << "3. Remove Element from End\n";
        cout << "4. Remove Element from Start\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Get Size\n";
        cout << "8. Insert at Index\n";
        cout << "9. Get Last Element\n";
        cout << "10. Search Element\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtFirstIndex(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtLastIndex(value);
            break;
        case 3:
            try {
                cout << "Removed: " << list.removeElementFromEnd() << endl;
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
            break;
        case 4:
            list.removeElementFromStart();
            cout << "First element removed." << endl;
            break;
        case 5:
            cout << (list.empty() ? "List is empty" : "List is not empty") << endl;
            break;
        case 6:
            cout << (list.full() ? "List is full" : "List is not full") << endl;
            break;
        case 7:
            cout << "Current size: " << list.size() << endl;
            break;
        case 8:
            cout << "Enter index and value: ";
            cin >> index >> value;
            cout << (list.insertAt(index, value) ? "Inserted successfully" : "Insertion failed") << endl;
            break;
        case 9:
            try {
                cout << "Last element: " << list.last() << endl;
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
            break;
        case 10:
            cout << "Enter value to search: ";
            cin >> value;
            cout << (list.search(value) ? "Element found" : "Element not found") << endl;
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