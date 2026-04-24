#include <iostream>
#include <fstream>
using namespace std;

bool prime(int n){
    if(n <= 1) return false;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){

    ifstream readfile("NUMS.txt");

    if(!readfile.is_open()){
        cout << "File could not be opened.";
        return 1;
    }

    int num;
    int isPrime = 0;

    while(readfile >> num){
        if(prime(num)){
            isPrime++;
        }
    }

    cout << "Number of Prime numbers: " << isPrime << endl;

    readfile.close();
    return 0;
}
