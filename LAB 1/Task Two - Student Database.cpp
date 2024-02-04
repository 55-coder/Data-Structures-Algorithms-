#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;

// Define the Course structure
struct Course {
    string course_code;
    string course_name;
};

// Define the Grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define the Student structure
struct Student {
    string reg_number;
    string name;
    int age;
    struct Course course;
    struct Grade grade;
};

// Function to calculate the grade based on the mark
char calculateGrade(int mark) {
    if (mark > 69)
        return 'A';
    else if (mark > 59)
        return 'B';
    else if (mark > 49)
        return 'C';
    else if (mark > 39)
        return 'D';
    else
        return 'E';
}

void addStudent(vector<Student>& students) {
    if (students.size() >= 40) {
        cout << "Cannot add more than 40 students." << endl;
        return;
    }

    struct Student newStudent;
    cout << "Enter registration number: ";
    cin >> newStudent.reg_number;

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // When cin >> is used for string inputs,
    // it only captures the first word and leaves the rest in the input buffer,
    // leading to unexpected behavior in subsequent input requests.
    cout << "Enter name: ";
    getline(cin, newStudent.name);

    cout << "Enter age: ";
    cin >> newStudent.age;
    cout << "Enter course code: ";
    cin >> newStudent.course.course_code;

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter course name: ";
    getline(cin, newStudent.course.course_name);

    // Initialize grade with default values
    newStudent.grade.mark = -1; // -1 indicates that the grade has not been calculated yet
    newStudent.grade.the_grade = ' ';

    students.push_back(newStudent);
    cout << "Student added successfully." << endl;
}

// Function to edit a student's details
void editStudent(vector<Student>& students) {
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
            return;
        }
    }

    cout << "Student with registration number " << regNumber << " not found." << endl;
}

// Function to add marks and calculate grades
void addMarksAndCalculateGrades(vector<Student>& students) {
    string regNumber;
    cout << "Enter registration number to add marks: ";
    cin >> regNumber;

    for (auto& student : students) {
        if (student.reg_number == regNumber) {
            cout << "Enter marks: ";
            cin >> student.grade.mark;

            // Calculate grade based on marks
            student.grade.the_grade = calculateGrade(student.grade.mark);

            cout << "Marks and grade added successfully." << endl;
            return;
        }
    }

    cout << "Student with registration number " << regNumber << " not found." << endl;
}

// Function to display student details
void displayStudentDetails(const Student& student) {
    cout << "Registration Number: " << student.reg_number << endl;
    cout << "Name: " << student.name << endl;
    cout << "Age: " << student.age << endl;
    cout << "Course Code: " << student.course.course_code << endl;
    cout << "Course Name: " << student.course.course_name << endl;
    cout << "Marks: " << ((student.grade.mark != -1) ? to_string(student.grade.mark) : "N/A") << endl;
    cout << "Grade: " << ((student.grade.the_grade != ' ') ? string(1, student.grade.the_grade) : "N/A") << endl;
}

// Function to display all students' details
void displayAllStudents(const vector<Student>& students) {
    //if the students file is empty,
    //it returns no students found
    if (students.empty()) {
        cout << "No students found." << endl;
        return;
    }

    //Displays student content
    for (const auto& student : students) {
        cout << "----------------------" << endl;
        displayStudentDetails(student);
    }
}

// Function to save students' information to a file
void saveToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);

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
        struct Student student;
        getline(file, student.reg_number);
        getline(file, student.name);
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

    //Initialize the file and name
    const string filename = "students_data.txt";

    // Load data from the file
    loadFromFile(students, filename);

    int choice;
    do {
        cout << "\nMenu:\n1. Add Student\n2. Edit Student Details\n3. Add Marks and Calculate Grades\n4. Display All Students\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                editStudent(students);
                break;
            case 3:
                addMarksAndCalculateGrades(students);
                break;
            case 4:
                displayAllStudents(students);
                break;
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
