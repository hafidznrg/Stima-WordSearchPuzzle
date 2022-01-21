#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool splitline(string line, vector<vector<char>> &mat, vector<vector<string>> &color){
    vector<char> vec;
    vector<string> linecolor;
    int len = 0;
    for (int i=0; i<line.length(); i++){
		if(line[i] !=' '){
			vec.push_back(line[i]);
            linecolor.push_back("\033[37m");
            len++;
		}
	}
    if (len > 0){
        mat.push_back(vec);
        color.push_back(linecolor);
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

bool check(vector<vector<char>> mat, string word, int i, int j, int ver, int hor, int &totalComparison, vector<vector<string>> &color, int idxcolor){
    int idx = 1;
    int n = word.length();
    while (idx < n && word[idx] == mat[i+ver*idx][j+hor*idx]){
        totalComparison++;
        idx++;
    }
    totalComparison++;
    if (idx == n){
        // cout << word << " (" << i << "," << j << ")" << endl;
        string warna = "\033[" + to_string(idxcolor) +"m";
        cout << warna << word << "\033[0m"  << "\tdi posisi (" << i+1 << "," << j+1 << ")" << endl;
        idx = 0;
        while (idx < n){
            color[i+ver*idx][j+hor*idx] = "\033[" + to_string(idxcolor) +"m";
            idx++;
        }
        return true;
    } else {
        return false;
    }
}


void checkWord(vector<vector<char>> mat, string word, int row, int col, int &totalComparison, vector<vector<string>> &color, int idxcolor){
    int n = word.length();
    bool found = false;
    for (int i=0; i<mat.size(); i++){
        for (int j=0; j<mat[0].size(); j++){
            totalComparison++;
            if (mat[i][j] == word[0]){
                // checking all possibilities
                // horizontal kanan
                if (col-j >= n && !found){
                    found = check(mat, word, i, j, 0, 1, totalComparison, color, idxcolor);
                }

                // horizontal kiri
                if (j+1 >= n && !found){
                    found = check(mat, word, i, j, 0, -1, totalComparison, color, idxcolor);
                }

                // vertikal atas
                if (i+1 >= n && !found){
                    found = check(mat, word, i, j, -1, 0, totalComparison, color, idxcolor);
                }

                // vertikal bawah
                if (row-i >= n && !found){
                    found = check(mat, word, i, j, 1, 0, totalComparison, color, idxcolor);
                }

                // miring kanan atas
                if (col-j >= n && i+1 >= n && !found){
                    found = check(mat, word, i, j, -1, 1, totalComparison, color, idxcolor);
                }

                // miring kanan bawah
                if (col-j >= n && row-i >= n && !found){
                    found = check(mat, word, i, j, 1, 1, totalComparison, color, idxcolor);
                }

                // miring kiri atas
                if (j+1 >= n && i+1 >= n && !found){
                    found = check(mat, word, i, j, -1, -1, totalComparison, color, idxcolor);
                }

                // miring kiri bawah
                if (j+1 >= n && row-i >= n && !found){
                    found = check(mat, word, i, j, 1, -1, totalComparison, color, idxcolor);
                }
            }
        }
    }
}

void displayPuzzle(vector<vector<char>> mat, vector<vector<string>> color){
    int row = mat.size();
    int col = mat[0].size();
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cout << color[i][j] << mat[i][j] << "\033[0m" << " ";
        }
        cout  << endl;
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
    vector<vector<string>> color;
    vector<string> word;
    while (getline (myfile, line)){
        if (!endData) {
            endData = splitline(line, mat, color);
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
    cout << "Keterangan:\n";

    for (int i=0; i< word.size(); i++){
        int idxcolor = i%6 + 31;
        checkWord(mat, word[i], row, col, totalComparison, color, idxcolor);
    }

    // display puzzle
    cout << endl;
    displayPuzzle(mat, color);

    // stop timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Total perbandingan : " << totalComparison << endl;
    cout << "Total durasi pencarian : " << duration.count() << " microseconds" << endl;
}