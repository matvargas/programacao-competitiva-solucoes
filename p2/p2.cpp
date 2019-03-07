#include <iostream>
#include <string>
using namespace std;
using std::endl;


bool shouldShowDebug;
bool result = false;
bool slimpVerification, slumpEvaluation;

bool isSlump(string str) {

    if(shouldShowDebug) cout << "testando slump " << str << endl;
    return result;
}

bool isSlimp(string str) {

    if(shouldShowDebug) cout << "Slimp - Evaluating : " << str << " - size:" << str.length() <<endl;

    if(str[0] != 'A') {
        if(shouldShowDebug) cout << "The evaluated text : " << str << " is not a slimp, does not start with an 'A' " << endl;
        return false;
    }

    if(str.length() == 2) {
        if(str[1] != 'H') {
            if(shouldShowDebug) cout << "The evaluated text : " << str << " is not a slimp, it has length 2 and second char is not 'H' " << endl;
            return false;
        } else {
            if(shouldShowDebug) cout << "The evaluated text : " << str << " is a slimp case 'AH' " << endl;
            slimpVerification = true;
            result = true;
        }
    } else {
        if (str[1] == 'B') {
            if(shouldShowDebug) cout << "Slimp is 'BC' type : " << str << endl;
            int lastCIndex = str.find_last_of('C');
            if(shouldShowDebug) cout << "Finding the potential end of the slimp : " << lastCIndex << " is the last occurrence of 'C' " << endl;
            string subSlimp = str.substr(2, lastCIndex - 2);
            if(shouldShowDebug) cout << "Evaluating potential subSlimp : " << subSlimp <<  endl;
            isSlimp(subSlimp);
        } else {
            if(str[1] != 'D' && str[1] != 'E') {
                if(shouldShowDebug) cout << "The evaluated text : " << str << " is not a slimp, after an 'A' has no 'B', 'D' or 'E' " << endl;
                return false;
            } else {
                
            }
        } 
    }

    if(shouldShowDebug) cout << "Slimp - result : " << result << endl;
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
        bool slimpAswer = isSlimp(textsToVerify[i]);
        bool answer = slimpAswer && slimpVerification && slumpEvaluation;
        if(shouldShowDebug) cout << "After process the results are: " << endl;
        if(shouldShowDebug) cout << "isSlimp: "<< slimpAswer << endl;
        if(shouldShowDebug) cout << "slimpVerification: "<< slimpVerification << endl;
        if(shouldShowDebug) cout << "slumpVerification: "<< slumpEvaluation << endl;
        if(shouldShowDebug) cout << "Answer is : "<< answer << endl;
        if(answer) {
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