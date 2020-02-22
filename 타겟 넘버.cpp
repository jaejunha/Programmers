#include <string>
#include <vector>

using namespace std;

int size, global_target;
vector<int> global_numbers;
int answer = 0;

void dfs(int i, int sum){
    if (i == size - 1){
        if (sum == global_target)
            answer++;
    }else{
        dfs(i + 1, sum + global_numbers[i + 1]);
        dfs(i + 1, sum - global_numbers[i + 1]);
    }
    
    
}

int solution(vector<int> numbers, int target) {
    
    global_target = target;
    size = numbers.size();
    for(int i = 0; i < size; i++)
        global_numbers.push_back(numbers[i]);
    
    dfs(0, global_numbers[0]);
    dfs(0, -global_numbers[0]);
    
    return answer;
}
