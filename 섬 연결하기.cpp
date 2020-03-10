#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), comp);
    int size = costs.size();
    bool visit[101] = {false};
    int remain = n;
    int index = 0;
    int a, b, c, d;
    while(remain > 0){
        a = costs[index][0];
        b = costs[index][1];
        
        if(!visit[a]){
            visit[a] = true;
            remain--;
        }
        if(!visit[b]){
            visit[b] = true;
            remain--;
        }
        answer += costs[index][2];
        for(index = 0; index < size; index++){
            c = costs[index][0];
            d = costs[index][1];
            if((!visit[c] && visit[d]) || (visit[c] && !visit[d]))
                break;
        }
    }
    
    return answer;
}
