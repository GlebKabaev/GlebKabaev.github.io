#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct PersonR {
    char name[25];
    int marks[5];
}A;

int main() {
    const char* nameR = "REQUEST.bin";
    const char* nameA = "ANSWER.bin";
    ifstream f_ANS;
    ofstream f_REQ;
    long pred_size; // предварит размер файла
    int Answer;
    while (true) {
        int students_col;
        cout << "Enter number of Students: ";
        cin >> students_col;
        f_ANS.open(nameA, ios::binary);
        f_ANS.seekg(0, ios::end);
        pred_size = f_ANS.tellg();
        f_ANS.close();
        for (int i = 0; i < students_col; i++) {
            cout << "Enter request: Name and array of 5 marks" << endl;
            cin >> A.name;
            for (int i = 0; i < 5; i++) cin >> A.marks[i];
            f_REQ.open(nameR, ios::app | ios::binary);
            f_REQ.write((char*)&A, sizeof(A));
            f_REQ.close();
        }
        for (int i = 0; i < students_col; i++) {
            f_ANS.open(nameA, ios::binary);
            f_ANS.seekg(0, ios::end);
            while (pred_size >= f_ANS.tellg()) {
                Sleep(100);
                f_ANS.seekg(0, ios::end);
            }
            f_ANS.seekg(pred_size, ios::beg);
            f_ANS.read((char*)&A.name, sizeof(A.name));
            f_ANS.read((char*)&Answer, sizeof(Answer));
            pred_size = f_ANS.tellg();
            f_ANS.close();
            if (Answer) cout << A.name << " has " << Answer << " debts." << endl;
        }
    }
    return 0;
}