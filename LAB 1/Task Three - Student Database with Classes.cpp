#include <vector>

using namespace std;

// Define the Course class
class Course {
public:
    string course_code;
    string course_name;
};

// Define the Grade class
class Grade {
public:
    int mark;
    char the_grade;

    // Function to calculate the grade based on the mark
    void calculateGrade() {
        if (mark > 69)
            the_grade = 'A';
        else if (mark > 59)
            the_grade = 'B';
        else if (mark > 49)
            the_grade = 'C';
        else if (mark > 39)
            the_grade = 'D';
        else
            the_grade = 'E';
    }
};

// Define the Student class
class Student {
public:
    string reg_number;
    string name;
    int age;
    Course course;
    Grade grade;

    // Function to display student details
    void displayStudentDetails() const {
        cout << "Registration Number: " << reg_number << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Course Code: " << course.course_code << endl;
        cout << "Course Name: " << course.course_name << endl;
        cout << "Marks: " << ((grade.mark != -1) ? to_string(grade.mark) : "N/A") << endl;
        cout << "Grade: " << ((grade.the_grade != ' ') ? string(1, grade.the_grade) : "N/A") << endl;
    }

    // Function to add marks and calculate grades
    void addMarksAndCalculateGrades() {
        cout << "Enter marks: ";
        cin >> grade.mark;

        // Calculate grade based on marks
        grade.calculateGrade();

        cout << "Marks and grade added successfully." << endl;
    }
};

int main() {
    vector<Student> students;

    int choice;
    do {
        cout << "\nMenu:\n1. Add Student\n2. Edit Student Details\n3. Add Marks and Calculate Grades\n4. Display All Students\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (students.size() >= 40) {
                    cout << "Cannot add more than 40 students." << endl;
                    break;
                }

                Student newStudent;
                cout << "Enter registration number: ";
                cin >> newStudent.reg_number;
                cout << "Enter name: ";
                cin >> newStudent.name;
                cout << "Enter age: ";
                cin >> newStudent.age;
                cout << "Enter course code: ";
                cin >> newStudent.course.course_code;
                cout << "Enter course name: ";
                cin >> newStudent.course.course_name;

                // Initialize grade with default values
                newStudent.grade.mark = -1; // -1 indicates that the grade has not been calculated yet
                newStudent.grade.the_grade = ' ';

                students.push_back(newStudent);
                cout << "Student added successfully." << endl;
                break;
            }
            case 2: {
                string regNumber;
                cout << "Enter registration number to edit: ";
                cin >> regNumber;

                for (auto& student : students) {
                    if (student.reg_number == regNumber) {
                        cout << "Enter new name: ";
                        cin >> student.name;
                        cout << "Enter new age: ";
                        cin >> student.age;
                        cout << "Student details updated successfully." << endl;
                        break;
                    }
                }

                cout << "Student with registration number " << regNumber << " not found." << endl;
                break;
            }
            case 3: {
                string regNumber;
                cout << "Enter registration number to add marks: ";
                cin >> regNumber;

                for (auto& student : students) {
                    if (student.reg_number == regNumber) {
                        student.addMarksAndCalculateGrades();
                        break;
                    }
                }

                cout << "Student with registration number " << regNumber << " not found." << endl;
                break;
            }
            case 4: {
                if (students.empty()) {
                    cout << "No students found." << endl;
                    break;
                }

                for (const auto& student : students) {
                    cout << "----------------------" << endl;
                    student.displayStudentDetails();
                }
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
