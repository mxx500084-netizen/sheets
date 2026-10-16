# COMP205 - Object-Oriented Programming (OOP) Sheets

Solutions and assignments for the Object-Oriented Programming (OOP - COMP205) course implemented in C++.

## Repository Structure

```text
sheets/
├── sheet1/
│   ├── question1.cpp
│   ├── question2.cpp
│   └── question3.cpp
├── sheet2/
│   ├── question1.cpp
│   └── question2.cpp
└── sheet3/
    ├── question1.cpp
    ├── question2.cpp
    ├── question3.cpp
    └── question4.cpp
```

---

### Sheet 1: Fundamentals & Dynamic Arrays
- **`question1.cpp`**: Number analysis functions (divisibility check, Greatest Common Divisor [GCD], prime checking, digit reversal, and digit count).
- **`question2.cpp`**: Dynamic array operations (input/display, search and replace, index swapping, and bubble sorting using swap).
- **`question3.cpp`**: Array analysis functions (vertical listed display, array reversal, duplicate detection, and cumulative prefix sum array generation).

---

### Sheet 2: Classes, Math & 3D Geometry
- **`question1.cpp`**: `Data` class for numeric array processing, calculating factorials, checking primes, and computing factorial sums and products.
- **`question2.cpp`**: `Point_3D` class representing 3D spatial points, computing vector norms, and comparing minimum/maximum distances between objects.

---

### Sheet 3: Object-Oriented Design & Constructors
- **`question1.cpp`**: `Product` class with default, parameterized, and copy constructors, calculating net price after applying tax and discounts.
- **`question2.cpp`**: `Employee` class managing 4-month salary arrays, computing average net salary, and finding minimum/maximum salaries.
- **`question3.cpp`**: `Complex` number class supporting magnitude calculations, object comparison, and negation.
- **`question4.cpp`**: `patient` hospital record class calculating stay costs, applying senior citizen discounts, and tracking patient count with static members.

---

## Compilation & Running

Compile any question independently with `g++`:

```bash
# Example: Compile and run Sheet 1 - Question 1
g++ sheet1/question1.cpp -o q1
./q1

# Example: Compile and run Sheet 3 - Question 1
g++ sheet3/question1.cpp -o q1_s3
./q1_s3
```
