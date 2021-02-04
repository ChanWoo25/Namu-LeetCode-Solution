#include "../libs.hpp"


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        multiset<int> mSet;
        for(const auto& x : nums)
        {
            int i = int( mSet.lower_bound(x) - mSet.begin())
            ;
        
        }
    }
};


class Solution {
public:
    vector<int> sol;

    void merge(vector<pair<int,int>> &a, vector<pair<int,int>> &tmp, int start,int mid,int end)
    {
        int i=start,j=mid+1, k=start;
        while(i<=mid && j<=end)
        {
            if(a[i].first<=a[j].first){
                sol[a[i].second] += ((j - 1) - mid);
                tmp[k++] = a[i++];
            }
            else
                tmp[k++] = a[j++];
        }

        while(i<=mid){
            sol[a[i].second] += ((j - 1) - mid);
            tmp[k++] = a[i++];
        }

        while(j <= end){
            tmp[k++] = a[j++];
        }

        for(k = start; k <= end; k++)
            a[k] = tmp[k];
    }
    
    void mergesort(vector<pair<int,int>> &a, vector<pair<int,int>> &tmp, int start,int end){
        if(start>=end) return;
        int mid = start+(end-start)/2;
        mergesort(a, tmp, start,mid);
        mergesort(a, tmp, mid+1,end);
        merge(a, tmp, start,mid,end);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n =nums.size();
        sol.resize(n,0);
        vector<pair<int,int>> idx;
        vector<pair<int,int>> tmp(n);

        for(int i=0;i<n;i++)
            idx.push_back({nums[i],i});
        
        mergesort(idx, tmp, 0,n-1);
        return sol;
    }
};


int main()
{

    Solution S;
    return 0;
}