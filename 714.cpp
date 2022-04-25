// 714. Best Time to Buy and Sell Stock with Transaction Fee
// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// Example 2:

// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6
 

// Constraints:

// 1 <= prices.length <= 5 * 104
// 1 <= prices[i] < 5 * 104
// 0 <= fee < 5 * 104
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices, int fee){
    /* time complexity == O(n) && space complexity == O(n)*/




    // int n = prices.size();
    // vector<int> buy(n, 0);
    // buy[0] = -prices[0];
    // vector<int> sell(n, 0);
    // for (int i = 1; i < n;i++){
    //     buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
    //     sell[i] = max(sell[i - 1], prices[i] + buy[i - 1] - fee);
    // }
    // return sell[n - 1];



    /*Time complexity == O(n ) && space complexity == O(1)*/

    // profit when intially we buy a stock == - price of first stock as we have zero rupees
    int obsp = -prices[0];
    // profit when we sell a stock == 0 as we have zero stock intially in our hand

    int ossp = 0;
    int n = prices.size();
    for (int i = 1; i < n;i++){
        // new buy state profit means profit if we buy stock at this point of time
        int nbsp;
        // new sell state profit  means profit if we sell stock at this point of time
        int nssp;
        // we are checking if we could get more profit if we but stock at current time
        // current buy profit == old sell profit or money left with us - current price of stock as compared to previous buy profit
        if(ossp-prices[i]>obsp){
            nbsp = ossp - prices[i];
        }
        // if current buy profit is less than previous buy profit then we are not buying stock we are proceding with previous stock which we have
        else{
            nbsp = obsp;
        }
        // current sell profit == old buy profit + profit that we get from selling stock - transaction fee 
        if(obsp+prices[i]-fee>ossp){
            // if current sell profit is greater than previous sell profit then we sell stock at this time otherwise we ignore selling right now
            nssp = obsp + prices[i] - fee;
        }
        else{
            nssp = ossp;
        }
        ossp = nssp;
        obsp = nbsp;
    }
    return ossp;
}
int main(){
    int n,fee;
    cin>>n >>fee;
    vector<int> prices(n);
    for (int i = 0; i < n;i++){
        cin >> prices[i];
    }
    cout << maxProfit(prices, fee) << endl;
    return 0;
}