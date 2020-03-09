#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a < b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int size = people.size();
    sort(people.begin(), people.end(), cmp);
    int l = 0, r = size - 1;
    while(l <= r){
        if(l == r){
            answer ++;
            break;
        }
        if (people[l] + people[r] > limit){
            answer ++;
            r--;
        }else{
            answer ++;
            r--;
            l++;
        }
    }
    return answer;
}
