//
// Created by 82109 on 2021-05-03.
//

#ifndef TABLE_ARRAY_TABLE_H
#define TABLE_ARRAY_TABLE_H
#include <cassert>

const int MAX_TABLE = 200;

template <class dataType, class keyType>
class Table {
public:
    Table();
    // find data of table's key, 파라미터에 들어온 data 에 key 에 속한 data 를 넣어준다.
    bool lookup(const keyType &key, dataType &data);
    void insert(const keyType &key, const dataType &data);
    // remove by key parameter
    void remove(const keyType &key);

private:
    struct Item {
        keyType key;
        dataType data;
    };
    Item tableArray[MAX_TABLE];
    int entries; // number of items, 앞으로 들어오게 될 item 의 위치 값.
    int search(const keyType &key);
};

// 찾고자하는 key 가 있으면 그 위치를 반환. (pos < entries)
// 찾고자하는 key 가 없으면 entries 값을 반환. (number of items)
template <class dataType, class keyType>
int Table<dataType, keyType>::search(const keyType &key) {
    int pos = 0;

    while (pos < entries && tableArray[pos].key != key) {
        pos += 1;
    }

    return pos;
}

template <class dataType, class keyType>
Table<dataType, keyType>::Table() {
    entries = 0;  // number of
}

template <class dataType, class keyType>
bool Table<dataType, keyType>::lookup(const keyType &key, dataType &data) {
    int pos = search(key);
    if (pos < entries) { // key 값이 table 에 존재.
        data = tableArray[pos].data;
        return true;
    }
    return false;
}

template <class dataType, class keyType>
void Table<dataType, keyType>::insert(const keyType &key, const dataType &data) {
    assert(entries < MAX_TABLE);
    int pos = search(key);

    tableArray[pos].data = data;
    tableArray[pos].key = key;

    if (pos == entries) {
        entries += 1;
    }
}

template <class dataType, class keyType>
void Table<dataType, keyType>::remove(const keyType &key) {
    int pos = search(key);

    if (pos < entries) {
        entries -= 1;
        tableArray[pos] = tableArray[entries];
    }
}

#endif //TABLE_ARRAY_TABLE_H
