#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

struct PrimeRange {
    int range1;
    int range2;
    int counter;
    int* num;
};

void generatePrimes(PrimeRange* range) {
    int counter = 0;
    int size = range->range2 - range->range1 + 1;
    range->num = new int[size];

    for (int i = range->range1; i <= range->range2; i++) {
        if (isPrime(i)) {
            range->num[counter] = i;
            counter++;
        }
    }

    range->counter = counter;
}
void printStructure(const PrimeRange* range) {
    cout << "Prime numbers in the range " << range->range1 << " to " << range->range2 << " are: ";

    for (int i = 0; i < range->counter; i++) {
        cout << range->num[i] << " ";
    }

    cout << endl;
    cout << "Total prime numbers: " << range->counter << endl;
}

int main() {
    PrimeRange range;

    cout << "Enter the lower range: ";
    cin >> range.range1;

    cout << "Enter the upper range: ";
    cin >> range.range2;

    generatePrimes(&range);

    printStructure(&range);

    delete[] range.num;

    return 0;
}

