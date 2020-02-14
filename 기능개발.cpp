#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    int size = speeds.size();
    int temp;
    for(int i = 0; i < size; i++){
        temp = 100 - progresses[i];
        if (temp % speeds[i] == 0)
            day.push_back(temp/speeds[i]);
        else
            day.push_back((int)(temp/speeds[i]) + 1);
        
    }
    int cur = 0;
    int count;
    for(int i = 1; i <= 100; i++){
        if (cur == size)
            break;
        if(day[cur] <= i){
            count = 1;
            cur++;
            while((cur < size) && (day[cur] <= i)){
                cur++;
                count++;
            }
            answer.push_back(count);
        }
    }
    
    return answer;
}
