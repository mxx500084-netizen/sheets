#include <iostream>
#include <cmath>
using namespace std;

class Data {
    private:
        float D[30];
        char T[10];
        int n;
        
    public:
        int Factorial(int num) {
            if (num < 0) {
                return -1; 
            }
            int fact = 1;
            for (int i = 1; i <= num; i++) {
                fact *= i;
            }
            return fact;
        }

        bool CheckPrime(int num) {
            if (num <= 1) {
                return false;
            }
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
        }

        void readDataForD_array_and_T_array() {
            cout << "Enter the number of elements (max 10): ";
            cin >> n;
            if (n > 10) n = 10; 

            cout << "Enter " << n << " elements for D:\n";
            for (int i = 0; i < n; i++) {
                cin >> D[i];
                
                if (CheckPrime((int)D[i])) {
                    T[i] = 'Y';
                } else {
                    T[i] = 'N';
                }
            }
        }

        long long SumPrimeFactorials() {
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                if (T[i] == 'Y') {
                    sum += Factorial((int)D[i]);
                }
            }
            return sum;
        }

        long long ProductNonPrimeFactorials() {
            long long product = 1;
            bool validElementsFound = false;
            
            for (int i = 0; i < n; i++) {
                if (T[i] == 'N' && (int)D[i] != 0) {
                    product *= Factorial((int)D[i]);
                    validElementsFound = true;
                }
            }

            return validElementsFound ? product : 0; 
        }

        void DisplayTable() {
            cout << "\n--- Data Table ---\n";
            cout << "Index\tD[i]\tT[i]\n";
            cout << "------------------\n";
            for (int i = 0; i < n; i++) {
                cout << i << "\t" << D[i] << "\t" << T[i] << "\n";
            }
            cout << "------------------\n";
        }
};

int main() {
    Data myData;
    myData.readDataForD_array_and_T_array();
    myData.DisplayTable();
    cout << "Sum of factorials (Prime elements): " << myData.SumPrimeFactorials() << "\n";
    cout << "Product of factorials (Non-prime, non-zero elements): " << myData.ProductNonPrimeFactorials() << "\n";

    return 0;
}
