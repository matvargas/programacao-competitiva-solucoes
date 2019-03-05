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

int main() {
    string str = "";
    getline(cin, str);
    cout << isSlump(str) << endl;
    return 0;
}