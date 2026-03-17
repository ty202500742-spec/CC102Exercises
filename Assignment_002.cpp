#include <iostream>
using namespace std;

void analyzeGrades(int *matrix, int students, int subjects) {
    
    cout << "\nGrade Matrix:\n";
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout << *(matrix + i * subjects + j) << "\t";
        }
        cout << endl;
    }

    
    cout << "\nAverage grade per student:\n";
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < subjects; j++) {
            sum += *(matrix + i * subjects + j);
        }
        double avg = (double)sum / subjects;
        cout << "Student " << i + 1 << ": " << avg << endl;
    }

    
    int highest = *matrix;
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            int value = *(matrix + i * subjects + j);
            if (value > highest) {
                highest = value;
            }
        }
    }

    cout << "\nHighest grade in the matrix: " << highest << endl;
}

int main() {
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    
    int *grades = new int[students * subjects];

    
    cout << "\nEnter grades:\n";
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout << "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin >> *(grades + i * subjects + j);
        }
    }

    
    analyzeGrades(grades, students, subjects);

    
    delete[] grades;

    return 0;
}