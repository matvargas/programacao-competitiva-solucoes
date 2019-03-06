#include <iostream>
#include <string>
using namespace std;
using std::endl;


bool result = false;
string actualyTextOnVerification = "";
int slimpCount = 0;

bool isSlump(string str) {


    if(str[0] != 'D' && str[0] != 'E') { return false; }
    if(str[1] != 'F' || str[str.size() - 1] == 'F') { return false; }
    int lastIndexOfF = -1;
    int numberOfFs = 0;
    for(std::string::size_type i = str.find('F'); i < str.size(); ++i) {
        if(str[i] != 'F') {
            lastIndexOfF = i;
            break;
        } else {
            numberOfFs ++;
        }
    }
    if(str[lastIndexOfF] != 'G') {
        if(!isSlump(str.substr(lastIndexOfF))) { return false; }
    } else if (str[str.length() - 1] != 'G') {
        return false;
    } else {
        result = true;
    }


    return result;
}

bool isSlimp(string str) {


    if(str[0] != 'A') {
        return 0;  
    }

    if (str[1] == 'H') {
        if(str.length() > 2) {
            if(!isSlump(str.substr(2))) { return false; }
            return true;
        } else {
            if(str.compare(actualyTextOnVerification) == 0) {
                return false;
            } else {
                return true;
            }
        }
    }

    if(str[1] == 'B') {
        int subSlimpEndIndex = (str.find('C') - slimpCount++);
        if(subSlimpEndIndex == -1) { return false; } 
        if(!isSlimp(str.substr(2,subSlimpEndIndex - 1))) {return false; }
        if(subSlimpEndIndex + 1 == str.length() - 1){ return false; } // Is just a slimpy

        int cCounter = 0;
        if(subSlimpEndIndex != (str.length() - 1)) {
            int sufixLength = str.substr(subSlimpEndIndex + 1 ).length();
            for (int i = 0; i < sufixLength - 1; i++) {
                if(str.substr(subSlimpEndIndex + 1)[i] == 'C') {
                    cCounter ++;
                }
            }
        }

        if(!isSlump(str.substr(subSlimpEndIndex + 1 + cCounter))) { return false; }

        result = true;
    } else {
        int subSlimpEndIndex = (str.find('C'));
        if(subSlimpEndIndex == -1) { return false; } 
        if(!isSlump(str.substr(1,subSlimpEndIndex - 1))) { return false; }

        if(subSlimpEndIndex != (str.length() - 1)) {
            if(!isSlump(str.substr(subSlimpEndIndex + 1))) {return false; }
        }
        result = true;
    }

    return result;

}

int main() {

    int slurpyCount = 0;
    int i = 0;
    cin >> slurpyCount;
    string textsToVerify[slurpyCount];
    for(i = 0; i < slurpyCount; i++) {
        string str = ""; 
        cin >> str;
        textsToVerify[i] = str;
    } 
    
    cout << "SLURPYS OUTPUT" << endl;
    for(i = 0; i < slurpyCount; i++) {
        actualyTextOnVerification = textsToVerify[i];
        slimpCount = 0;
        if(isSlimp(textsToVerify[i])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}