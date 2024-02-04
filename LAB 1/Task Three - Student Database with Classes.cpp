#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>

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
        //If it's not, it converts the integer to a string; otherwise, it returns the string "N/A."
        cout << "Marks: " << ((grade.mark != -1) ? to_string(grade.mark) : "N/A") << endl;
        // if not, it creates one string with the value of grade.the_grade
        //  otherwise, it returns the string "N/A."
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

// Function to save students' information to a file
void saveToFile(const vector<Student>& students, const string& filename) {
    //Creating an output file stream object named file,
    //associating it with a file
    //whose name is provided by the variable filename
    ofstream file(filename);

    //Writing the values to the file
    for (const auto& student : students) {
        file << student.reg_number << "\n";
        file << student.name << "\n";
        file << student.age << "\n";
        file << student.course.course_code << "\n";
        file << student.course.course_name << "\n";
        file << student.grade.mark << "\n";
        file << student.grade.the_grade << "\n";
    }

    file.close();
}

// Function to load students' information from a file
void loadFromFile(vector<Student>& students, const string& filename) {
    ifstream file(filename);

    while (file.good()) {
        Student student;
        //reading a line from the file associated with the file object
        //storing it in the reg_number member variable of the student object.
        getline(file, student.reg_number);
        getline(file, student.name);
        //reading a line from the file associated with the file object
        //storing it in the reg_number member variable of the student object.
        file >> student.age;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(file, student.course.course_code);
        getline(file, student.course.course_name);
        file >> student.grade.mark;
        file >> student.grade.the_grade;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!student.reg_number.empty()) {
            students.push_back(student);
        }
    }

    file.close();
}

int main() {
    vector<Student> students;

    //Initializing constant file and its name
    const string filename = "students_data.txt";

    // Load data from the file
    loadFromFile(students, filename);

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

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

                cout << "Enter name: ";
                getline(cin, newStudent.name);

                cout << "Enter age: ";
                cin >> newStudent.age;
                cout << "Enter course code: ";
                cin >> newStudent.course.course_code;

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

                cout << "Enter course name: ";
                getline(cin, newStudent.course.course_name);

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
                // Save data to the file before exiting
                saveToFile(students, filename);
                cout << "Data saved. Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
