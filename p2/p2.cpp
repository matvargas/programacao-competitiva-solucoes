#include <iostream>
#include <string>
using namespace std;
using std::endl;

int isSlump(string str) {

    cout << "testando slump " << str << endl;
    bool result = true;

    if(str[0] != 'D' && str[0] != 'E') { return false; }
    if(str[1] != 'F' || str[str.size() - 1] == 'F') { return false; }
    int lastIndexOfF = -1;
    int numberOfFs = 0;
    for(std::string::size_type i = str.find('F'); i < str.size(); ++i) {
        if(str[i] != 'F') {
            lastIndexOfF = i;
            cout << "Ultima posicao do F " << lastIndexOfF << endl;
            break;
        } else {
            numberOfFs ++;
        }
    }
    if(str[lastIndexOfF] != 'G') {
        cout << "Char na posicao " << lastIndexOfF << " é " << str[lastIndexOfF] << endl;
        if(!isSlump(str.substr(lastIndexOfF))) { return 0; }
    } else {
        cout << "Char na posicao " << lastIndexOfF << " é " << str[lastIndexOfF] << endl;
        result = true;
        return true;
    }

    return result;
}

int isSlimp(string str) {

    cout << "Entrou no isSlimp: " << str << endl;

    bool result = false;

    if(str[0] != 'A') {
        cout << "primeira letra não é A: " << str[0] << endl;
        result =  false;
        return 0;  
    }

    if (str[1] == 'H') {
        cout << "Slimp identificado " << str.substr(0, 2) << endl;
        cout << "Testando se o restante e slumpy " << str.substr(2) << endl;
        if(!isSlump(str.substr(2))) {result =  false; return 0; }
        result = true;
        return 1;
    }

    if(str[1] == 'B') {
        int subSlimpEndIndex = (str.find('C') - 2);
        if(subSlimpEndIndex == -1) { result =  false; return 0; } 
        if(!isSlimp(str.substr(2,subSlimpEndIndex))) {result =  false; return 0; }
        result = true;
        return 1;
    } else {
        int subSlimpEndIndex = (str.find('C') - 2);
        if(subSlimpEndIndex == -1) { result =  false; return 0; } 
        if(!isSlump(str.substr(2,subSlimpEndIndex))) {result =  false; return 0; }
        result = true;
        return 1;
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
        if(isSlimp(textsToVerify[i])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        cout << "______" << endl;
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}