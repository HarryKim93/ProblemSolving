#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class User;
using UserPtr = shared_ptr<User>;

class Party {
public:
    Party() {
        cout << "Party constructor\n";
    }
    ~Party() {
        m_MemberList.clear();
        cout << "Party destructor\n";
    }

    void AddMember(const UserPtr& member) {
        m_MemberList.push_back(member);
    }

private:
    using MemberList = vector<UserPtr>;
    MemberList m_MemberList;
};

// using PartyPtr = shared_ptr<Party>;
using PartyPtr = weak_ptr<Party>;

class User {
public:
    User() {
        cout << "User constructor\n";
    }

    ~User() {
        cout << "User destructor\n";
    }

    void SetParty(const PartyPtr& party) {
        m_Party = party;
    }

private:
    PartyPtr m_Party;
};

int main() {
    auto party = make_shared<Party>();
    // PartyPtr party(new Party);

    for (int i = 0; i < 5; i++) {
        UserPtr user(new User);
        party->AddMember(user);
        user->SetParty(party);
    }

    cout << party.use_count() << "\n";
    party.reset();
    cout << party.use_count() << "\n";

    return 0;
}