#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::endl;

void computeOutgoing(vector<pair<string, int>> friendsList, vector<pair<string, pair<int, vector<string>>>> outgoingList) {
    
    int giftValue = 0;
    int rest = 0;

    for(int i = 0; i < (int)friendsList.size(); i++) {
        for(int j = 0; j < (int)outgoingList.size(); j++) {
            if(outgoingList[j].first == friendsList[i].first){
                friendsList[i].second -= outgoingList[j].second.first; 
                cout << friendsList[i].second << " from " << friendsList[i].first << endl;

                if((outgoingList[j].second.first) != 0 && (int)outgoingList[j].second.second.size() != 0) {
                    giftValue = (outgoingList[j].second.first)/(int)outgoingList[j].second.second.size();
                    rest = (outgoingList[j].second.first)%(int)outgoingList[j].second.second.size();
                } else {
                    giftValue = 0;
                    rest = 0;
                } 
                cout << "Gift for each one: " << giftValue << " what left: " << rest << endl;
                friendsList[i].second += rest;

                for(int k = 0; k < (int)outgoingList[j].second.second.size(); k++){
                    for(int l = 0; l < (int)friendsList.size(); l++) {
                        if(outgoingList[j].second.second[k] == friendsList[l].first) {
                            cout << "Gift for " << outgoingList[j].second.second[k] << ": " << giftValue << endl;
                            friendsList[l].second += giftValue;
                        }
                    } 
                }
            } 
        }

        // cout << friendsList[i].first << " " << friendsList[i].second << endl;
    }

    for (int i = 0; i < (int)friendsList.size(); i++ ){
        cout << friendsList[i].first << " " << friendsList[i].second << endl;
    }

}

int main() {
    while(!cin.eof()) {
        int numOfFriends = 0;
        cin >> numOfFriends;
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

        computeOutgoing(friendsList, outgoingList);
        if(!cin.eof()) cout << endl;


        friendsList.clear();
        outgoingList.clear();
    }
    return 0;
}