//
// 20160569 임재웅 자료구조 Table.h
//

#ifndef HASHTABLEARRAY_TABLE_H
#define HASHTABLEARRAY_TABLE_H
#include <cassert>
#include <iostream>

const int MAX_TABLE = 11;

template <class keyType, class dataType>
class Table {
public:
    Table();
    // data 를 key 에 해당하는 hash index 번호에 저장 해주는 함수
    void insert(const keyType &key, const dataType &data);
    // 매개변수 data 에 key 값에 존재하는 data 를 넣어주는 넣어주는 함수
    bool lookup(const keyType &key, dataType &data);
    // key 값을 지운다. (key 값에 해당하는 hash index 번호 에 존재하는 slot status 를 Deleted 처리해준다.)
    void deleteKey(const keyType &key);
    // Table 을 보여준다.
    void dump();

private:
    enum slotType { Empty, Deleted, InUse };
    struct slot {
        slotType slotStatus;
        keyType key;
        dataType data;
    };
    slot TableArray[MAX_TABLE];
    // number of entry
    int entries;
    // key to hash function
    int hash(const keyType &key);
    // pos < MAX_TABLE ? pos = pos + 1 : 0;
    int probe(const int &pos);
    // target 의 key 값을 찾는다. 매개변수로 들어온 pos 는 hash 값에 해당하는 index 로 바뀌어져 있다.
    bool search(int &pos, const keyType &target);
};

template <class keyType, class dataType>
int Table<keyType, dataType>::hash(const keyType &key) {
    return key % MAX_TABLE;
}

template <class keyType, class dataType>
int Table<keyType, dataType>::probe(const int &pos) {
    if(pos < MAX_TABLE - 1) {
        return pos + 1;
    }
    return 0;
}

template <class keyType, class dataType>
bool Table<keyType, dataType>::search(int &pos, const keyType &target) {
    for(; TableArray[pos].slotStatus != Empty ; pos = probe(pos)) {
    // pos 값을 올렸을 때, InUse 이고 key 값이 찾고자 하는것과 같으면 true
        if(TableArray[pos].slotStatus == InUse && TableArray[pos].key == target) {
            return true;
        }
    } // InUse or Deleted 인 곳을 찾을 때 까지 pos 값을 올림
    return false;
}

template <class keyType, class dataType>
Table<keyType, dataType>::Table() {
    entries = 0;
    for(int i = 0; i < MAX_TABLE; i++) {
        TableArray[i].slotStatus = Empty;
    }
}

template <class keyType, class dataType>
void Table<keyType, dataType>::insert(const keyType &key, const dataType &data) {
    assert(entries < MAX_TABLE - 1);
    int pos = hash(key);
    // key 값이 사용되지 않았으면, (아직 해당하는 key, data 가 안들어 와 있으면)
    if(search(pos, key) == false) {
        pos = hash(key); // 1. pos 값을 초기 화
        while (TableArray[pos].slotStatus == InUse) { // 2. 비어있는 곳 (Empty, Deleted) 를 찾는다.
            pos = probe(pos);
        }
        entries += 1; // 3. entries 를 1 증가한다.
    }
    // 값을 넣어준다.
    TableArray[pos].slotStatus = InUse;
    TableArray[pos].key = key;
    TableArray[pos].data = data;
}

template <class keyType, class dataType>
void Table<keyType, dataType>::deleteKey(const keyType &key) {
    int pos = hash(key);
    if (search(pos, key) == true) {
        TableArray[pos].slotStatus = Deleted;
        entries -= 1;
    }
}

template <class keyType, class dataType>
bool Table<keyType, dataType>::lookup(const keyType &key, dataType &data) {
    int pos = hash(key);
    if (search(pos, key)) {
        data = TableArray[pos].data;
        return true;
    }
    return false;
}

template <class keyType, class dataType>
void Table<keyType, dataType>::dump() {
    for(int i = 0; i < MAX_TABLE; i++) {
        std::cout << i << '\t';
        switch (TableArray[i].slotStatus) {
            case InUse:
                std::cout << "In Use key \t" << TableArray[i].key << "\n";
                std::cout << i << '\t';
                std::cout << "In Use data \t" << TableArray[i].data << "\n";
                break;
            case Deleted:
                std::cout << "In Use key \t" << TableArray[i].key << "\n";
                std::cout << i << '\t';
                std::cout << "Deleted data \t" << TableArray[i].data << "\n";
                break;
            case Empty:
                std::cout << "Empty \t"<< "\n";
                break;
            default:
                break;
        }
        std::cout << "---------------------------------" << '\n';
    }
    std::cout << "Entries = " << entries << "\n\n";
}


#endif //HASHTABLEARRAY_TABLE_H
