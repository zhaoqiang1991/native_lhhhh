//
// Created by lh on 2023-03-10.
//

#include "Methon.h"


template<typename T>
T Methon::swip(T &it, int &num) {
    cout << "==== it = " << it << "==== num = " << num << endl;
    T temp = it;
    it = num;
    num = temp;
    return temp;
}