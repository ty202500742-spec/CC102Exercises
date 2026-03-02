#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        int movies, viewers;
        cout << "Enter number of movies: ";
        cin >> movies;
        cout << "Enter number of viewers: ";
        cin >> viewers;

        vector<vector<int>> ratings(movies, vector<int>(viewers));

        for (int i = 0; i < movies; i++) {
            cout << "Movie " << i + 1 << " ratings: ";
            for (int j = 0; j < viewers; j++) {
                cin >> ratings[i][j];
            }
        }

        cout << "\n---------------------------------------------------\n";
        cout << "Movie ";
        for (int j = 0; j < viewers; j++)
            cout << "V" << j + 1 << " ";
        cout << "| Average | Remarks\n";
        cout << "---------------------------------------------------\n";

        for (int i = 0; i < movies; i++) {
            double sum = 0;
            cout << setw(5) << i + 1 << " ";

            for (int j = 0; j < viewers; j++) {
                cout << setw(2) << ratings[i][j] << " ";
                sum += ratings[i][j];
            }

            double avg = sum / viewers;

            cout << "|   " << fixed << setprecision(2) << setw(5)
                 << avg << "  | ";

            if (avg >= 4.0)
                cout << "Hit\n";
            else
                cout << "Flop\n";
        }

        cout << "---------------------------------------------------\n";

        cout << "\nRun again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
