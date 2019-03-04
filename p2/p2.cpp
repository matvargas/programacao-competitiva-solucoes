#include <iostream>
#include <string>
using namespace std;
using std::endl;

int isSlimp(string str) {

    cout << "Entrou no isSlimp: " << str << endl;

    bool result = false;

    if(str[0] != 'A') {
        cout << "primeira letra não é A: " << str[0] << endl;
        result =  false;
        return 0;  
    }

    if(str.length() == 2 && str[1] != 'H') {
        cout << "Tamanho igual a 2 e segunda letra não é H: " << str[1] << endl;
        result =  false;
        return 0;
    } else if (str.length() == 2 && str[1] == 'H') {
        result =  true;
        return 1;
    }

    if(str[1] == 'B') {
        int subSlimpEndIndex = (str.find('C') - 2);
        if(subSlimpEndIndex == -1) { result =  false; return 0; } 
        if(!isSlimp(str.substr(2,subSlimpEndIndex))) {result =  false; return 0; }
        result = true;
        return 1;
    }

    return result;

}

int isSlump() {
    return 0;
}

int main() {
    string str = "";
    getline(cin, str);
    cout << isSlimp(str) << endl;
    return 0;
}