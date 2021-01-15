#include "../libs.hpp"


class Solution { 
public: // Solution 1

    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) { 
        int m(nums1.size()), n(nums2.size()); 
        if(m > n)  //=> Ensure always (j > 0)
            return findMedianSortedArrays1(nums2, nums1); 
        int l(0), r(m); 
        while(l <= r) 
        { 
            int i = (l+r)/2;        // i divides the nums1 array into 2 parts 
            int j = (m+n+1)/2 - i;  // j divides the nums2 array into 2 parts 
            if(i > 0 && nums1[i-1] > nums2[j]) 
                r = i -1; 
            else if(i < m && nums2[j-1] > nums1[i]) 
                l = i + 1; 
            else  
            {   //  
                int lmax, rmin; 
                if(i == 0) 
                    lmax = nums2[j-1]; 
                else if(j == 0) 
                    lmax = nums1[i-1]; 
                else 
                    lmax = max(nums1[i-1], nums2[j-1]); 
                if((m+n)%2) // 총 elem 수가 홀수이면, median은 원소 하나. 
                    return (double)lmax; 
                 
                // Otherwise, 2개의 median을 구해서 평균을 내야함. 
                if(i == m) 
                    rmin = nums2[j]; 
                else if(j == n) 
                    rmin = nums1[i]; 
                else 
                    rmin = min(nums1[i], nums2[j]); 
                return (double)(lmax+rmin) / 2.0; 
            } 
            return -1.0;// Error 
        } 
    } 

public: // Solution 2

    int findKth(const vector<int>& v1, int i1, \ 
                const vector<int>& v2, int i2, int kth) 
    {   // Goal Condition 
        if(i1 >= v1.size()) 
            return v2[i2+kth-1]; 
        if(i2 >= v2.size()) 
            return v1[i1+kth-1]; 
        if(kth == 1) 
            return min(v1[i1], v2[i2]); 
        // Bisection method on two arrays. 
        // if kth==2or3 -> kth/2-1 = 0 -> m값이 작은 쪽은 적어도 (kth/2-1) 개는  
        // 우리가 찾고자 하는 k-th 값보다 작음을 보장
        int m1(INT32_MAX), m2(INT32_MAX); 
        m1 = (i1+kth/2-1 < v1.size())?v1[i1+kth/2-1]:m1; 
        m2 = (i2+kth/2-1 < v2.size())?v2[i2+kth/2-1]:m2; 
         
        // if m1,m2 are proper mid value, kth-num is either v1[i1+kth/2] or v2[i2+kth/2]. 
        if(m1 < m2) 
            return findKth(v1, i1+kth/2,    v2, i2,         kth-kth/2); 
        else 
            return findKth(v1, i1,          v2, i2+kth/2,   kth-kth/2); 
    } 
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) { 
        int m = nums1.size(), n = nums2.size(); 
        int midl = (m+n+1)/2; 
        int midr = (m+n+2)/2; 
         
        if(midl == midr)    // (m+n) is odd. 
            return (double)findKth(nums1, 0, nums2, 0, midl); 
        else                // (m+n) is even. 
            return (double)(findKth(nums1, 0, nums2, 0, midl) \ 
                          + findKth(nums1, 0, nums2, 0, midr)) / 2.0; 
    } 
};

int main()
{

    Solution S;
    return 0;
}