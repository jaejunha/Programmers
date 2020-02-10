#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    map<string, int>::iterator it;
    int size = clothes.size();
    for (int i = 0; i < size; i++){
        it = m.find(clothes[i][1]);
        if(it == m.end())
            m.insert(pair<string, int>(clothes[i][1], 1));
        else
            it->second++;
    }
    
    int answer = 1;
    for(auto it = m.begin(); it != m.end(); it++)
		answer *= (it->second + 1);
	
    return answer - 1;
}
