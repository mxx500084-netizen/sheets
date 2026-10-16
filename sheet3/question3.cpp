#include <iostream>
#include <cmath>

using namespace std;

class Complex {
    private:
        float real;
        float imag;

    public:
        Complex() {
            real = 0.0;
            imag = 0.0;
        }
        
        Complex(float r, float i) {
            real = r;
            imag = i;
        }
        
        float getReal() {
            return real;
        }
        
        float getImag() {
            return imag;
        }
        
        float getMagnitude() const {
            return sqrt((real * real) + (imag * imag));
        }

        void compareComplex(const Complex &c) {
            if (real == c.real && imag == c.imag) {
                cout << "The complex numbers are equal." << endl;
            } else {
                cout << "The complex numbers are not equal." << endl;
            }
        }
        
        bool returnbiggerComplex(const Complex &c) { // ده pass by reference عشان يعمل access لل object من غير ما يعمل copy
            float mag1 = getMagnitude();
            float mag2 = c.getMagnitude();
            
            if (mag1 > mag2) {
                cout << "The first complex number is bigger." << endl;
                return true;
            } else if (mag1 < mag2) {
                cout << "The second complex number is bigger." << endl;
                return false;
            } else {
                cout << "Both complex numbers have the same magnitude." << endl;
                return false;
            }
        }
        
        void negateComplex() {
            real = -real;
            imag = -imag;
        }
        
        void displayComplex() {
            cout << "Complex Number: " << real << " + " << imag << "i" << endl;
        }
};

int main() {
    cout << "\n--- Complex Class Demo ---\n";
    Complex c1(3.0, 4.0);
    Complex c2(3.0, 4.0);
    Complex c3(5.0, 2.0);

    c1.displayComplex();
    c2.displayComplex();
    c3.displayComplex();

    c1.compareComplex(c2);
    c1.compareComplex(c3);

    c1.returnbiggerComplex(c3);
    
    c1.negateComplex();
    c1.displayComplex();

    return 0;
}
