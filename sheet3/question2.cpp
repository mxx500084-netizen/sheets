#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Employee {
    private:
        string Name;
        int ID;
        float Salary[4];
        string Department;
        
    public:
        Employee() {
            Name = "";
            ID = 0;
            for (int i = 0; i < 4; i++) {
                Salary[i] = 0.0;
            }
            Department = "";
        }
        
        Employee(string name, int id, float salaries[4], string department) {
            Name = name;
            ID = id;
            for (int i = 0; i < 4; i++) {
                Salary[i] = salaries[i];
            }
            Department = department;
        }
        
        Employee(const Employee &e) { // ده pass by reference عشان يعمل access لل object من غير ما يعمل copy
            Name = e.Name;
            ID = e.ID;
            for (int i = 0; i < 4; i++) {
                Salary[i] = e.Salary[i];
            }
            Department = e.Department;
        }

        float AverageNetSalary() {
            float totalSalary = 0.0;
            for (int i = 0; i < 4; i++) {
                totalSalary += Salary[i];
            }
            return totalSalary / 4;
        }

        float CompareMaxSalary(const Employee &e) {
            float maxSalary1 = *max_element(Salary, Salary + 4);
            float maxSalary2 = *max_element(e.Salary, e.Salary + 4);
            return (maxSalary1 > maxSalary2) ? maxSalary1 : maxSalary2;
        }

        float CompareMinSalary(const Employee &e) {
            float minSalary1 = *min_element(Salary, Salary + 4);
            float minSalary2 = *min_element(e.Salary, e.Salary + 4);
            return (minSalary1 < minSalary2) ? minSalary1 : minSalary2;
        }

        void displayEmployeeDetails() {
            cout << "Employee Name: " << Name << endl;
            cout << "Employee ID: " << ID << endl;
            cout << "Current Salary: $" << Salary[0] << endl;
            cout << "Department: " << Department << endl;
            cout << "Average Net Salary: $" << AverageNetSalary() << endl;
        }
};

int main() {
    cout << "\n--- Employee Class Demo ---\n";
    float salaries1[4] = {5000, 5000, 5000, 5000};
    float salaries2[4] = {6000, 6000, 6000, 6000};
    float salaries3[4] = {7000, 7000, 7000, 7000};

    Employee employee1("John Doe", 201, salaries1, "IT");
    Employee employee2("Jane Smith", 202, salaries2, "HR");
    Employee employee3("mangawy", 203, salaries3, "Finance");

    employee1.displayEmployeeDetails();
    employee2.displayEmployeeDetails();
    employee3.displayEmployeeDetails();

    cout << "\nMax Salary Employee 1 vs Employee 2: $" << employee1.CompareMaxSalary(employee2) << endl;
    cout << "Min Salary Employee 1 vs Employee 2: $" << employee1.CompareMinSalary(employee2) << endl;

    return 0;
}
