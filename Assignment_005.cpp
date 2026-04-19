#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){


 fstream file;
file.open("original.txt", ios:: out);
 if(!file.is_open()){

    cout << "file did not open";
    return 1;
 }

 file << "one\n";
 file << "two\n";
 file << "three\n";
 file << "four\n";
 file << "five\n";
 file.close();

 cout<< "file created\t";



 ifstream readfile("original.txt");

 if(!readfile.is_open()){

    cout<< "cannot open\t";
    return 1;
 }
    vector<string>words;

    string line;

    while(getline(readfile, line)){

        words.push_back(line);

    }
        readfile.close();

        sort(words.begin(),words.end());

        ofstream sorted("sorted.txt");

        if(!sorted.is_open()){

            cout<< "cannot open\n";
            return 1;
        }

        for(string w : words){

            sorted << w << endl;
        }

        cout<< "\nsorted successfuly";
        return 0;
}
