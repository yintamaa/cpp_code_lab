//
// Created by Administrator on 2023/1/1.
//

#ifndef CPPTEST_MEMORY_H
#define CPPTEST_MEMORY_H

#include <iostream>
#include <cmath>

class Memory {
    typedef long long ll;

public:
    // 返回等差数列最大的项数、和，使得 sigma <= val
    std::pair<ll, ll> binarySearch(ll first, ll diff, ll l, ll r, ll val) {
        auto check = [&] (ll mid) -> bool {
            ll last = first + diff * (mid - 1);
            return (first + last) * mid <= 2 * val;
        };
        ll ans = 0;
        while (l + 5 < r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        for (auto i = l; i <= r; i++) {
            if (check(i)) {
                ans = i;
            }
        }
        return {ans, (2 * first + diff * (ans - 1)) * ans / 2};
    }

    void TestMemory() {
        long long M1, M2;
//        M1 = 8, M2 = 11;
//        M1 = 2, M2 = 2;
//        M1 = 0, M2 = 0;
//        M1 = 11, M2 = 8;
//        M1 = 1e18, M2 = 1e18;
        scanf("%lld%lld", &M1, &M2);
        auto seq_data = binarySearch(1, 1, 1, 1e9, abs(M1 - M2));
        bool is_swap = false;
        if (M2 > M1) { // 令M1为大的数
            std::swap(M2, M1);
            is_swap = true;
        }
        M1 -= seq_data.second;
        ll first = 1 + seq_data.first;
        if (M2 == M1 && is_swap) { // 代表M2 M1发生了交换，相等的时候需要先走M1，否则先走M2
            std::swap(M2, M1);
            is_swap = false;
        }
        auto m1_data = binarySearch(first, 2, 1, 1e9, M1);
        auto m2_data = binarySearch(first + 1, 2, 1, 1e9, M2);
        if (!is_swap) {
            printf("%lld %lld %lld", seq_data.first + m1_data.first + m2_data.first + 1, M1 - m1_data.second, M2 - m2_data.second);
        } else {
            printf("%lld %lld %lld", seq_data.first + m1_data.first + m2_data.first + 1, M2 - m2_data.second, M1 - m1_data.second);
        }
    }
};

#endif //CPPTEST_MEMORY_H
