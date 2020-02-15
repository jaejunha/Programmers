#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int size = priorities.size();
    int check[10] = {0};
    for(int i = 0; i < size; i++)
        check[priorities[i]] = 1;
    
    
    vector<int> v;
    int cur = 0;
    for(int i = 9; i > 0; i--){
        if(check[i] == 0)
            continue;
        for(int j = cur, max = cur + size; j < max; j++){    
            if(priorities[j % size] == i){
                v.push_back(j % size);
                cur = (j + 1) % size;
            }
        }
    }
    
    for(int i = 0; i < size; i++){
        if(v[i] == location)
            return i + 1;
    }
}
