#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int size = truck_weights.size();
    stack<int> stack_wait;
    vector<pair<int, int>> vector_ing;
    
    int int_current = 0;
    int int_start = 0;
    
    for (int i = 0, size = truck_weights.size(); i < size; i++)
        stack_wait.push(truck_weights[i]);
    
    while(1){
        answer++;
    
        if(stack_wait.size() > 0 && int_current + stack_wait.top() <= weight){
            vector_ing.push_back({stack_wait.top(), bridge_length - 1});
            int_current += stack_wait.top();
            stack_wait.pop();
            
            for(int i = int_start, size = vector_ing.size() - 1; i < size; i++){
                vector_ing[i].second --;
                if (vector_ing[i].second == 0){
                    int_current -= vector_ing[i].first;
                    int_start++;
                }
            }
        }else{
            for(int i = int_start, size = vector_ing.size(); i < size; i++){
                vector_ing[i].second --;
                if (vector_ing[i].second == 0){
                    int_current -= vector_ing[i].first;
                    int_start++;
                }
            }
        }
        
        if(int_start == truck_weights.size())
            break;
    }
    return answer + 1;
}
