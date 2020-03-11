/* Reference: https://ga0n.tistory.com/entry/프로그래머스-단속카메라 */
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int size = routes.size();
    sort(routes.begin(), routes.end(), cmp);
    int pos = routes[0][1];
    for(int i = 1; i < size; i++){
        if(routes[i][1] < pos)
            pos = routes[i][1];
        if(routes[i][0] > pos){
            answer++;
            pos = routes[i][1];
        }
    }
    return answer;
}
