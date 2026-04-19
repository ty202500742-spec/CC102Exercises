#include <iostream>
#include <fstream>
using namespace std;

int main() {

    fstream file;

    file.open("color.txt", ios::out);
    if(!file.is_open()){

           cout<< "failed to write";

           return 1;

    }
    file << "red\n";
            file << "blue\n";
            file << "cyan\n";
            file << "purple\n";
            file << "green";

            file.close();

            cout<< "write successfully";

        ifstream readfile("color.txt");

        if(!readfile.is_open()){

            cout<< "di na open";
            return 1;
        }

        ofstream copyfile("color_copy.txt");

        if(!copyfile.is_open()){

            cout<<" di na copy";
            return 1;
        }

        string line;

        while(getline(readfile, line)){

            copyfile << line <<endl;
        }

        readfile.close();
        copyfile.close();

        cout<< " copied succesfully";

    return 0;
}
