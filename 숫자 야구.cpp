#include <string>
#include <vector>

#define WRONG 1
#define CHECKED 1

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int check[1000] = {!WRONG};
    int x[3];
    
    // filter the numbers
    for (int i = 123; i < 1000; i++){
        if ((i % 10 == 0) || ((int(i/10) % 10) == 0)){
            check[i] = WRONG;
            continue;
        }
        x[0] = i / 100;
        x[1] = (i % 100) / 10;
        x[2] = i % 10;
        
        if(x[0] == x[1] || x[0] == x[2] || x[1] == x[2])
            check[i] = WRONG;
    }
    
    int ball, strike, y[3], check_x[3], check_y[3];
    vector<int> v;
    int size = baseball.size();
    for (int i = 0; i < size; i++){
        
            v = baseball[i];
            y[0] = v[0] / 100;
            y[1] = (v[0] % 100) / 10;
            y[2] = v[0] % 10;
            
        for (int j = 123; j < 1000; j++){
            if (check[j] != WRONG){
                ball = 0;
                strike = 0;
                x[0] = j / 100;
                x[1] = (j % 100 / 10);
                x[2] = j % 10;
                
                
                check_x[0] = check_x[1] = check_x[2] = !CHECKED;
                check_y[0] = check_y[1] = check_y[2] = !CHECKED;
                
                for(int k = 0; k < 3; k++){
                    if(x[k] == y[k]){
                        strike++;
                        check_x[k] = check_y[k] = CHECKED;
                    }
                }
             
                for(int k = 0; k < 3; k++) {
                    if(check_y[k] == CHECKED)
                        continue;
                    
                    for(int l = 0; l < 3; l++){
                        if(check_x[l] == CHECKED)
                            continue;
                    
                        if (y[k] == x[l]){
                            ball++;
                            check_x[l] = CHECKED;
                            break;
                        }
                    }
                }
                if (strike != v[1] || ball != v[2])
                    check[j] = WRONG;
            }
        }
    }
    
    for (int i = 123; i < 1000; i++){
        if (check[i] != WRONG)
            answer++;
    }
    return answer;
}
