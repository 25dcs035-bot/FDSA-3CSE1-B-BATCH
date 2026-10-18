#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
vector<int> adj[100]; 

void dfs(int start, int n) {
    bool visited[100] = {false};
    stack<int> st;

    st.push(start);

    cout << "DFS Order: ";
    while (!st.empty()) {
        int curr = st.top();
        st.pop();

        if (!visited[curr]) {
            visited[curr] = true;
            cout << curr << " ";
            for (int i = 0; i < adj[curr].size(); i++) {
                int next = adj[curr][i];
                if (!visited[next]) {
                    st.push(next);
                }
            }
        }
    }
    cout << endl;
}
void bfs(int start, int n) {
    bool visited[100] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Order: ";
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << curr << " ";
        for (int i = 0; i < adj[curr].size(); i++) {
            int next = adj[curr][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    cout << endl;
}

int main() {
    int total = 5;
    adj[0].push_back(1); adj[1].push_back(0);
    adj[0].push_back(2); adj[2].push_back(0);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[1].push_back(4); adj[4].push_back(1);

    dfs(0, total);
    bfs(0, total);

    return 0;
}