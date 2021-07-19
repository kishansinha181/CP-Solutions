class Solution {
public:
    class Node{
        public:
        int first;
        int second;
        int sum;
        
        Node(int f,int s){
            first = f;
            second = s;
            sum = f + s;
        }
    };
    
    class cmp{
        public:
        bool operator()(Node A, Node B){
            return A.sum > B.sum;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node, vector<Node>, cmp> pq;
        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++ ){
                Node temp(nums1[i], nums2[j]) ;
                pq.push(temp);
            }
        }
        
        if(k > pq.size())
            k = pq.size();
        vector<vector<int>> ans;
        for(int i = 0 ; i < k ; i++){
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
        
    }
};