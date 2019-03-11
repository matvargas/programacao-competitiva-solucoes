#include <iostream>
#include <string>
using namespace std;
using std::endl;

void deifineFinalPos(string initialPos, string instructions) {
    int currentY = (int)initialPos[0] - 48;
    int currentX = (int)initialPos[2] - 48;
    char currentDir = (char)initialPos[4];
    cout << "Y: " << currentY << " - X: " << currentX << " - Dir: " << currentDir << endl;
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
        cout << currentY << currentX << currentDir << endl;
    }
}

int main () {
    int upper,right;
    cin >> upper;
    cin >> right;
    while(!cin.eof()) {
        string initialPos, instructions;
        getline(cin, initialPos);
        if(initialPos != "" && initialPos != "/n"){
            getline(cin, instructions);
//            cout << "Lí isso: " << initialPos << endl;
//            cout << "Lí isso: " << instructions << endl;
            deifineFinalPos(initialPos, instructions);
        }
    }
    return false;
}