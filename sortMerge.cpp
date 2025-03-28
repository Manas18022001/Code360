void merge(vector<int> &arr, int s, int e){
    int mid = s+(e-s)/2;
    int arrIndex = s;

    int len1 = mid-s+1;
    int len2 = e-mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    for(int i=0; i<len1; i++){
        arr1[i] = arr[arrIndex++];
    }

    for(int j=0; j<len2; j++){
        arr2[j] = arr[arrIndex++];
    }

    int i= 0;
    int j= 0;
    arrIndex = s;
    while(i<len1 && j<len2){
        if(arr1[i] <= arr2[j]){
            arr[arrIndex++] = arr1[i++];
        }
        else{
            arr[arrIndex++] = arr2[j++];
        }
    }

    while(i<len1){
            arr[arrIndex++] = arr1[i++];
    }

    while(j<len2){
            arr[arrIndex++] = arr2[j++];
    }
}

void solve(vector<int> &arr, int s, int e){
    if(s>=e){
        return;
    }

    int mid = s+(e-s)/2;

    //solve left
    solve(arr, s, mid);
    //solve right
    solve(arr, mid+1, e);

    //merge
    merge(arr, s, e);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    solve(arr, 0, n-1);
}