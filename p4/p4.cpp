#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::endl;

void computeOutgoing(vector<string> friendsList, vector<pair<string, pair<int, vector<string>>>> outgoingList) {
    for(int i = 0; i < (int)friendsList.size(); i++) {
        
    }
}

int main() {
    while(!cin.eof()) {
        int numOfFriends = 0;
        cin >> numOfFriends;
        vector<string> friendsList;
        vector<pair<string, pair<int, vector<string>>>> outgoingList;
        for(int i = 0; i < numOfFriends; i++) {
            string friendName;
            cin >> friendName;
            friendsList.push_back(friendName);
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
        cout << endl;

        friendsList.clear();
        outgoingList.clear();
    }
    return 0;
}