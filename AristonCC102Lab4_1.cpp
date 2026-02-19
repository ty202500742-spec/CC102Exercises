//ARISTON, RUDOLF DEE P. CS - 1B
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;


int main() {

char repeat;

do{
    int numStudents, numQuizzes;

    cout<<"enter number of students: ";
    cin>>numStudents;
    cout<<"enter number of quizzes: ";
    cin>>numQuizzes;


    int scores[numStudents][numQuizzes];
    double average[numStudents];

    for(int i = 0; i<numStudents; i++) {
        double sum = 0;
        cout<<"student "<<i+1<<" scores: ";
        for(int j = 0; j<numQuizzes; j++) {
            cin>>scores[i][j];
            sum+=scores[i][j];

        }
        average[i]  = sum/numQuizzes;
    }

    cout<<"student\t";
    for(int j = 1; j<=numQuizzes; j++) {
        cout<<"Q"<<j<<"\t";

    }
    cout<<"average\n";

    cout<<"============================================\n";
    for(int i = 0; i<numStudents; i++) {
        cout<<i+1<<"\t";
        for(int j= 0; j<numQuizzes; j++) {
            cout<<scores[i][j]<<"\t";

        }
        cout<<fixed<<setprecision(1)<<average[i]<<"\n";
    }
    cout<<"\ncompute again?(y/n): ";
    cin>>repeat;
    repeat = toupper(repeat);
}while( repeat == 'Y');
}