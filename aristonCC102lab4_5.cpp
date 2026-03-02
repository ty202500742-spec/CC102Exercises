#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols, '.'));

    int cats;
    cout << "\nEnter number of cats: ";
    cin >> cats;

    vector<pair<int,int>> catPos(cats);

    for (int i = 0; i < cats; i++) {
        cout << "Cat " << i + 1 << " position: ";
        cin >> catPos[i].first >> catPos[i].second;
        grid[catPos[i].first][catPos[i].second] = 'C';
    }

    int mice;
    cout << "\nEnter number of mice: ";
    cin >> mice;

    vector<pair<int,int>> mousePos(mice);

    for (int i = 0; i < mice; i++) {
        cout << "Mouse " << i + 1 << " position: ";
        cin >> mousePos[i].first >> mousePos[i].second;
        grid[mousePos[i].first][mousePos[i].second] = 'm';
    }

    int moves;
    cout << "\nEnter moves allowed: ";
    cin >> moves;

    if (cats == 0 || mice == 0) {
        cout << "boring without two animals\n";
        return 0;
    }

    cout << "\n---------------- MAP ----------------\n\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    cout << "\n-----------------------------------\n";
    cout << "Cat | Mouse | Status\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < cats; i++) {
        for (int j = 0; j < mice; j++) {

            int distance = abs(catPos[i].first - mousePos[j].first) +
                           abs(catPos[i].second - mousePos[j].second);

            cout << " " << i + 1 << "  |   " << j + 1 << "   |   ";

            if (distance <= moves)
                cout << "Caught\n";
            else
                cout << "Escaped\n";
        }
    }

    cout << "-----------------------------------\n";

    return 0;
}
