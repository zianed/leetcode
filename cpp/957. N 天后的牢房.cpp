/**
8 间牢房排成一排，每间牢房不是有人住就是空着。

每天，无论牢房是被占用或空置，都会根据以下规则进行更改：

如果一间牢房的两个相邻的房间都被占用或都是空的，那么该牢房就会被占用。
否则，它就会被空置。
（请注意，由于监狱中的牢房排成一行，所以行中的第一个和最后一个房间无法有两个相邻的房间。）

我们用以下方式描述监狱的当前状态：如果第 i 间牢房被占用，则 cell[i]==1，否则 cell[i]==0。

根据监狱的初始状态，在 N 天后返回监狱的状况（和上述 N 种变化）。

 

示例 1：

输入：cells = [0,1,0,1,1,0,0,1], N = 7
输出：[0,0,1,1,0,0,0,0]
解释：
下表概述了监狱每天的状况：
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

示例 2：

输入：cells = [1,0,0,1,0,0,1,0], N = 1000000000
输出：[0,0,1,1,1,1,1,0]
 

提示：

cells.length == 8
cells[i] 的值为 0 或 1 
1 <= N <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/prison-cells-after-n-days
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    bool comp(vector<int>&v1, vector<int>&v2)
    {
        return v1[0] == v2[0] &&
            v1[1] == v2[1] &&
            v1[2] == v2[2] &&
            v1[3] == v2[3] &&
            v1[4] == v2[4] &&
            v1[5] == v2[5] &&
            v1[6] == v2[6] &&
            v1[7] == v2[7];
    }
    
    void printVec(vector<int>&v1) {
        cout << ":";
        for (int a : v1) {
            cout << a << ",";
        }
        cout << endl;
    }

    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N == 0) {
            return cells;
        }
        vector<vector<int>> hashVec;
        // 占位0
        hashVec.push_back(vector<int>());
        vector<int> cells1(8, 0);
        for (int i = 1; i <= 6; i++) {
            if (cells[i - 1] == cells[i + 1] ) {
                cells1[i] = 1;
            }
        }
        if (N == 1) {
            return cells1;
        }
        // 第1天
        hashVec.push_back(cells1);
        printVec(cells1);
        int index = 1;
        vector<int> cells2 = cells1;
        do {
            vector<int> cellsTmp(8, 0);
            for (int i = 1; i <= 6; i++) {
                if (cells2[i - 1] == cells2[i + 1] ) {
                cellsTmp[i] = 1;
            }
            }
            printVec(cellsTmp);
            hashVec.push_back(cellsTmp);
            cells2 = cellsTmp;
            index++;
        } while (!comp(cells2, cells1));
        index--;
        cout << index << "," << hashVec.size() << endl;
        int pos = N % index;
        if (pos == 0) {
            pos = index;
        }
        return hashVec[pos];
    }
};