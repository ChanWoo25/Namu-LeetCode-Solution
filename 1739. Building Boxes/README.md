## 

### Description
You have a cubic storeroom where the width, length, and height of the room are all equal to n units. You are asked to place n boxes in this room where each box is a cube of unit side length. There are however some rules to placing the boxes:

You can place the boxes anywhere on the floor.
If box x is placed on top of the box y, then each side of the four vertical sides of the box y must either be adjacent to another box or to a wall.
Given an integer n, return the minimum possible number of boxes touching the floor.
#### Constraint:
#### Note:
#### Follow-Up:

---------------------------------------
### Try 1
- 가독성과 논리가 명확하지 못한 풀이.
- 
> Time Complexity : tot을 찾기 위한 O(k1) + ret을 찾기 위한 O(k2) Linear Solution \
  Space Complexity : O(1)
```cpp
class Solution {
public:
    int minimumBoxes(int n) {
        int layer(0), tot(0), i(1);
        while(tot <= n)
        {
            layer += (i++);
            tot += layer;
        }

        tot -= layer;
        layer -= (--i);

        int rest = n - tot;
        if(rest == 0) 
            return layer;
        else
        {
            int ret = layer, l=1;
            while(rest > 0)
            {
                rest -= (l++);
                ret++;
            }
            return ret;
        }
    }
};
```

### Try
- 
> Time Complexity : O(N)\
  Space Complexity : O(1)
```cpp

```