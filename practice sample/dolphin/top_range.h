//
// Created by Administrator on 2023/1/1.
//

#ifndef CPPTEST_TOP_RANGE_H
#define CPPTEST_TOP_RANGE_H

#include <vector>
#include <iostream>

class TopRangeObj {
private:
    static const int N = 1e5 + 5;
    int q[N];
public:
    std::vector<int> TopRange(std::vector<double>&arr) {
        std::vector<int>ans;
        int id = 0;
        q[0] = -1;
        for(int i = 0; i < arr.size(); i++) { // 枚举遍历，N个元素，复杂度为O(N)
            while (id > 0 && arr[q[id]] < arr[i]) { // 每个元素最多只会进队出队一次，while体最多共执行2*N次，sigma{while} = O(N)
                id--;
            }
            ans.push_back(i - q[id]);
            q[++id] = i;
        }
        return ans; // 因此总复杂度为O(N) + O(N) => O(N)
    }

    void TestTopRange() {
        std::vector<double>temp = { 13.5,13.6,13.4,13.3,13.5,13.9,13.1,20.1,20.2,20.3 };
        auto ans = TopRange(temp);
        for (auto &v: ans) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }

};

#endif //CPPTEST_TOP_RANGE_H
