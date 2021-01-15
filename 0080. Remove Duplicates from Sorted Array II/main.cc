#include "../libs.hpp"


class Solution{
public:
    int removeDuplicates(int* arr, int arrSize)
    {
        if (arrSize <= 2) 
            return arrSize;  
        int i=2;
        int index=2;
        
        for (i=2;i<arrSize;i++)
        {
            /* Key-Part */
            // 1. i가 새로운 숫자를 찾았으면 당연히 index에 집어넣음.
            // 2. 만약 index의 2번째 이전 원소가 i가 가리키는 것과 같다면, 
            //    index가 가리키는 곳에 새로운 원소로 집어넣었을 때, 3개의 중복된 숫자가 존재하게 됨.
            if ((arr[i]!=arr[i-1]) || (arr[index-2]!=arr[i])) 
                arr[index++]=arr[i];  
        }
        return index;
    }
};

int main()
{

    Solution S;
    return 0;
}