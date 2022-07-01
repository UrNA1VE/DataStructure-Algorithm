// https://leetcode.com/problems/stock-price-fluctuation/

class StockPrice {
public:
    unordered_map<int, int> prices;
    map<int, int> table;
    int lasttime = -1;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (prices.count(timestamp)) {
            int preprice = prices[timestamp];
            table[preprice]--;
            if (table[preprice] == 0) table.erase(preprice);
        }
        prices[timestamp] = price;
        table[price]++;
        lasttime = max(lasttime, timestamp);
    }
    
    int current() {
        return prices[lasttime];
    }
    
    int maximum() {
        return table.rbegin()->first;
    }
    
    int minimum() {
        return table.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
