#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::endl;

vector<pair<string, int>> computeOutgoing(vector<pair<string, int>> friendsList, vector<pair<string, pair<int, vector<string>>>> outgoingList) {
    
    int giftValue = 0;
    int rest = 0;

    for(int i = 0; i < (int)friendsList.size(); i++) {
        for(int j = 0; j < (int)outgoingList.size(); j++) {
            if(outgoingList[j].first == friendsList[i].first){
                if((int)outgoingList[j].second.second.size() != 0) friendsList[i].second -= outgoingList[j].second.first; 

                if((outgoingList[j].second.first) != 0 && (int)outgoingList[j].second.second.size() != 0) {
                    giftValue = (outgoingList[j].second.first)/(int)outgoingList[j].second.second.size();
                    rest = (outgoingList[j].second.first)%(int)outgoingList[j].second.second.size();
                } else {
                    giftValue = 0;
                    rest = 0;
                } 
                friendsList[i].second += rest;

                for(int k = 0; k < (int)outgoingList[j].second.second.size(); k++){
                    for(int l = 0; l < (int)friendsList.size(); l++) {
                        if(outgoingList[j].second.second[k] == friendsList[l].first) {
                            friendsList[l].second += giftValue;
                        }
                    } 
                }
            } 
        }
    }

    return friendsList;

}

int main() {

    bool isFirstTime = true;

    while(!cin.eof()) {
        
        int numOfFriends = 0;
        cin >> numOfFriends;
        if(numOfFriends <= 0) break;

        if(isFirstTime == true) {
            isFirstTime = false;
        } else {
            cout << endl;
        }
        
        vector<pair<string, int>> friendsList;
        vector<pair<string, pair<int, vector<string>>>> outgoingList;
        for(int i = 0; i < numOfFriends; i++) {
            string friendName;
            cin >> friendName;
            pair <string, int> friendInfo;
            friendInfo.first = friendName;
            friendInfo.second = 0;
            friendsList.push_back(friendInfo);
        }
        for(int i = 0; i < numOfFriends; i++) {
            string name;
            int moneySpent = 0;
            int numOfFriendsGifts = 0;
            cin >> name;
            cin >> moneySpent;
            cin >> numOfFriendsGifts;
            vector <string> personalFriends;
            
            for(int j = 0; j < numOfFriendsGifts; j++) {
                string frd;
                cin >> frd;
                personalFriends.push_back(frd);
            }

            pair<int, vector<string>> outgoing;
            outgoing.first = moneySpent;
            outgoing.second = personalFriends;
            pair<string, pair<int, vector<string>>> personalOutgoing;
            personalOutgoing.first = name;
            personalOutgoing.second = outgoing;
            outgoingList.push_back(personalOutgoing);
        }

        vector<pair<string, int>> result = computeOutgoing(friendsList, outgoingList);
        for(int i = 0; i < (int)result.size(); i++){
            cout << result[i].first << " " << result[i].second << endl;
        }

        friendsList.clear();
        outgoingList.clear();
    }
    return 0;
}