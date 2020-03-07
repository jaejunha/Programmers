#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    int size_lost = lost.size();
    int size_reserve = reserve.size();
    vector<int> duplicate;
    
    /* 여벌도 있고 잃어버린 것도 있는 학생 탐색 */
    for(int i = 0; i < size_lost; i++){
        for (int j = 0; j < size_reserve; j++){
            if(reserve[j] == lost[i]){
                answer++;
                duplicate.push_back(lost[i]);
                break;
            }
        }
    }
    
    int size_duplicate = duplicate.size();
    vector<int> new_reserve, new_lost;
    
    if (size_duplicate > 0){
        for(int i = 0; i < size_lost; i++){
            for(int j = 0; j < size_duplicate; j++){
                if(lost[i] == duplicate[j])
                    break;
                if(j == size_duplicate - 1)
                    new_lost.push_back(lost[i]);
            }
        }

        for(int i = 0; i < size_reserve; i++){
            for(int j = 0; j < size_duplicate; j++){
                if(reserve[i] == duplicate[j])
                    break;
                if(j == size_duplicate - 1)
                    new_reserve.push_back(reserve[i]);
            }
        }
    }else{
        new_lost = lost;
        new_reserve = reserve;
    }
    size_lost = new_lost.size();
    size_reserve = new_reserve.size();
    
    bool b[31] = {false};
    
    for(int i = 0; i < size_lost; i++){
        for (int j = 0; j < size_reserve; j++){
            if(b[j])
                continue;
            if(abs(new_reserve[j] - new_lost[i]) <= 1){
                b[j] = true;
                answer ++;
                break;
            }
        }
    }
    return answer;
}
