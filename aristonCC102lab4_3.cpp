#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        int students, days;
        cout << "Enter number of students: ";
        cin >> students;
        cout << "Enter number of days: ";
        cin >> days;

        vector<vector<int>> attendance(students, vector<int>(days));

        for (int i = 0; i < students; i++) {
            cout << "Student " << i + 1 << " attendance: ";
            for (int j = 0; j < days; j++) {
                cin >> attendance[i][j];
            }
        }

        cout << "\n-------------------------------------------------------------\n";
        cout << "Student ";
        for (int j = 0; j < days; j++)
            cout << "D" << j + 1 << " ";
        cout << "| Total | Percentage | Remarks\n";
        cout << "-------------------------------------------------------------\n";

        for (int i = 0; i < students; i++) {
            int total = 0;
            cout << setw(7) << i + 1 << " ";

            for (int j = 0; j < days; j++) {
                cout << setw(2) << attendance[i][j] << " ";
                total += attendance[i][j];
            }

            double percent = (double)total / days * 100;

            cout << "|   " << setw(3) << total
                 << "  |    " << setw(3) << fixed << setprecision(0)
                 << percent << "%     | ";

            if (percent < 50)
                cout << "DRP\n";
            else
                cout << "OK\n";
        }

        cout << "-------------------------------------------------------------\n";

        cout << "\nRun again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
