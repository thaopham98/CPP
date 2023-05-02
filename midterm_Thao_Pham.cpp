//
//  main.cpp
//  midterm
//
//  Created by Thao Pham on 3/2/22.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> scores_1 { 70, 80, 90, 100 };
    vector<int> scores_2 { 65, 75, 85, 95 };

    int score = scores_1.back();
    scores_2.push_back(score); // 65, 75, 85, 95, 70, 80, 90, 100
    scores_2.front() = 60; // 60, 65, 75, 85, 95, 70, 80, 90, 100
    scores_2.assign(scores_1.begin(), scores_1.begin() + 3); // starting at 70 , end at 100. => vector<int> scores_2 {70, 80, 90}
    scores_2.resize(4); // 70, 80, 90, 0
    scores_2.push_back(scores_1.back()); // 70, 80, 90, 0, 100
    
    cout << "Scores_2: ";
    for (int j = 0; j<scores_2.size(); j++)
        cout << scores_2 [j]<< " ";
    cout << endl;
    
    return 0;
}
