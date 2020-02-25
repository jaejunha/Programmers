#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> global_answer;
int global_size;
bool global_visit[10001];

bool cmp(pair<string, int> a, pair<string, int> b){
    for(int i = 0; i < 3; i++){
        if(a.first[i] > b.first[i])
            return false;
        else if(a.first[i] < b.first[i])
            return true;
    }
    return true;
}

bool dfs(int level, string start, vector<vector<string>> tickets){
    
    global_answer.push_back(start);
    
    vector<pair<string, int>> possible;
    for(int i = 0; i < global_size; i++){
        if(global_visit[i])
            continue;
        if(tickets[i][0].compare(start) == 0){
            possible.push_back({tickets[i][1], i});
        }
    }
    
    
    int size = possible.size();
    if(size == 0){
        if(global_answer.size() != global_size + 1)
            return false;
        else
            return true;
    }
    sort(possible.begin(), possible.end(), cmp);
    for(int i = 0; i < size; i++){
        global_visit[possible[i].second] = true;
        if(dfs(level + 1, possible[i].first, tickets))
            return true;
        global_visit[possible[i].second] = false;
        global_answer.erase(global_answer.begin() + level + 1);
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    string start = "ICN";
    global_answer.push_back(start);
    global_size = tickets.size();
    
    vector<pair<string, int>> possible;
    for(int i = 0; i < global_size; i++){
        if(tickets[i][0].compare(start) == 0)
            possible.push_back({tickets[i][1], i});
    }
    
    int size = possible.size();
    sort(possible.begin(), possible.end(), cmp);
    for(int i = 0; i < size; i++){
        global_visit[possible[i].second] = true;
        if(dfs(1, possible[i].first, tickets))
            break;
        global_visit[possible[i].second] = false;
        global_answer.erase(global_answer.begin() + 1);
    }
    return global_answer;
}
