#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = prices.size();
    
    for(int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (prices[i] > prices[j]){
                answer.push_back(j - i);
                break;
            }
            
            if (j == size - 1)
                answer.push_back(size - i - 1);    
        }
    }
    answer.push_back(0);
    return answer;
}
