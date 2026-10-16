#include <iostream>
#include <string>

using namespace std;

class patient {
    private:
        string Name;
        int PatientID;
        int Age;
        float totalcost;
        float costperday;
        int days;
        string Disease;
        string Doctor;
        static int patientCount;

    public:
        patient() {
            Name = "";
            patientCount++;
            PatientID = 1000 + patientCount;
            Age = 0;
            Disease = "";
            Doctor = "";
            totalcost = 0.0;
            costperday = 0.0;
            days = 0;
        }
        
        patient(string name, int age, string disease, string doctor) {
            Name = name;
            patientCount++;
            PatientID = 1000 + patientCount; 
            Age = age;
            Disease = disease;
            Doctor = doctor;
            totalcost = 0.0;
            costperday = 0.0;
            days = 0;
        }

        void readPatientDetails() {
            cout << "Enter Patient Name: ";
            cin >> Name;
            cout << "Enter Age: ";
            cin >> Age;
            cout << "Enter Disease: ";
            cin >> Disease;
            cout << "Enter Doctor's Name: ";
            cin >> Doctor;
        }
        
        void calculateCost() {
            cout << "Enter cost per day: ";
            cin >> costperday;
            cout << "Enter number of days: ";
            cin >> days;
            totalcost = costperday * days;
        }
        
        void discountfor60s() {
            if (Age >= 60) {
                totalcost *= 0.9;
            }
        }

        static int getPatientCount() {
            return patientCount;
        }

        void displayPatientDetails() {
            cout << "Patient Name: " << Name << endl;
            cout << "Patient ID: " << PatientID << endl;
            cout << "Age: " << Age << endl;
            cout << "Disease: " << Disease << endl;
            cout << "Doctor: " << Doctor << endl;
            cout << "Total Cost: $" << totalcost << endl;
        }
};

int patient::patientCount = 0;

int main() {
    cout << "\n--- Patient Class Demo ---\n";
    patient p1("Fathiya", 65, "Flu", "Dr. Absalam");
    patient p2("Ahmed", 45, "Cold", "Dr. Rabie");
    patient p3("Sarah", 70, "Diabetes", "Dr. Rabie"); 
    
    cout << "\nPatient 1 Data Entry:\n";
    p1.calculateCost();
    p1.discountfor60s();
    p1.displayPatientDetails();
    
    cout << "\nPatient 2 Data Entry:\n";
    p2.calculateCost();
    p2.discountfor60s();
    p2.displayPatientDetails();
    
    cout << "\nPatient 3 Data Entry:\n";
    p3.calculateCost();
    p3.discountfor60s();
    p3.displayPatientDetails();
    
    cout << "\nTotal Patients: " << patient::getPatientCount() << endl;

    return 0;
}
