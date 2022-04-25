// 123. Best Time to Buy and Sell Stock III
//     You are given an array prices where prices[i] is the price of a given stock on the ith day.

//     Find the maximum profit you can achieve.You may complete at most two transactions.

//     Note : You may not engage in multiple transactions
//            simultaneously(i.e., you must sell the stock before you buy again)
//                .

//            Example 1 :

//     Input : prices = [ 3, 3, 5, 0, 0, 3, 1, 4 ] Output : 6 Explanation : Buy on day 4(price = 0) and sell on day 6(price = 3),
//             profit = 3 - 0 = 3. Then buy on day 7(price = 1) and sell on day 8(price = 4), profit = 4 - 1 = 3. Example 2 :

//     Input : prices = [ 1, 2, 3, 4, 5 ] Output : 4 Explanation : Buy on day 1(price = 1) and sell on day 5(price = 5),
//             profit = 5 - 1 = 4. Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time.You must sell before buying again.Example 3 :

//     Input : prices = [ 7, 6, 4, 3, 1 ] Output : 0 Explanation : In this case,
//             no transaction is done, i.e.max profit = 0.
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices){
    int n = prices.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    int left_min = prices[0];
    for (int i = 1; i < n;i++){
        left_min = min(left_min, prices[i]);
        left[i] = max(left[i - 1], prices[i] - left_min);
    }
    int right_max = prices[n - 1];
    for (int i = n - 2; i >= 0;i--){
        right_max = max(right_max, prices[i]);
        right[i] = max(right[i + 1], right_max - prices[i]);
    }
    // cout << "LEFT : ";
    // for(int x:left){
    //     cout << x << " ";
    // }
    // cout << endl;
    // cout << "RIGHT : ";
    // for(int x:right){
    //     cout << x << " ";
    // }
    int max_profit = 0;
    for (int i = 0; i < n;i++){
        max_profit = max(max_profit, left[i] + right[i]);
    }
    return max_profit;
}
int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n;i++){
        cin >> prices[i];
    }
    cout << maxProfit(prices) << endl;
    return 0;
}