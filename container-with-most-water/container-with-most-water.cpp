class Solution {
public:
    int maxArea(vector<int>& height) {
         int i =0; 
        int j = height.size()-1;
        int max_water = 0;// to store the maximum water collected
        while(i< j){
           int min_height = min(height[i], height[j]); // minimum of the two vertical lines height is responsible for containing the water 
           int width = j-i; // index of j - index of i
            
           max_water = max(max_water, min_height *width); // update the max_water 
            if(height[i] > height[j]){
              //whichever has the minimum height will move
                j--;
            }else{
                i++; // if i has minimum height we will increment it or both i and j pointers have same height increment i it dosen't effect even we can decrement j also for the equal heights 
            }
            
        }
        return max_water;
    }
};