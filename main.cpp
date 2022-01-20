#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    // File reader
    string line;
    string filename;
    bool status = false;
    do
    {
        cout << "Nama File : ";
        cin >> filename;
        ifstream myfile (filename);
        status = myfile.is_open();
    } while (!status);
    ifstream myfile (filename);

    while (getline (myfile, line)){
        cout << line << endl;
    }
    myfile.close();
}