// // Unio find
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, string> mailToRootMail;
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> rootMailToMails;
        for (auto account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                mailToRootMail[account[i]] = account[i];
                owner[account[i]] = account[0];
            }
        }
        for (auto account : accounts) {
            string rootMail = find(account[1], mailToRootMail);
            for (int i = 2; i < account.size(); ++i) {
                mailToRootMail[find(account[i], mailToRootMail)] = rootMail;
            }
        }
        for (auto account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                rootMailToMails[find(account[i], mailToRootMail)].insert(account[i]);
            }
        }
        for (auto a : rootMailToMails) {
            vector<string> v(a.second.begin(), a.second.end());
            v.insert(v.begin(), owner[a.first]);
            res.push_back(v);
        }
        return res;
    }
    string find(string mail, unordered_map<string, string>& mailToRootMail) {
        return mailToRootMail[mail] == mail ? mail : find(mailToRootMail[mail], mailToRootMail);
    }
};

// BFS
/*
    Original :
    account index1 -> mail1, mail2, mail4
    account index2 -> mail1,
    account index3 -> mail2, mail3

    Create :
    mail1 -> account index1, account index2
    mail2 -> account index1, account index3
    mail3 -> account index3
    mail4 -> account index1
    ...

    mail1 -> account index1 -> (mail1, mail2) -> ...
*/
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, vector<int>> mailToAccountIndex;
        vector<int> visited(accounts.size(), 0);
        for (int i=0; i<accounts.size(); ++i) {
            for (int j=1; j<accounts[i].size(); ++j) {
                mailToAccountIndex[accounts[i][j]].push_back(i);
            }
        }

        for (int i=0 ; i<accounts.size() ; ++i ) {
            if (visited[i] != 0) continue;
            queue<int> q;
            q.push(i);
            set<string> collectedMails;
            while(!q.empty()) {
                int curIndex = q.front();
                q.pop();
                visited[curIndex] = 1;
                for(int j=1 ; j<accounts[curIndex].size() ; ++j) {
                    auto& mail = accounts[curIndex][j];
                    collectedMails.insert(mail);
                    for (int user : mailToAccountIndex[mail]) {
                        if (visited[user] != 0) continue;
                        q.push(user);
                    }
                }
            }
            vector<string> out(collectedMails.begin(), collectedMails.end());
            out.insert(out.begin(), accounts[i][0]);
            res.push_back(out);
        }
        return res;
    }
};
