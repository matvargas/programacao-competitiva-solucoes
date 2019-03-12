#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::endl;

void deifineFinalPos(string initialPos, string instructions, int upper, int right) {
    int currentY = (int)initialPos[2] - 48;
    int currentX = (int)initialPos[0] - 48;
    char currentDir = (char)initialPos[4];
    bool fellOfTable = false;
    cout << "X: " << currentX << " - Y: " << currentY << " - Dir: " << currentDir << endl;
    for(int i = 0; i < instructions.length(); i++){
        cout << instructions[i] << endl;
        switch (instructions[i]){
            case 'R':
                if(currentDir == 'N') currentDir = 'E';
                else if(currentDir == 'E') currentDir = 'S';
                else if(currentDir == 'S') currentDir = 'W';
                else if(currentDir == 'W') currentDir = 'N';
                break;
            case 'L':
                if(currentDir == 'N') currentDir = 'W';
                else if(currentDir == 'W') currentDir = 'S';
                else if(currentDir == 'S') currentDir = 'E';
                else if(currentDir == 'E') currentDir = 'N';
                break;
            case 'F':
                if(currentDir == 'N') currentY = currentY + 1;
                else if(currentDir == 'W') currentX = currentX - 1;
                else if(currentDir == 'S') currentY = currentY - 1;
                else if(currentDir == 'E') currentX = currentX + 1;
                break;
        }
        if(currentY > upper || currentY < 0 || currentX > right || currentX < 0) {
            cout << "CurrentY: " << currentY << " upper: " << upper << endl;
            cout << "CurrentX: " << currentX << " right: " << right << endl;
            i = instructions.length();
            fellOfTable = true;
        }
        if(!fellOfTable) cout  << currentX << " " << currentY << " " << currentDir << endl;
        else cout << currentY << " " << currentX << " " << currentDir << " " << "LOST" << endl;
    }
}

int main () {
    int upper,right;
    cin >> right;
    cin >> upper;
    while(!cin.eof()) {
        string initialPos, instructions;
        getline(cin, initialPos);
        if(initialPos != "" && initialPos != "/n"){
            getline(cin, instructions);
            deifineFinalPos(initialPos, instructions, upper, right);
        }
    }
    return false;
}