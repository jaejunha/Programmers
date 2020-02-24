#include <string>
#include <vector>

using namespace std;

int visit[200];
vector<vector<int>> global_computers;

void dfs(int n, int i){
    visit[i] = 1;
    
    for(int j = 0; j < n; j++){
         if(global_computers[i][j] == 1 && visit[j] == 0)
            dfs(n, j);
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        vector<int> v;
        for (int j = 0; j < n; j++)
            v.push_back(computers[i][j]);
        global_computers.push_back(v);
    }
    
    for(int i = 0; i < n; i++){
        if(visit[i] == 0){
            dfs(n, i);
            answer++;
        }
    }
    
    return answer;
}