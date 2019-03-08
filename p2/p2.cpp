#include <iostream>
#include <string>
using namespace std;
using std::endl;


bool shouldShowDebug;
bool result = false;
bool slimpVerification, slumpEvaluation;
bool slimpAnswer;
bool slumpKey;

bool isSlump(string str) {

    if(shouldShowDebug) cout << "Slump - Evaluating : " << str << " - size:" << str.length() <<endl;

    if(str[0] != 'D' && str[0] != 'E' || str[1] != 'F') {
        if(shouldShowDebug) cout << "The evaluated text : " << str << " is not a slump, does not start with an 'D' or 'E' or is not followed by 'Fs', it starts with: " << str[0] << endl;
        slumpKey = false;
        return false;
    }

    int i;
    for(i = 1; i < str.length() - 1; i++) {
        if (str[i] != 'F') { break; }
    }

    if(shouldShowDebug) cout << "The potential slump has a sequence of " << i - 1 << " Fs" << endl;

    if(i + 1 > str.length()) {
        if(shouldShowDebug) cout << "The text evaluated is not a slump, it ends with an: " << str[i] << " and not an 'G'" << endl;
        return false;
    } else if (str[i] == 'G') {
        if(str.length() > i + 1) {
            if(shouldShowDebug) cout << "The text evaluated has a 'G' but not at the end: " << str << endl;
            slumpKey = false;
            return false;
        }
        if((str.length() - 1) == i) {
            if(shouldShowDebug) cout << "The end of slump was identified, " << str << " is a slump. " << endl;
            slumpEvaluation = true;
        }
    } else if(str[i] == 'D' || str[i] == 'E') {
        if(shouldShowDebug) cout << "After a sequence of Fs, the text has a 'D' or 'E' with is a potential start of a new slump to be evaluated: " << str.substr(i + 1) << endl;
        isSlump(str.substr(i));
    } else {
        if(shouldShowDebug) cout << "The char at position i: '" << str[i] << "' does not configure a slump" << endl;
    }

    return true;
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
        }
    } else {
        if (str[1] == 'B') {
            if(shouldShowDebug) cout << "Slimp is 'BC' type : " << str << endl;
            int lastCIndex = str.find_last_of('C');
            if(shouldShowDebug) cout << "Finding the potential end of the slimp : " << lastCIndex << " is the last occurrence of 'C' " << endl;

            if((str.length() - 1) > lastCIndex) {
                if(shouldShowDebug) cout << "The potential end of the slimp : " << lastCIndex << " is not the end of text of size " << str.length() << endl;
                if(shouldShowDebug) cout << "The sufix will be considered as a potential slump : " << str.substr(lastCIndex + 1) << endl;

                if(!isSlump(str.substr(lastCIndex + 1))) return false;
                result = true;
            }

            string subSlimp = str.substr(2, lastCIndex - 2);
            if(shouldShowDebug) cout << "Evaluating potential subSlimp : " << subSlimp <<  endl;
            if(!isSlimp(subSlimp)) { return false; }

        } else {
            if(str[1] == 'H') {
                if(shouldShowDebug) cout << "The text contains a slimp of type 'AH' : " << str.substr(0,2) <<  endl;
                if(shouldShowDebug) cout << "The sufix will be cosidered as a potential slump : " << str.substr(2) <<  endl;
                if(!isSlump(str.substr(2))) { 
                    return false;
                } else {
                    slimpVerification = true;
                    result = true;
                }
            } else if(str[1] != 'D' && str[1] != 'E') {
                if(shouldShowDebug) cout << "The evaluated text : " << str << " is not a slimp, after an 'A' has no 'B', 'D' or 'E' " << endl;
                return false;
            } else if (str[1] == 'D' || str[1] == 'E'){
                int lastCIndex = str.find_last_of('C');
                if(lastCIndex == -1) {
                    if(shouldShowDebug) cout << "Could not found the end of potential slimp " <<  endl; 
                    return false; 
                }
                slimpVerification = true;
                if(shouldShowDebug) cout << "Finding the potential end of the slimp : " << lastCIndex << " is the last occurrence of 'C' " << endl;
                string subSlump = str.substr(1, lastCIndex - 1);
                if(shouldShowDebug) cout << "Evaluating potential subSlump : " << subSlump <<  endl;
                if(!isSlump(subSlump)) { return false; }
                if((str.length() - 1) > lastCIndex) {
                    if(shouldShowDebug) cout << "The potential end of the slimp : " << lastCIndex << " is not the end of text of size " << str.length() << endl;
                    if(shouldShowDebug) cout << "The sufix will be considered as a potential slump : " << str.substr(lastCIndex + 1) << endl;

                    if(!isSlump(str.substr(lastCIndex + 1))) return false;
                    result = true;
                }
            } else {
                if(shouldShowDebug) cout << "The text : " << str << "does not cointains the necessary rules to be a slimp. " <<  endl;
                return false;
            }
        }
    }

    if(shouldShowDebug) cout << "Slimp - result : " << result << endl;
    return result;

}

int main() {

    shouldShowDebug = false;
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
        if(shouldShowDebug) cout << i + 1 << endl;
        slumpKey = true;
        slimpAnswer = isSlimp(textsToVerify[i]);
        bool answer = slimpAnswer && slimpVerification && slumpEvaluation && slumpKey;
        if(shouldShowDebug) cout << "After process the results are: " << endl;
        if(shouldShowDebug) cout << "isSlimp: "<< slimpAnswer << endl;
        if(shouldShowDebug) cout << "slimpVerification: "<< slimpVerification << endl;
        if(shouldShowDebug) cout << "slumpVerification: "<< slumpEvaluation << endl;
        if(shouldShowDebug) cout << "slumpKey: "<< slumpKey << endl;
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