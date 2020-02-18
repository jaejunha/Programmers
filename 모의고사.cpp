#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int pattern_1[] = {1, 2, 3, 4, 5};
    int pattern_2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int pattern_3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int size = answers.size();
    int sol[3] = { 0 };
    for (int i = 0; i < size; i++){
        if (pattern_1[i % 5] == answers[i])
            sol[0] ++;
        if (pattern_2[i % 8] == answers[i])
            sol[1] ++;
        if (pattern_3[i % 10] == answers[i])
            sol[2] ++;
    }
    
    int max_sol = 0;
    for (int i = 0; i < 3; i++){
        if (max_sol < sol[i])
            max_sol = sol[i];
    }
    
    vector<int> answer;
    
    for (int i = 0; i < 3; i++){
        if (sol[i] == max_sol)
            answer.push_back(i + 1);
    }
    
    return answer;
}
