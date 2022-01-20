#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool splitline(string line, vector<vector<char>> &mat){
    vector<char> vec;
    int len = 0;
    for (int i=0; i<line.length(); i++){
		if(line[i] !=' '){
			vec.push_back(line[i]);
            len++;
		}
	}
    if (len > 0){
        mat.push_back(vec);
        return false;
    } else return true;
}

void processWord(string line, vector<string> &word){
    while (line[0] == ' '){
        line = line.substr(1,line.length()-1);
    }
    while (line[line.length()-1] == ' '){
        line = line.substr(0,line.length()-1);
    }
    word.push_back(line);
}


void checkWord(vector<vector<char>> mat, string word, int row, int col, int* totalComparison){
    for (int i=0; i<mat.size(); i++){
        for (int j=0; j<mat[0].size(); j++){
            if (mat[i][j] == word[0]){
                // checking all possibilities
            }
        }
    }
}

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

    bool endData = false;
    vector<vector<char>> mat;
    vector<string> word;
    while (getline (myfile, line)){
        if (!endData) {
            endData = splitline(line, mat);
        } else {
            processWord(line, word);
        }
    }
    myfile.close();

    // main program
    // start timer
    auto start = high_resolution_clock::now();

    int row = mat.size(), col = mat[0].size(), lenWord = word.size();
    int totalComparison = 0;

    for (int i=0; i< word.size(); i++){
        checkWord(mat, word[i], row, col, &totalComparison);
    }

    // stop timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Total durasi pencarian:" << duration.count() << " microseconds" << endl;
}