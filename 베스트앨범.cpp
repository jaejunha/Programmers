#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> copy_plays;

bool M(const pair<string, int> &a, const pair<string, int> &b){ 
    return (a.second > b.second); 
}

bool V(const int &a, const int &b){ 
    return (copy_plays[a] > copy_plays[b]); 
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    copy_plays = plays;
    
    map<string, int> m;
    map<string, vector<int>> n;

    vector<int> answer;
    
    int size = genres.size();
    map<string, int>::iterator it;
    for (int i = 0; i < size; i++){
        it = m.find(genres[i]);
        if(it == m.end()){
            m.insert({genres[i], plays[i]});
            n.insert({genres[i], vector<int>{i}});
        }
        else{
            it->second += plays[i];
            n.find(genres[i])->second.push_back(i);
        }
    }
    
	vector<pair<string, int>> v_m;
    for (auto i = m.begin(); i != m.end(); i++)
        v_m.push_back({i->first, i->second});

    sort(v_m.begin(), v_m.end(), M); 
    
    vector<int> v_i;
    for(auto i = v_m.begin(); i != v_m.end(); i++){
        v_i = n.find(i->first)->second;
        sort(v_i.begin(), v_i.end(), V);
        size = v_i.size();
        if (size > 2)
            size = 2;
        for(int i = 0; i < size; i++){
            answer.push_back(v_i[i]);
        }
    }
    return answer;
}
