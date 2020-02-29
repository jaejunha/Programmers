#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    
    sort(times.begin(), times.end());
    
    int size = times.size();
    long long min = 1;
    long long max = 1000000000 * (long long)n;
    long long mid;
    
    long long answer = max;
    
    long long sum;
    while (min <= max){
        mid = (min + max) / 2;
        
        sum = 0;
        for(int i = 0; i < size; i++)
            sum += mid / times[i];
        
        if (sum < n){
            min = mid + 1;
        }else{
            max = mid - 1;
            if(answer > mid)
                answer = mid;
        }
        
    }
    return answer;
}