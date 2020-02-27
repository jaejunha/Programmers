#include <string>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    
    int max = 0;
    long long sum = 0;
    int size = budgets.size();
    for (int i = 0; i < size; i++){
        sum += budgets[i];
        if(budgets[i] > max)
            max = budgets[i];
    }
    if (sum <= M)
        return max;
    
    int min = 0;
    max = 100001;
    
    while (min < max){
        answer = (min + max) / 2;
        sum = 0;
        for(int i = 0; i < size; i++){
            if(budgets[i] > answer)
                sum += answer;
            else
                sum += budgets[i];
        }
        
        if(sum == M)
            return answer;
        else if (sum < M){
           if (min == answer)
               break;
           min = answer;
        }
        else
            max = answer;
    }
    return answer;
}
