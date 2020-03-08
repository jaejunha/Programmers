#include <string>
#include <vector>
#include <cmath>

using namespace std;

int global_opt;
int global_size;

void dfs(int remain, bool v[21], int value, int current){
    if (value >= global_opt)
        return ;
    
    if(remain == 0){
        if(global_opt > value)
            global_opt = value;
    }else{
        int delta;
        for(int i = 0; i < global_size; i++){
            if(v[i])
                continue;
            v[i] = true;
            remain --;
            if (current > i)
                delta = current - i;
            else
                delta = i - current;
            dfs(remain, v, value + min(delta, global_size - delta), i);
            v[i] = false;
            remain ++;
        }
    }
}

int solution(string name){
    
    global_size = name.size();
    int remain = global_size;
    int answer = 0;
    int delta;
    bool v[21] = {false};
    for(int i = 0; i < global_size; i++){
        if (name[i] != 'A'){
            delta = name[i] - 'A';
            answer += min(delta, 26 - delta);
        }else{
            v[i] = true;
            remain--;
        }
    }
    
    global_opt = global_size;
    
    int value = 0;
    for(int i = 0; i < global_size; i++){
        if(v[i])
            continue;
        v[i] = true;
        remain --;
        dfs(remain, v, min(i, global_size - i), i);
        v[i] = false;
        remain ++;
    }
    
    return answer + global_opt;
}
