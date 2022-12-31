#pragma once
template<typename DataType>
struct BinaryNode {
    DataType data;
    BinaryNode<DataType>* lchild, * rchild;
    BinaryNode() {
        data = 0;
        lchild = NULL;
        rchild = NULL;
    }
    BinaryNode(DataType d) {
        data = d;
        lchild = NULL;
        rchild = NULL;
    }
};