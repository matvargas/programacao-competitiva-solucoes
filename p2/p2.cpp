#include <iostream>
#include <string>
using namespace std;
using std::endl;


bool shouldShowDebug;
bool result = false;
bool slimpVerification;
bool slumpVerification;

bool isSlimp(string str) {

    if(shouldShowDebug) cout << "Slimp - Evaluating: " << str << endl;

    if(str[0] != 'A') {
        if(shouldShowDebug) cout << "First char is not a 'A': " << str[0] << endl;
        return false;  
    }

    if(str.length() < 2){
        if(shouldShowDebug) cout << "Slimp size is lower than 2 " << str.length() << endl; 
        return false;
    } else if(str.length() == 2){
        if(str[1] == 'H') {
            slimpVerification = true;
            if(shouldShowDebug) cout << "Slimp identified: " << str << endl; 
        } else {
            return false;
        }
    } else if(str.length() > 2) {
        if(str[1] == 'B') {
            if(shouldShowDebug) cout << "Slimp has subslimps: " << str << endl;
            int lastIndexOfC = str.find_last_of('C');
            if(shouldShowDebug) cout << "index of 'C' char that shold close first 'B' occurrence: " << lastIndexOfC - 2 << endl;
            if(!isSlimp(str.substr(2, lastIndexOfC - 2))) {
               return false;
            } else {
                cout << "teste" << endl;
                slimpVerification = true;
            }
        }
    }
    if(shouldShowDebug) cout << "Slimp verification success: " << slimpVerification << endl;
    return result;

}

int main() {

    shouldShowDebug = true;
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
        slimpVerification = false;
        slumpVerification = false;
        if(isSlimp(textsToVerify[i]) && slimpVerification && slumpVerification) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        if(shouldShowDebug) {
            cout << "______" << endl;
            cout << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}