#include <iostream>
using namespace std;


//Task 1:
template <typename Type>
class List {
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    List(int size = 10) : maxSize(size), currentSize(0) {
        arr = new Type[maxSize];
    }
    List(const List& other) {
        maxSize = other.maxSize;
        currentSize = other.currentSize;
        arr = new Type[maxSize];
        for (int i = 0; i < currentSize; i++) {
            arr[i] = other.arr[i];
        }
    }
    virtual ~List() {
        delete[] arr;
    }

    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
};

//Task 2:
template <typename Type>
class MyList : public List<Type> {
public:
    MyList(int size = 10) : List<Type>(size) {}
    MyList(const MyList& other) : List<Type>(other) {}
    ~MyList() {}

    bool empty() {
        return this->currentSize == 0;
    }

    bool full() {
        return this->currentSize == this->maxSize;
    }

    int size() {
        return this->currentSize;
    }

    bool insertAt(int index, Type value) {
        if (index < 0 || index > this->currentSize || this->full()) {
            return false;
        }
        for (int i = this->currentSize; i > index; i--) {
            this->arr[i] = this->arr[i - 1];
        }
        this->arr[index] = value;
        this->currentSize++;
        return true;
    }

    Type last() {
        if (!empty()) {
            return this->arr[this->currentSize - 1];
        }
        throw runtime_error("List is empty");
    }

    bool search(Type value) {
        for (int i = 0; i < this->currentSize; i++) {
            if (this->arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    void addElementAtFirstIndex(Type value) {
        insertAt(0, value);
    }

    void addElementAtLastIndex(Type value) {
        if (!this->full()) {
            this->arr[this->currentSize++] = value;
        }
    }

    Type removeElementFromEnd() {
        if (!empty()) {
            return this->arr[--this->currentSize];
        }
        throw runtime_error("List is empty");
    }

    void removeElementFromStart() {
        if (!empty()) {
            for (int i = 0; i < this->currentSize - 1; i++) {
                this->arr[i] = this->arr[i + 1];
            }
            this->currentSize--;
        }
    }
};

//Task 3
template <typename Type>
class CustomList : public MyList<Type> {
public:
    CustomList(int size = 10) : MyList<Type>(size) {}
    CustomList(const CustomList& other) : MyList<Type>(other) {}
    ~CustomList() {}

    Type sum_ofPrime() {
        Type sum = 0;
        for (int i = 0; i < this->currentSize; i++) {
            if (isPrime(this->arr[i])) {
                sum += this->arr[i];
            }
        }
        return sum;
    }

    Type secondMaxEven() {
        Type maxEven = -1, secondMaxEven = -1;
        for (int i = 0; i < this->currentSize; i++) {
            if (this->arr[i] % 2 == 0) {
                if (this->arr[i] > maxEven) {
                    secondMaxEven = maxEven;
                    maxEven = this->arr[i];
                }
                else if (this->arr[i] > secondMaxEven && this->arr[i] != maxEven) {
                    secondMaxEven = this->arr[i];
                }
            }
        }
        return secondMaxEven;
    }

    Type secondMinOdd() {
        Type minOdd = INT_MAX, secondMinOdd = INT_MAX;
        for (int i = 0; i < this->currentSize; i++) {
            if (this->arr[i] % 2 != 0) {
                if (this->arr[i] < minOdd) {
                    secondMinOdd = minOdd;
                    minOdd = this->arr[i];
                }
                else if (this->arr[i] < secondMinOdd && this->arr[i] != minOdd) {
                    secondMinOdd = this->arr[i];
                }
            }
        }
        return secondMinOdd;
    }

    void printDuplicates() {
        for (int i = 0; i < this->currentSize; i++) {
            for (int j = i + 1; j < this->currentSize; j++) {
                if (this->arr[i] == this->arr[j]) {
                    cout << this->arr[i] << " ";
                    break;
                }
            }
        }
        cout << endl;
    }

    void rotateClockwise(int r) {
        int half = this->currentSize / 2;
        for (int i = 0; i < r; i++) {
            Type temp = this->arr[half - 1];
            for (int j = half - 1; j > 0; j--) {
                this->arr[j] = this->arr[j - 1];
            }
            this->arr[0] = temp;

            temp = this->arr[this->currentSize - 1];
            for (int j = this->currentSize - 1; j > half; j--) {
                this->arr[j] = this->arr[j - 1];
            }
            this->arr[half] = temp;
        }
    }

    void rotateAntiClockwise(int rt) {
        int half = this->currentSize / 2;
        for (int i = 0; i < rt; i++) {
            Type temp = this->arr[0];
            for (int j = 0; j < half - 1; j++) {
                this->arr[j] = this->arr[j + 1];
            }
            this->arr[half - 1] = temp;

            temp = this->arr[half];
            for (int j = half; j < this->currentSize - 1; j++) {
                this->arr[j] = this->arr[j + 1];
            }
            this->arr[this->currentSize - 1] = temp;
        }
    }
};