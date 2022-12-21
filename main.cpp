/*
 *input: 一根单链表
output: 判断链表是否对称：true or false

func isSymmetric(node *ListNode) bool {
    // add implementation here
    return false;
}

public boolean isSymmetric(ListNode node) {
    // add implementation here
    return false;
}

example:
1. a -> b -> a return true
2. a -> b -> b -> a return true

需求：
1. 澄清需求 & 边界条件
2. 工业编码风格
3. UT设计
 */

#include <iostream>
#include <vector>
#include <unordered_map>

constexpr int LOOP_LIST = -1;
constexpr int IS_NOT_SYM = -2;
constexpr int SUCCESS = 0;
struct Retmsg {
    int ret_code;
};

class ListNode {
private:
    ListNode *next_pointer_; // 后继指针
    std::vector<int>temp_vector_;
    int value_;
    std::unordered_map<ListNode*, bool> hash_map_;
public:
    explicit ListNode(int value): value_(value){}
    ListNode(int value, ListNode next_node) {

    }
    Retmsg isSymmetric(ListNode* node) {
        Retmsg ret_msg = Retmsg({SUCCESS});
        while (node != nullptr) {
            if (hash_map_.count(node)) {
                temp_vector_.clear();
                hash_map_.clear();
                ret_msg.ret_code = LOOP_LIST;
                return ret_msg;
            }
            hash_map_[node] = true;
            temp_vector_.push_back(node->value_);
            node = node->next_pointer_;
        }
        size_t len = temp_vector_.size();
        for (int i = 0; i < len / 2; i++) {
            if (temp_vector_[i] != temp_vector_[len - i - 1]) {
                ret_msg.ret_code = IS_NOT_SYM;
                break;
            }
        }
        temp_vector_.clear();
        hash_map_.clear();
        return ret_msg;
    }
};

int main() {
    // INPUT：1 2 3 2 1     OUTPUT: Retmsg{SUCCESS};
    // INPUT: 1 2 3 3 2 1  OUTPUT: Retmsg{SUCCESS};
    // INPUT: 1            OUTPUT: Retmsg{SUCCESS};
    // INPUT: 1(node) -> 2(node) -> 1(node) OUTPUT: Retmsg{LOOP_LIST};
    // INPUT: (node 1, value 1) -> (node 2, value 2) -> (node 3, value 2) -> (node 1, value1) OUTPUT: Retmsg{LOOP_LIST};
    // INPUT: (nullptr) OUTPUT: Retmsg{SUCCESS};
    // INPUT: 1(node) -> 1(node); OUTPUT: Retmsg{LOOP_LIST};
}