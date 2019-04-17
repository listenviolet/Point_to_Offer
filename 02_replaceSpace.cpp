class Solution {
public:
	void replaceSpace(char *str,int length) {
        int total_space = 0;
        for(int i = 0; i < length; ++i)
        {
            if(str[i] == ' ') total_space++;
        }
        
        int cnt = 0;
        int move; 
        for(int i = length - 1; i >= 0; --i)
        {
            move = (total_space - cnt) * 2;
            if(str[i] != ' ') 
            {
                str[i + move] = str[i];
            }
            else
            {
                str[i + move] = '0';
                str[i + move - 1] = '2';
                str[i + move - 2] = '%';
                cnt++;
            }
        }
	}
};


// 2. 替换空格
// 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
// 例如，当字符串为We Are Happy.
// 则经过替换之后的字符串为We%20Are%20Happy。

// 运行时间：5ms

// 占用内存：588k

// Alg:
// 先遍历整个字符串，计算字符串中空格的总数，从而可以计算出替换后的字符串长度
// （根据替换规则，每次替换空格时，都会使字符串的长度增加2）。
// 然后，使用两个指针或索引，从后往前遍历，
// 即初始化指针或索引分别指向替换前和替换后字符串的末尾，循环递减，
// 如遇到空格，则替换为 "%20"，从而减少字符串移动的次数，降低时间复杂度。