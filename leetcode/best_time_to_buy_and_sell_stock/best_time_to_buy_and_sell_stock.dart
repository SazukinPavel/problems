import 'dart:math';

class Solution {
  int maxProfit(List<int> prices) {
    int maxProfit = 0;
    int currentMin = prices[0];

    for (var i = 1; i < prices.length; i++) {
      var price = prices[i];

      maxProfit = max(maxProfit, price - currentMin);
      currentMin = min(currentMin, price);
    }

    return maxProfit;
  }
}

void main(List<String> args) {
  print(Solution().maxProfit([7, 1, 5, 3, 6, 4]));
}
