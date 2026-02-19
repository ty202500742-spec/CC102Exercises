//ARISTON, RUDOLF DEE P. CS - 1B
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

int main() {
    char choice;
    do {
        const int Products = 5;
        const int Salespeople = 4;

        double sales[Products][Salespeople] = {0};

        int salesperson, product;
        double amount;
        char repeat;
        do {
            cout<<"Salesperson number: ";
            cin>>salesperson;

            cout<<"Product number: ";
            cin>>product;

            cout<<"amount: ";
            cin>>amount;

            sales[salesperson-1][product-1]+=amount;

            cout<<"enter more sales?(y/n) ";
            cin>>repeat;
            repeat = toupper(repeat);
        } while( repeat == 'Y');

        cout<<"\n\t\t\t\tSalesperson\n";
        cout<<setw(10)<<"Products";
        for(int sp = 1; sp<=Salespeople; sp++) {
            cout<<setw(10)<<sp;



        }
        cout<<setw(12)<<"total\n";
        cout<<"--------------------------------------------------------------\n";
        double GrandTotal = 0;
        for( int p = 0; p<Products; p++) {
            double rowTotal = 0;
            cout<<setw(10)<<p+1;
            for(int sp = 0; sp<Salespeople; sp++) {
                cout<<setw(10)<<fixed<<setprecision(2)<<sales[p][sp];
                rowTotal+=sales[p][sp];

            }

            cout<<setw(12)<<rowTotal<<"\n";
            GrandTotal += rowTotal;
        }
        cout<<"--------------------------------------------------------------\n";
        cout<<setw(10)<<"total";
        for(int sp = 0; sp<Salespeople; sp++) {
            double coltotal = 0;
            for(int p = 0; p<Products; p++) {

                coltotal+=sales[p][sp];
            }

            cout<<setw(10)<<fixed<<setprecision(2)<<coltotal;
        }

        cout<<setw(12)<<GrandTotal<<"\n";

        cout<<"\n compute again?(y/n): ";
        cin>>choice;
        choice = toupper(choice);
    } while(choice == 'Y');
}