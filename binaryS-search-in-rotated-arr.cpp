//Search in a rotated array

int pivotElement(vector<int>& arr, int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    
    while(s<e){
        if(arr[mid]>=arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

int binaryS(vector<int>& arr, int n, int k, int s, int e){
    int mid = s + (e-s)/2;

    while(s<=e){
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[mid]>k){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = pivotElement(arr, n);
    int ans;
    if(k>=arr[pivot] && k<=arr[n-1]){
        ans = binaryS(arr, n, k, pivot, n-1);
    }

    else{
        ans = binaryS(arr, n, k, 0, pivot-1);
    }
    
    return ans;

}
