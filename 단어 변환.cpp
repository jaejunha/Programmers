#include <string>
#include <vector>

using namespace std;

int global_size, global_length;
string global_target;
vector<string> global_words;
int global_answer = 1000;

void dfs(int level, string word, int visit[50]){
    if(word == global_target){
        if (global_answer > level)
            global_answer = level;
        else
            return;
    }
    
    for(int i = 0; i < global_size; i++){
        if(visit[i] == 1)
            continue;
        int length = 0;
        for(int j = 0; j < global_length; j++){
            if(global_words[i][j] == word[j])
                length++;
        }
        if(length == global_length - 1){
            visit[i] = 1;
            dfs(level + 1, global_words[i], visit);
            visit[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    global_size = words.size();
    global_length = words[0].length();
    global_target = target;
    
    for(int i = 0; i < global_size; i++)
        global_words.push_back(words[i]);
    
    int visit[50] = {0};
    for(int i = 0; i < global_size; i++){
        int length = 0;
        for(int j = 0; j < global_length; j++){
            if(words[i][j] == begin[j])
                length++;
        }
        if(length == global_length - 1){
            visit[i] = 1;
            dfs(1, words[i], visit);
            visit[i] = 0;
        }
    }
    if (global_answer == 1000)
        global_answer = 0;
    return global_answer;
}
