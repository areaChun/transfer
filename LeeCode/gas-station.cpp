/*
时间限制：1秒 空间限制：32768K 热度指数：11421
本题知识点： leetcode 贪心
 算法知识视频讲解
题目描述

There are N gas stations along a circular route, where the amount of gas at station i isgas[i].

You have a car with an unlimited gas tank and it costscost[i]of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note: 
The solution is guaranteed to be unique.

**/

/*
Note:贪心的思想很简单，就是每次迭代最大最好了。
     另外，我采用了循环栈和循环队列的思路，那公路变成环状。gas[(i+begin)%number]
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int number = gas.size();
        if(number<=0)
            return -1;
        for(int begin=0;begin<number;begin++){
            int add=0,costOil=0;
            for(int i=0;i<number;i++){
                add+=gas[(i+begin)%number];
                costOil+=cost[(i+begin)%number];
                if(add<costOil)
                    break;
                if(add>=costOil&&i==number-1)
                    return begin;
            }
        }
        return -1;
    }
};
