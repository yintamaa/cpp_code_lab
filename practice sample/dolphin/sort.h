//
// Created by Administrator on 2023/1/2.
//

#ifndef CPPTEST_SORT_H
#define CPPTEST_SORT_H

#include <vector>
#include <iostream>

class Cumrank {
private:
    static const int N = 1e5 + 5;
    int tree[N];
    std::vector<int>ans;
    bool vis[N];
public:
    int lowbit(int x) {
        return x & (-x);
    }
    // 对pos位置加上val的权值
    void add(int pos, int len, int val) {
        while (pos <= len) {
            tree[pos] += val;
            pos += lowbit(pos);
        }
    }
    // 获取pos位置的前缀和
    int get(int pos) {
        int ans = 0;
        while (pos > 0) {
            ans += tree[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }
    std::vector<int>& cumrank(std::vector<int>& temp) {
        for (auto &v: temp) {
            ans.emplace_back(get(v - 1));
            add(v, temp.size(), 1);
        }
        return ans;
    }
    void TestCumrank() {
        std::vector<int>temp = { 1,3,2,3,4 };
        auto ans = cumrank(temp);
        for (auto& v: ans) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }
};


#endif //CPPTEST_SORT_H
