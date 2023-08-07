#include <iostream>

using namespace std;

class Fractions {
public:
    Fractions(int wholePart = 0, unsigned short fractionalPart = 0)
        : wholePart(wholePart), fractionalPart(fractionalPart) {}

    int getWholePart() const { return wholePart; }
    unsigned short getFractionalPart() const { return fractionalPart; }

    Fractions operator+(const Fractions& other) const {
        int newWholePart = wholePart + other.wholePart;
        unsigned short newFractionalPart = fractionalPart + other.fractionalPart;
        if (newFractionalPart >= 10000) {
            newWholePart++;
            newFractionalPart -= 10000;
        }
        return Fractions(newWholePart, newFractionalPart);
    }

    Fractions operator-(const Fractions& other) const {
        int newWholePart = wholePart - other.wholePart;
        int newFractionalPart = fractionalPart - other.fractionalPart;
        if (newFractionalPart < 0) {
            newWholePart--;
            newFractionalPart += 10000;
        }
        return Fractions(newWholePart, newFractionalPart);
    }

    Fractions operator*(const Fractions& other) const {
        int newWholePart = wholePart * other.wholePart;
        unsigned long long newFractionalPart = static_cast<unsigned long long>(fractionalPart) * other.fractionalPart / 10000;
        return Fractions(newWholePart, static_cast<unsigned short>(newFractionalPart));
    }

    bool operator==(const Fractions& other) const {
        return wholePart == other.wholePart && fractionalPart == other.fractionalPart;
    }

    bool operator!=(const Fractions& other) const {
        return !(*this == other);
    }

    bool operator<(const Fractions& other) const {
        if (wholePart < other.wholePart) {
            return true;
        }
        else if (wholePart > other.wholePart) {
            return false;
        }
        else {
            return fractionalPart < other.fractionalPart;
        }
    }

    bool operator>(const Fractions& other) const {
        return !(*this < other) && !(*this == other);
    }

    bool operator<=(const Fractions& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>=(const Fractions& other) const {
        return (*this > other) || (*this == other);
    }

private:
    int wholePart;
    unsigned short fractionalPart;
};

int main() {
    Fractions a(3, 7500);
    Fractions b(2, 2500);

    Fractions sum = a + b;
    Fractions difference = a - b;
    Fractions product = a * b;

    cout << "a + b = " << sum.getWholePart() << " " << sum.getFractionalPart() << endl;
    cout << "a - b = " << difference.getWholePart() << " " << difference.getFractionalPart() << endl;
    cout << "a * b = " << product.getWholePart() << " " << product.getFractionalPart() << endl;

    if (a == b) {
        cout << "a is equal to b" << endl;
    }
    else if (a != b) {
        cout << "a is not equal to b" << endl;
    }

    if (a < b) {
        cout << "a is less than b" << endl;
    }
    else if (a > b) {
        cout << "a is greater than b" << endl;
    }

    return 0;
}
