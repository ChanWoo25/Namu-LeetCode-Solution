### 880. Decoded String at Index

**Time Complexity** : $O(N)$

**Space Complexity** : $O(1)$

**Description**
- 이 문제의 관련 자료구조는 Stack 이다.
- Decoded string을 저장하기엔 메모리 낭비가 크다.
- 복호화가 순차적이므로, 문자열을 하나의 스택으로 보고 깔끔한 논리로 Goal Constraint를 작성하는게 중요했다.

```cpp
string sol(string S, int K) 
{ 
    long size = 0; 
    unsigned i = 0; 
    int n = S.length(); 
    //Find the size 
    for(i = 0; size < K; i++) 
        size = \ 
        (isdigit(S[i])) ? (size*(S[i]-'0')) : (size+1);  
     
    while(i--) 
    { 
        char c = S[i]; 
        K %= size; 
        if(isdigit(c)) 
            size /= (c-'0'); 
        else // isalpha(c) 
        { 
            if(K == 0)  
                return string(1, c); 
            else  
                size--; 
        } 
    }
    return "";
}
```
