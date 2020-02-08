#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    map <string, int> m;
    map<string, int>::iterator iter;

    int size = completion.size();
    for (int i = 0; i < size; i++){
        iter = m.find(completion[i]);
        if(iter == m.end())
            m.insert(pair<string, int>(completion[i], 1));
        else
            iter->second += 1;
    }  
    size = participant.size();
    
    for (int i = 0; i < size; i++){
        iter = m.find(participant[i]);
        if(iter == m.end()){
            answer = participant[i];
            break;
        }else{
            iter->second--;
            if(iter->second == 0)
                m.erase(iter);
        }
    }
    return answer;
}
