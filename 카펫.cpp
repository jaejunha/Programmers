#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int sum = brown + red;
    int a, b;
    for(int i = 1; i < sum; i++){
        if(sum % i == 0){
            a = sum / i;
            b = i;
            if (b > a)
                break;
            if(2 * (a + b - 2) == brown){
                answer.push_back(a);
                answer.push_back(b);
                return answer;
            }
        }
    }
}
