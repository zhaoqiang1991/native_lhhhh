//
// Created by lh on 2025/2/19.
//

#ifndef LH_NODE_H
#define LH_NODE_H


class Node {
public:
    Node(int val, Node *next);

    Node *next;
    int val;

    Node();
};


#endif //LH_NODE_H
