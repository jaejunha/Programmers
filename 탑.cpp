#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> temp;
    int size = heights.size();
    for(int i = size - 1; i >= 0; i--){
        for(int j = i - 1; j >= 0; j--){
            if(heights[i] < heights[j]){
                temp.push_back(j + 1);
                break;
            }
            if(j == 0)
                temp.push_back(0);
        }
    }
    temp.push_back(0);
    vector<int> answer;
    for(int i = size - 1; i >= 0; i--)
        answer.push_back(temp[i]);
    return answer;
}
