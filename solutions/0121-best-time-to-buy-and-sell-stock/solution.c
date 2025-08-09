int maxProfit(int* prices, int pricesSize){
    int x = 0;
    int max = 0;
    int number = prices[0];

    for(int i = 1 ;  i < pricesSize ; ++i){
        if(prices[i] > number){
            x = prices[i] - number;
            if(x > max){
                max = x;
            }
        }
        else{
            number = prices[i];
        }
    }

    return max;
}
   
