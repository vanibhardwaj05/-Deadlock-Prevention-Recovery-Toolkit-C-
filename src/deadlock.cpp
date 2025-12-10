#include <bits/stdc++.h>
using namespace std;

class DeadlockToolkit {
public:
    int n, m;
    vector<int> available;
    vector<vector<int>> maxNeed, allocation;

    vector<vector<int>> calculateNeed() {
        vector<vector<int>> need(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                need[i][j] = maxNeed[i][j] - allocation[i][j];
        return need;
    }

    bool isSafe(vector<int>& seq) {
        auto need = calculateNeed();
        vector<int> work = available;
        vector<bool> finish(n, false);

        for (int k = 0; k < n; k++) {
            bool allocated = false;
            for (int i = 0; i < n; i++) {
                if (!finish[i]) {
                    bool ok = true;
                    for (int j = 0; j < m; j++)
                        if (need[i][j] > work[j]) ok = false;

                    if (ok) {
                        for (int j = 0; j < m; j++)
                            work[j] += allocation[i][j];

                        finish[i] = true;
                        seq.push_back(i);
                        allocated = true;
                    }
                }
            }
            if (!allocated) break;
        }

        for (bool f : finish)
            if (!f) return false;
        return true;
    }

    bool requestResources(int p, vector<int> req) {
        auto need = calculateNeed();

        for (int j = 0; j < m; j++)
            if (req[j] > need[p][j])
                return false;

        for (int j = 0; j < m; j++)
            if (req[j] > available[j])
                return false;

        for (int j = 0; j < m; j++) {
            available[j] -= req[j];
            allocation[p][j] += req[j];
        }

        vector<int> seq;
        if (isSafe(seq)) return true;

        for (int j = 0; j < m; j++) {
            available[j] += req[j];
            allocation[p][j] -= req[j];
        }

        return false;
    }

    bool detectDeadlock() {
        vector<int> visited(n, 0), recStack(n, 0);

        function<bool(int)> dfs = [&](int u) {
            visited[u] = recStack[u] = 1;

            for (int r = 0; r < m; r++) {
                if (allocation[u][r] == 0) continue;

                for (int p = 0; p < n; p++) {
                    if (p != u && allocation[p][r] > 0) {

                        if (!visited[p] && dfs(p)) return true;
                        if (recStack[p]) return true;
                    }
                }
            }

            recStack[u] = 0;
            return false;
        };

        for (int i = 0; i < n; i++)
            if (!visited[i] && dfs(i))
                return true;

        return false;
    }

    void recover() {
        cout << "Deadlock found. Terminating Process P0...\n";
        for (int j = 0; j < m; j++)
            available[j] += allocation[0][j];
    }
};

int main() {
    DeadlockToolkit D;

    cout << "Enter number of processes: ";
    cin >> D.n;
    cout << "Enter number of resources: ";
    cin >> D.m;

    D.maxNeed.assign(D.n, vector<int>(D.m));
    D.allocation.assign(D.n, vector<int>(D.m));
    D.available.assign(D.m, 0);

    cout << "Enter MAX matrix:\n";
    for (int i = 0; i < D.n; i++)
        for (int j = 0; j < D.m; j++)
            cin >> D.maxNeed[i][j];

    cout << "Enter ALLOCATION matrix:\n";
    for (int i = 0; i < D.n; i++)
        for (int j = 0; j < D.m; j++)
            cin >> D.allocation[i][j];

    cout << "Enter AVAILABLE vector:\n";
    for (int j = 0; j < D.m; j++)
        cin >> D.available[j];

    while (true) {
        cout << "\nMENU:\n";
        cout << "1. Check Safe State\n";
        cout << "2. Request Resources\n";
        cout << "3. Detect Deadlock\n";
        cout << "4. Exit\n";

        int ch;
        cin >> ch;

        if (ch == 1) {
            vector<int> seq;
            if (D.isSafe(seq)) {
                cout << "Safe Sequence: ";
                for (auto x : seq) cout << "P" << x << " ";
                cout << endl;
            } else {
                cout << "System is NOT in safe state\n";
            }
        }

        else if (ch == 2) {
            int p;
            cout << "Enter process ID: ";
            cin >> p;

            vector<int> req(D.m);
            cout << "Enter request: ";
            for (int j = 0; j < D.m; j++)
                cin >> req[j];

            if (D.requestResources(p, req))
                cout << "Request Granted\n";
            else
                cout << "Request Denied\n";
        }

        else if (ch == 3) {
            if (D.detectDeadlock()) {
                cout << "Deadlock Detected\n";
                D.recover();
            } else {
                cout << "No Deadlock\n";
            }
        }

        else break;
    }
}
