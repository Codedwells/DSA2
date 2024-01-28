#include <iostream>
#include <string>
using namespace std;

// Define Course structure
struct Course {
    string course_code;
    string course_name;
};

// Define Grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define Student structure
struct Student {
    string reg_number;
    string name;
    int age;
    Course course;
    Grade grades;
    bool grades_calculated; // Flag to check if grades are already calculated
};

// Function prototypes
void addStudent(Student students[], int& numStudents);
void editStudent(Student students[], int numStudents);
void addMarksAndCalculateGrades(Student students[], int numStudents);

int main() {
    const int MAX_STUDENTS = 40;
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    char choice;
    do {
        cout << "1. Add Student\n";
        cout << "2. Edit Student Details\n";
        cout << "3. Add Marks and Calculate Grades\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addStudent(students, numStudents);
                break;
            case '2':
                editStudent(students, numStudents);
                break;
            case '3':
                addMarksAndCalculateGrades(students, numStudents);
                break;
            case '4':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}

void addStudent(Student students[], int& numStudents) {
    if (numStudents < 40) {
        cout << "Enter registration number: ";
        cin >> students[numStudents].reg_number;

        cout << "Enter name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, students[numStudents].name);

        cout << "Enter age: ";
        cin >> students[numStudents].age;

        cout << "Enter course code: ";
        cin >> students[numStudents].course.course_code;

        cout << "Enter course name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, students[numStudents].course.course_name);

        students[numStudents].grades_calculated = false; // Initialize grades_calculated flag

        numStudents++;
        cout << "Student added successfully.\n";
    } else {
        cout << "Maximum number of students reached.\n";
    }
}

void editStudent(Student students[], int numStudents) {
    if (numStudents > 0) {
        string regNum;
        cout << "Enter registration number to edit: ";
        cin >> regNum;

        int index = -1;
        for (int i = 0; i < numStudents; ++i) {
            if (students[i].reg_number == regNum) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            cout << "Enter new age: ";
            cin >> students[index].age;

            cout << "Enter new course code: ";
            cin >> students[index].course.course_code;

            cout << "Enter new course name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, students[index].course.course_name);

            cout << "Student details edited successfully.\n";
        } else {
            cout << "Student not found.\n";
        }
    } else {
        cout << "No students to edit.\n";
    }
}

void addMarksAndCalculateGrades(Student students[], int numStudents) {
    if (numStudents > 0) {
        string regNum;
        cout << "Enter registration number to add marks: ";
        cin >> regNum;

        int index = -1;
        for (int i = 0; i < numStudents; ++i) {
            if (students[i].reg_number == regNum) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            cout << "Enter mark (between 0 and 100): ";
            cin >> students[index].grades.mark;

            // Calculate grade based on the grading system
            if (students[index].grades.mark > 69) {
                students[index].grades.the_grade = 'A';
            } else if (students[index].grades.mark > 59) {
                students[index].grades.the_grade = 'B';
            } else if (students[index].grades.mark > 49) {
                students[index].grades.the_grade = 'C';
            } else if (students[index].grades.mark > 39) {
                students[index].grades.the_grade = 'D';
            } else {
                students[index].grades.the_grade = 'E';
            }

            students[index].grades_calculated = true; // Set grades_calculated flag

            cout << "Marks added and grades calculated successfully.\n";
        } else {
            cout << "Student not found.\n";
        }
    } else {
        cout << "No students to add marks.\n";
    }
}
