//Square Root of a number

int floorSqrt(int n)
{
    int s = 0;
    int e = n;
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e){
        long sqr = mid*mid; 
        if(sqr > n)
            e=mid-1;
        else{
            ans = mid;
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
