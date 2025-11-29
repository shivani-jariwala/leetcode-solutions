class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end()) return "";
        string res="";
        const vector<pair<int, string>>&history = mpp[key];
        int low=0, high=history.size()-1, mid;
        while(low<=high) {
            mid = low + (high-low)/2;
            if(history[mid].first<=timestamp){
                res = history[mid].second;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */