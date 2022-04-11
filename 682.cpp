// 682. Baseball Game
// You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

// At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

// An integer x - Record a new score of x.
// "+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
// "D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
// "C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
// Return the sum of all the scores on the record.

 

// Example 1:

// Input: ops = ["5","2","C","D","+"]
// Output: 30
// Explanation:
// "5" - Add 5 to the record, record is now [5].
// "2" - Add 2 to the record, record is now [5, 2].
// "C" - Invalidate and remove the previous score, record is now [5].
// "D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
// "+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
// The total sum is 5 + 10 + 15 = 30.
// Example 2:

// Input: ops = ["5","-2","4","C","D","9","+","+"]
// Output: 27
// Explanation:
// "5" - Add 5 to the record, record is now [5].
// "-2" - Add -2 to the record, record is now [5, -2].
// "4" - Add 4 to the record, record is now [5, -2, 4].
// "C" - Invalidate and remove the previous score, record is now [5, -2].
// "D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
// "9" - Add 9 to the record, record is now [5, -2, -4, 9].
// "+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
// "+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
// The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
// Example 3:

// Input: ops = ["1"]
// Output: 1
 

// Constraints:

// 1 <= ops.length <= 1000
// ops[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
// For operation "+", there will always be at least two previous scores on the record.
// For operations "C" and "D", there will always be at least one previous score on the record.

#include<bits/stdc++.h>
    using namespace std;
int calPoints(vector<string> &ops){
    stack<int> st;
    int n = ops.size();
    for (int i = 0; i < n;i++){
        if(ops[i]=="+"){
            int var1, var2;
            var1 = st.top();
            st.pop();
            var2 = st.top();
            st.pop();
            st.push(var2);
            st.push(var1);
            st.push(var1 + var2);
        }
        else if(ops[i]=="D"){
            int var = st.top();
            st.push(var * 2);
        }
        else if(ops[i]=="C"){
            st.pop();
        }
        else{
            int var = stoi(ops[i]);
            st.push(var);
        }
    }
    int res = 0;
    while(st.empty()==false){
        res += st.top();
        st.pop();
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    vector<string> ops;
    for (int i = 0; i < n;i++){
        string temp;
        cin >> temp;
        ops.push_back(temp);
    }
    cout << calPoints(ops) << endl;
    return 0;
}