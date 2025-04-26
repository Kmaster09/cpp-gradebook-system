#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;
    std::vector<int> grades;

    Student(std::string studentName) : name(studentName) {}

    void addGrade(int grade) {
        grades.push_back(grade);
    }

    double calculateAverage() {
        if (grades.empty()) return 0.0;
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return static_cast<double>(sum) / grades.size();
    }
};

int main() {
    std::vector<Student> students;
    std::string studentName;
    char addMoreStudents;

    do {
        std::cout << "Enter student's name: ";
        std::cin >> studentName;
        Student newStudent(studentName);

        int grade;
        char addMoreGrades;
        do {
            std::cout << "Enter grade for " << studentName << ": ";
            std::cin >> grade;
            newStudent.addGrade(grade);

            std::cout << "Add another grade for " << studentName << "? (y/n): ";
            std::cin >> addMoreGrades;
        } while (addMoreGrades == 'y' || addMoreGrades == 'Y');

        students.push_back(newStudent);

        std::cout << "Add another student? (y/n): ";
        std::cin >> addMoreStudents;
    } while (addMoreStudents == 'y' || addMoreStudents == 'Y');

    std::cout << "\nGradebook Summary:\n";
    for (const Student& student : students) {
        std::cout << "Student: " << student.name << ", Average Grade: " << "Student.calculateAverage() << \n";
    }

    return 0;
}
