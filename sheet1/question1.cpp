#include <iostream>
#include <cmath>
using namespace std;

// ==========================================
//        QUESTION 1 HELPER FUNCTIONS
// ==========================================
void DivByEachOther(int a, int b)
{
    if (b != 0 && a % b == 0)
    {
        cout << a << " is divisible by " << b << endl;
    }
    else
    {
        cout << a << " is not divisible by " << b << endl;
    }

    if (a != 0 && b % a == 0)
    {
        cout << b << " is divisible by " << a << endl;
    }
    else
    {
        cout << b << " is not divisible by " << a << endl;
    }
}

void GreatestCommonDivisor(int a, int b)
{
    int gcd = 1;
    for (int i = 1; i <= min(abs(a), abs(b)); ++i)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    cout << "The greatest common divisor of " << a << " and " << b << " is: " << gcd << endl;
}

void CheckPrime(int a, int b)
{
    bool isPrimeA = true;
    bool isPrimeB = true;

    if (a <= 1)
        isPrimeA = false;
    else
    {
        for (int i = 2; i <= sqrt(a); ++i)
        {
            if (a % i == 0)
            {
                isPrimeA = false;
                break;
            }
        }
    }

    if (b <= 1)
        isPrimeB = false;
    else
    {
        for (int i = 2; i <= sqrt(b); ++i)
        {
            if (b % i == 0)
            {
                isPrimeB = false;
                break;
            }
        }
    }

    cout << a << " is " << (isPrimeA ? "prime" : "not prime") << endl;
    cout << b << " is " << (isPrimeB ? "prime" : "not prime") << endl;
}

void ReverseDigits(int a, int b)
{
    cout << "Reverse of " << a << " is: ";
    if (a == 0)
    {
        cout << 0;
    }
    else
    {
        while (a != 0)
        {
            cout << a % 10;
            a /= 10;
        }
    }
    cout << endl;

    cout << "Reverse of " << b << " is: ";
    if (b == 0)
    {
        cout << 0;
    }
    else
    {
        while (b != 0)
        {
            cout << b % 10;
            b /= 10;
        }
    }
    cout << endl;
}

void NumberOfDigits(int a, int b)
{
    int countA = (a == 0) ? 1 : 0;
    int countB = (b == 0) ? 1 : 0;
    int tempA = abs(a);
    int tempB = abs(b);

    while (tempA != 0)
    {
        tempA /= 10;
        countA++;
    }
    while (tempB != 0)
    {
        tempB /= 10;
        countB++;
    }
    cout << "Number of digits in first number: " << countA << endl;
    cout << "Number of digits in second number: " << countB << endl;
}

int main()
{
    cout << "\n===============================================================================================================" << endl;
    cout << "                                                    Question 1                                                 " << endl;
    cout << "===============================================================================================================" << endl;
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    DivByEachOther(num1, num2);
    GreatestCommonDivisor(num1, num2);
    CheckPrime(num1, num2);
    ReverseDigits(num1, num2);
    NumberOfDigits(num1, num2);

    return 0;
}
