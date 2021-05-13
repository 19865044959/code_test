# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题

*斜体*

**粗体**

***粗斜体***

[插入链接-比如插入bilibili官网](http://www.bilibili.com)

<http://www.bilibili.com>

- 无序列表
	- 子级列表
		- 子子级列表
			- 子子子级列表


1. 有序列表1
2. 有序列表2
3. 有序列表3

换行需要两个空格加回车  
换行需要两个空格加回车  

如何实现缩进？  
缩进啦,缩进1个中文字符  
&emsp;缩进啦,缩进1个中文字符  
&ensp;缩进啦,缩进半个中文字符  

>引用
>
>>多层引用

`代码块`

```c++
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0,status = 0;
        vector<int> pos(1<<5,-1);
        pos[0] = 0;
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(s[i] == 'a'){
                status ^= 1<<0;
            }
            else if(s[i] == 'e'){
                status ^= 1<<1;
            }
            else if(s[i] == 'i'){
                status ^= 1<<2;
            }
            else if(s[i] == 'o'){
                status ^= 1<<3;
            }
            else if(s[i] == 'u'){
                status ^= 1<<4;
            }
            if(pos[status] != -1){
                ans = max(ans, i + 1 - pos[status]);
            }
            else{
                pos[status] = i + 1;
            }
        }
        return ans;
    }
};
```




下面是3条分割线

---
***
___


# 这是一个heading #
# 这也是一个heading

## 原来二级标题下面就会有划线 ## 



