#include <iostream>
#include <string>

using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    ComplexNumber() {
        real = 0.0;
        imaginary = 0.0;
    }
    
    ComplexNumber(double r, double i) {
        real = r;
        imaginary = i;
    }

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(this->real + other.real, this->imaginary + other.imaginary);
    }

    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(this->real - other.real, this->imaginary - other.imaginary);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        double r = (this->real * other.real) - (this->imaginary * other.imaginary);
        double i = (this->real * other.imaginary) + (this->imaginary * other.real);
        return ComplexNumber(r, i);
    }

    bool operator==(const ComplexNumber& other) const {
        return (this->real == other.real && this->imaginary == other.imaginary);
    }

    void print(string label) const {
        cout << label << ": " << real;
        if (imaginary >= 0) cout << " + " << imaginary << "i";
        else cout << " - " << -imaginary << "i";
        cout << endl;
    }
};

int main() {
    ComplexNumber num1(3.0, 4.0);
    ComplexNumber num2(1.0, 2.0);
    
    cout << "--- Complex Math Lab ---" << endl;
    num1.print("Number 1");
    num2.print("Number 2");
    
    ComplexNumber sum = num1 + num2;
    sum.print("Addition (1+2)");

    ComplexNumber num3(8.0, 3.0);
    ComplexNumber num4(5.0, 6.0);
    ComplexNumber diff = num3 - num4;
    diff.print("Subtraction (3-4)");

    ComplexNumber num5(2.0, 3.0);
    ComplexNumber num6(1.0, 4.0);
    ComplexNumber product = num5 * num6;
    product.print("Multiplication (5*6)");

    ComplexNumber eqCheck1(3, 5), eqCheck2(3, 5);
    if (eqCheck1 == eqCheck2) {
        cout << "Equality Check: Both complex numbers are identical." << endl;
    }

    return 0;
}
