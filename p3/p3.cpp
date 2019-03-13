#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::endl;

vector<pair<int,int>> lostPositions;

void deifineFinalPos(int x, int y, char direction,  string instructions, int upper, int right) {
    int currentX = x;
    int currentY = y;
    char currentDir = direction;
    bool fellOfTable = false;
    pair<int,int> lastPos;
    for(int i = 0; i < instructions.length(); i++){
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
                lastPos.first = currentX;
                lastPos.second = currentY;
                if(currentDir == 'N') currentY = currentY + 1;
                else if(currentDir == 'W') currentX = currentX - 1;
                else if(currentDir == 'S') currentY = currentY - 1;
                else if(currentDir == 'E') currentX = currentX + 1;
                break;
        }
        if(currentY > upper || currentY < 0 || currentX > right || currentX < 0) {

            bool sentLeft = false;

            for(int i = 0; i < (int)lostPositions.size(); i++){
                if(lastPos == lostPositions[i]) {
                    sentLeft = true;
                    currentX = lastPos.first;
                    currentY = lastPos.second;
                }
            }

            if(!sentLeft) {
                cout << lastPos.first << " " << lastPos.second << " " << currentDir << " LOST" << endl;
                fellOfTable = true; 
                lostPositions.push_back(lastPos);
                break;
            } 
        }
    }
    if(!fellOfTable) cout  << currentX << " " << currentY << " " << currentDir << endl;
}

int main () {
    int upper,right;
    cin >> right;
    cin >> upper;
    char direction;
    string instructions;
    int x,y;
    while(cin >> x >> y >> direction >> instructions) {
        deifineFinalPos(x, y, direction, instructions, upper, right);
    }
    return false;
}