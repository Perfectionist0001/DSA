class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       sort(deck.begin(),deck.end());
       queue<int>que;
       int n = deck.size();
       vector<int>result(n);
       for(int i = 0; i < n; i++){
        que.push(i);
       } 
       for(int e : deck){
        int i = que.front();
        que.pop();
        result[i] = e;
        if(!que.empty()){
            que.push(que.front());
            que.pop();
        }
       }
       return result;
    }
};