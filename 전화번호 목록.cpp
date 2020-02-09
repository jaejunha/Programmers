#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    int size = phone_book.size();
    
    for(int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if(phone_book[j].find(phone_book[i]) < 20)
                return false;
        }
    }
    return true;
}
