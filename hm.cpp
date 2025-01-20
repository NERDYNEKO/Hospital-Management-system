#include <iostream>
#include <string>
#include <vector>
#include <limits> // For numeric_limits
using namespace std;

// Base Class: Person
class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    virtual void displayInfo() const = 0; // Pure virtual function
};

// Derived Class: Patient
class Patient : public Person {
private:
    string disease;
    int patientid;

public:
    Patient(string name, int age, string disease, int patientid)
        : Person(name, age), disease(disease), patientid(patientid) {}

    void displayInfo() const override {
        cout << "Patient's Id: " << patientid << "\n Name: " << name
             << "\n Age: " << age << "\n Disease: " << disease << endl;
    }

    int getpatientid() const { return patientid; }
};

// Derived Class: Doctor
class Doctor : public Person {
private:
    string specialization;

public:
    Doctor(string name, int age, string specialization)
        : Person(name, age), specialization(specialization) {}

    void displayInfo() const override {
        cout << "Doctor's Name: " << name << "\n Age: " << age
             << "\n Specialization: " << specialization << endl;
    }
};

int main() {
    vector<Patient> patients; // Dynamic list of patients
    vector<Doctor> doctors;  // Dynamic list of doctors
    int choice;

    while (true) {
        cout << "\n...........Hospital Management System..................\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. View Doctors\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer and handle invalid input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input, please enter a number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        if (choice == 1) {
            string name, disease;
            int patientid, age;
            cout << "Enter Patient Name: ";
            getline(cin, name);
            cout << "Enter Patient Age: ";
            cin >> age;
            cin.ignore(); // Clear the input buffer
            cout << "Enter Patient Disease: ";
            getline(cin, disease);
            cout << "Enter Patient ID: ";
            cin >> patientid;
            cin.ignore(); // Clear the input buffer
            patients.emplace_back(name, age, disease, patientid);
            cout << "Patient added successfully!\n";

        } else if (choice == 2) {
            cout << "\n...List of Patients...\n";
            if (patients.empty()) {
                cout << "No patients available.\n";
            } else {
                for (const auto& patient : patients) {
                    patient.displayInfo();
                    cout << "------------------------\n";
                }
            }

        } else if (choice == 3) {
            string name, specialization;
            int age;
            cout << "Enter Doctor Name: ";
            getline(cin, name);
            cout << "Enter Doctor Age: ";
            cin >> age;
            cin.ignore(); // Clear the input buffer

            cout << "Enter Doctor Specialization: ";
            getline(cin, specialization);

            doctors.emplace_back(name, age, specialization);
            cout << "Doctor added successfully!\n";

        } else if (choice == 4) {
            cout << "\n...List of Doctors...\n";
            if (doctors.empty()) {
                cout << "No doctors available.\n";
            } else {
                for (const auto& doctor : doctors) {
                    doctor.displayInfo();
                    cout << "----------------------\n";
                }
            }

        } else if (choice == 5) {
            cout << "Exiting the system. Goodbye!\n";
            break;

        } else {
            cout << "Invalid choice, try again.\n" << endl;
        }
    }

    return 0;
}
