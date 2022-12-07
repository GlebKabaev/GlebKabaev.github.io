#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct PersonR {
    char name[25];
    int marks[5];
}B;

long Answer;
long size_pred;

int main() {
    ifstream fR;
    ofstream fA;
    const char* nameR = "REQUEST.bin";
    const char* nameA = "ANSWER.bin";
    cout << "Server is working.";
    fR.open(nameR, ios::binary);
    fR.seekg(0, ios::end);
    size_pred = fR.tellg();
    fR.close();
    while (true) {
        fR.open(nameR, ios::binary);
        fR.seekg(0, ios::end);
        while (size_pred >= fR.tellg()) {
            Sleep(100);
            fR.seekg(0, ios::end);
        }
        fR.seekg(size_pred, ios::beg);
        fR.read((char*)&B, sizeof(B));
        size_pred = fR.tellg();
        fR.close();
        Answer = 0;
        for (int i = 0; i < 5; i++)
            if (B.marks[i] == 2) Answer++;
        fA.open(nameA, ios::binary | ios::app);
        fA.write((char*)&B.name, sizeof(B.name));
        fA.write((char*)&Answer, sizeof(Answer));
        fA.close();
    }
}