int binSearch(vector<int> &nums, int s, int e, int target){
    
    if(s>e){
        return -1;
    }

    int mid = s+(e-s)/2;
    
    if(nums[mid] == target)
        return mid;
    
    else if(nums[mid] > target)
        binSearch(nums, s, mid-1, target);
    
    else
        binSearch(nums, mid+1, e, target);
}


int search(vector<int> &nums, int target) {
    // Write your code here.
    int k = binSearch(nums, 0, nums.size()-1, target);
    return k;
}