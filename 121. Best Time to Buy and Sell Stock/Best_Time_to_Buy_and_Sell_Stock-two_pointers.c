int max(int a, int b){
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0 || pricesSize == 1) return 0;
    
    int maxProfit = 0;
    int buy = 0;
    int sell = 1;
    
    while(sell < pricesSize){
        if(prices[buy] >= prices[sell]){
            buy = sell;
        }
        else{
            maxProfit = max(maxProfit, prices[sell] - prices[buy]);
        }
        sell++;
    }
    return maxProfit;
}