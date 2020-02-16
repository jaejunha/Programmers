/* Reference from: https://ju-nam2.tistory.com/46 */
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    vector<char> v;
    int length = arrangement.length();
    for(int i = 0; i < length; i++){
        if(arrangement[i] == '(' && arrangement[i + 1] == ')'){
            v.push_back('1');
            i++;
        }
        else
            v.push_back(arrangement[i]);
    }
    length = v.size();
    stack<int> s;
    for(int i = 0; i < length; i++){
        if(v[i] == '1')
            answer += s.size();
        else if(v[i] == '(')
            s.push(1);
        else{
            s.pop();
            answer++;
        }
    }
    return answer;
}
