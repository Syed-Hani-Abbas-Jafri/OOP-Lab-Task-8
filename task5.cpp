#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    string studentName;
    double grades[3];
public:
    Student(string name, double g1, double g2, double g3) {
        studentName = name;
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }

    void displayGrades() const {
        cout << "\n--- Student Grade Sheet ---" << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Grade 1: " << grades[0] << endl;
        cout << "Grade 2: " << grades[1] << endl;
        cout << "Grade 3: " << grades[2] << endl;
        cout << "---------------------------" << endl;
    }

    friend class Teacher;
    friend void calculateAverageGrade(const Student& s);
};

class Teacher {
private:
    string teacherName;
public:
    Teacher(string name) {
        teacherName = name;
    }

    void modifyGrade(Student& s, int index, double newGrade) {
        if (index >= 0 && index < 3) {
            cout << "Teacher " << teacherName << " is updating Grade " << index + 1 << " to " << newGrade << "..." << endl;
            s.grades[index] = newGrade;
        } else {
            cout << "Error: Invalid grade index." << endl;
        }
    }
};

void calculateAverageGrade(const Student& s) {
    double total = 0;
    for (int i = 0; i < 3; i++) {
        total += s.grades[i];
    }
    double average = total / 3.0;
    cout << "Academic Performance: " << fixed << setprecision(2) << average << " (Average)" << endl;
}

int main() {
    Student alice("Alice Cooper", 55.0, 60.0, 58.0);
    Teacher profSmith("Professor Smith");

    cout << "Scenario: Initial Student Performance" << endl;
    alice.displayGrades();
    calculateAverageGrade(alice);

    cout << "\nScenario: Teacher intervenes and updates a grade." << endl;
    profSmith.modifyGrade(alice, 0, 85.0);

    cout << "\nScenario: Final Academic Standing" << endl;
    alice.displayGrades();
    calculateAverageGrade(alice);

    return 0;
}
