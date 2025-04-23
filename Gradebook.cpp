#include <iostream>
#include <vector>
#include <string>
#include <numeric>

class Student {
public:
    Student(const std::string& name) : name(name) {}

    void addGrade(double grade) {
        grades.push_back(grade);
    }

    double getAverageGrade() const {
        if (grades.empty()) return 0.0;
        double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
        return sum / grades.size();
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    std::vector<double> grades;
};

class Gradebook {
public:
    void addStudent(const std::string& name) {
        students.emplace_back(name);
    }

    void addGrade(const std::string& name, double grade) {
        for (auto& student : students) {
            if (student.getName() == name) {
                student.addGrade(grade);
                return;
            }
        }
        std::cerr << "Student not found: " << name << std::endl;
    }

    void printGrades() const {
        for (const auto& student : students) {
            std::cout << "Student: " << student.getName() << ", Average Grade: " << student.getAverageGrade() << std::endl;
        }
    }

private:
    std::vector<Student> students;
};

int main() {
    Gradebook gradebook;
    gradebook.addStudent("Alice");
    gradebook.addStudent("Bob");

    gradebook.addGrade("Alice", 85.5);
    gradebook.addGrade("Alice", 90.0);
    gradebook.addGrade("Bob", 78.0);

    gradebook.printGrades();

    return 0;
}


