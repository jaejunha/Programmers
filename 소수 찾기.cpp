#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool cmp(char a, char b){
    return a > b;
}

int solution(string numbers) {
    int answer = 0;    
    char n[10];
    
    sort(numbers.begin(), numbers.end(), cmp);
    strcpy(n, numbers.c_str());
    
    int size = atoi(n);
    vector<bool> v(size + 1, true);
    int check[10] = {0};
    size = numbers.size();
    for(int i = 0; i < size; i++)
        check[n[i] - '0']++;
    
    size = atoi(n);
    int max_number = sqrt(size);
    for (int i = 2; i <=  max_number; i++) { 
        if (v[i] == false)
            continue;
        for (int j = i + i; j <= size; j += i)
            v[j] = false;
    }
    
    int number;
    
    for(int i = 2; i <= size; i++){
        int check_confirm[10] = {0};
        for(int j = 0; j < 10; j++)
            check_confirm[j] = check[j];
            
        number = i;
        while(1){
            check_confirm[(number % 10)]--;
            if (number < 10)
                break;
            number /= 10;
        }
        
        for(int j = 0; j < 10; j++){
            if(check_confirm[j] < 0){
                v[i] = false;
                break;   
            }
        }
    }
    
    for(int i = 2; i <= size; i++)
        if (v[i])
            answer++;
    
    return answer;
}
