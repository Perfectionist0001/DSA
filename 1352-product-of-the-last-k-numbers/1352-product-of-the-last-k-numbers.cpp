
class ProductOfNumbers {
public:
    vector<int> arr;
    ProductOfNumbers() {

    }    
    void add(int num) {
        arr.push_back(num);
    }
    int getProduct(int k) {
        int ans = 1;   
        for (int i = arr.size() - k; i < arr.size(); i++) {
            ans *= arr[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */