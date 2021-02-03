#ifndef __ST_H
#define __ST_H

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

template<typename T>
class SegmentTree {
typedef     std::vector<T>          vT  ;
typedef     std::pair<int, int>     pii ; // Only Control index.

public:
    SegmentTree(){}

    SegmentTree(const std::vector<T> arr) {
        Construct(arr); 
    }

    T Query(const pii& q)
    {
        if(q.first < 0 || q.second >= N || q.first > q.second)
            std::perror("Unvalid Query");

        return QueryUtil(std::make_pair(0, N-1), q, 0);
    }

    void Update(const int &i, const T &diff) 
    {
        UpdateUtil(std::make_pair(0, N-1), i, diff, 0);
    }

    void Construct(const std::vector<int> &arr)
    {
        N = arr.size();
        H = (int)(std::ceil(log2(N)));
        ST.assign(2*(int)pow(2, H) - 1, -1);
        ConstructUtil(arr, std::make_pair(0, N-1), 0);   
    }

    void print(){
        std::cout << "SegmentTree.print() : "
                  << "N: " << N << ", H: " << H << ", Size: " << ST.size()
                  << "\n{ ";
        for(auto x: ST)
            std::cout << x << ", ";
        std::cout << "}" << std::endl;
    }

private:

    vT ST;      // member Segment Tree
    int N,      // the size of original array.
        H;      // Height of Segment tree.

    int midIndexOf(const int &s, const int &e) const {
        return s + (e - s)/2;
    }

    T QueryUtil(pii s, const pii& q, int si)
    {
        if(q.first <= s.first && q.second >= s.second)
            return ST[si];

        if(s.second < q.first || q.second < s.first)
            return 0;

        int midIndex = midIndexOf(s.first, s.second);
        return QueryUtil(std::make_pair(s.first, midIndex), q, 2*si + 1) +
            QueryUtil(std::make_pair(midIndex+1, s.second), q, 2*si + 2);
    }

    void UpdateUtil(pii s, const int &i, const int &diff, int si)
    {
        if(i < s.first || s.second < i)
            return;
        
        ST[si] += diff;
        if(s.first != s.second)
        {
            int m = midIndexOf(s.first, s.second);
            UpdateUtil(std::make_pair(s.first, m), i, diff, 2*si + 1);
            UpdateUtil(std::make_pair(m + 1, s.second), i, diff, 2*si + 2);
        }
    }

    T ConstructUtil(const std::vector<T> &arr, pii s, int si)
    {
        if(s.first == s.second){
            ST[si] = arr[s.first];
            return arr[s.first];
        }

        int m(midIndexOf(s.first, s.second));
        return (ST[si] = ConstructUtil(arr, std::make_pair(s.first, m), 2*si + 1) + 
                        ConstructUtil(arr, std::make_pair(m+1, s.second), 2*si + 2));
    }

};




#endif