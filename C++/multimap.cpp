#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

class BuddyList final {
public:
    void addBuddy(const string& name, const string& buddy);
    void removeBuddy(const string& name, const string& buddy);
    bool isBuddy(const string& name, const string& buddy) const;
    vector<string> getBuddies(const string& name) const;
private:
    multimap<string, string> mBuddies;
};

void BuddyList::addBuddy(const string& name, const string& buddy) {
    if (!isBuddy(name, buddy)) {
        mBuddies.insert({name, buddy});
    }
}

void BuddyList::removeBuddy(const string& name, const string& buddy) {
    auto [begin, end] = mBuddies.equal_range(name);

    for (auto iter = begin; iter != end; ++iter) {
        if (iter->second == buddy) {
            mBuddies.erase(iter);
            break;
        }
    }
}

bool BuddyList::isBuddy(const string& name, const string& buddy) const {
    //mBuddies is multimap
    auto [begin, end] = mBuddies.equal_range(name);

    for (auto iter = begin; iter != end; ++iter) {
        if (iter->second == buddy) {
            return true;
        }
    }

    return false;
}

vector<string> BuddyList::getBuddies(const string& name) const {
    auto [begin, end] = mBuddies.equal_range(name);

    vector<string> buddies;
    for (auto iter = begin; iter != end; iter++) {
        buddies.push_back(iter->second);
    }

    return buddies;
}

int main() {
    BuddyList buddies;
    buddies.addBuddy("harry", "8");
    buddies.addBuddy("harry", "9");
    buddies.addBuddy("harry", "10");
    buddies.addBuddy("harry", "1");
    buddies.addBuddy("harry", "2");
    buddies.addBuddy("harry", "3");
    buddies.addBuddy("harry", "4");
    buddies.addBuddy("harry", "5");
    buddies.addBuddy("harry", "6");
    buddies.addBuddy("harry", "7");

    buddies.removeBuddy("harry", "Draco Malfoy");

    buddies.addBuddy("Hagrid", "harry");
    buddies.addBuddy("Hagrid", "Ron Weasley");
    buddies.addBuddy("Hagrid", "Hermione");

    auto harrysFriends = buddies.getBuddies("harry");
    cout << "Harry's friends: " << "\n";
    for (const auto& name : harrysFriends) {
        cout << "\t" << name << "\n";
    }

    return 0;
}