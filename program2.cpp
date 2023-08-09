/*
Name of project: Student Record Management System

The project structure informs you about the file management system. The developed program will correctly store all the students’ information. The data can be any information about the student, their personal details, roll number, academic records, etc (At least 5) along with their marks in 3 subjects along with their percentage with the grading system- A-60%+ , B- 40%+, F- <40% .

*/

#include <iostream>
using namespace std;
struct Student
{
    string name;
    int roll_number;
    int marks[3];
    float percentage;
    char grade;
};
void calculate(Student &student)
{
    int total_marks = 0;
    for (int i = 0; i < 3; i++)
    {
        total_marks += student.marks[i];
    }
    student.percentage = total_marks / 3.0;
    if (student.percentage >= 60)
        student.grade = 'A';
    else if (student.percentage >= 40)
        student.grade = 'B';
    else
        student.grade = 'F';
}
void add_record(Student students[], int &count)
{
    if (count >= 100)
    {
        cout << "\n\nStudent database is full. Cannot add more records." << endl;
        return;
    }
    Student new_student;
    cout << "Enter student name: ";
    cin >> new_student.name;
    cout << "Enter roll number: ";
    cin >> new_student.roll_number;
    cout << "Enter marks for three subjects (space-separated): ";
    for (int i = 0; i < 3; i++)
    {
        cin >> new_student.marks[i];
    }
    calculate(new_student);
    students[count] = new_student;
    count++;
    cout << "\nStudent record added successfully!" << endl;
}
void display_records(Student students[], int count)
{
    if (count == 0)
    {
        cout << "\nNo records found." << endl;
        return;
    }
    cout << "Displaying all student records below.." << endl;
    cout << "\nName\tRoll Number\tSubject1\tSubject2\tSubject3\tPercentage\tGrade" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << students[i].name << "\t" << students[i].roll_number << "\t\t"
             << students[i].marks[0] << "\t\t" << students[i].marks[1] << "\t\t"
             << students[i].marks[2] << "\t\t" << students[i].percentage << "\t\t"
             << students[i].grade << endl;
    }
}
int main()
{
    Student students[100];
    int count = 0;
    int choice;
    do
    {
        cout << "\n\n========= Student Record Management System =========" << endl;
        cout << "1. Add a new student record" << endl;
        cout << "2. Display all student records" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_record(students, count);
            break;
        case 2:
            display_records(students, count);
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}