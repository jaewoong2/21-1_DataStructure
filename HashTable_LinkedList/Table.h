//
// 20160569 임재웅 자료구조 Hash Table p.51 Table.h
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
    void insert(const keyType &key, const dataType &data);
    bool lookup(const keyType &key, dataType &data);
    void deleteKey(const keyType &key);
    void dump();

private:
    struct Slot;
    typedef Slot* Link;
    struct Slot {
        keyType key;
        dataType data;
        Link next;
    };
    Link TableArray[MAX_TABLE];
    int hash(const keyType &key);
    bool search(Link &slotPointer, const keyType &target);
};

template <class keyType, class dataType>
int Table<keyType, dataType>::hash(const keyType &key) {
    return key % MAX_TABLE;
}


template <class keyType, class dataType>
bool Table<keyType, dataType>::search(Link &slotPointer, const keyType &target) {
    for(; slotPointer != nullptr; slotPointer = slotPointer->next) {
        // pos 값을 올렸을 때, InUse 이고 key 값이 찾고자 하는것과 같으면 true
        if(slotPointer->key == target) {
            return true;
        }
    } // InUse or Deleted 인 곳을 찾을 때 까지 pos 값을 올림
    return false;
}

template <class keyType, class dataType>
Table<keyType, dataType>::Table() {
    for(int i = 0; i < MAX_TABLE; i++) {
        TableArray[i] = nullptr;
    }
}

template <class keyType, class dataType>
void Table<keyType, dataType>::insert(const keyType &key, const dataType &data) {
    int pos = hash(key); // Head 의 위치 정하기.
    Link searchPointer = TableArray[pos];
    // pos 로 결정한 Head 에
    // key 값이 사용되지 않았으면, (아직 해당하는 key, data 가 안들어 와 있으면)
    if(search(searchPointer, key) == false) {
        Link newSlot = new Slot;
        newSlot->data = data;
        newSlot->key = key;
        newSlot->next = TableArray[pos];
        TableArray[pos] = newSlot;
    } else { // 이미 key 값이 사용되어 있으면,
        searchPointer->data = data; // 값만 변경
    }
}

template <class keyType, class dataType>
void Table<keyType, dataType>::deleteKey(const keyType &key) {
    int pos = hash(key);
    if (TableArray[pos] == nullptr) {
        return;
    }

    if (TableArray[pos]->key == key) {
        Link deleteSlot = TableArray[pos];
        TableArray[pos] = deleteSlot->next;
        delete deleteSlot;
        return;
    }

    for (Link tempSlot = TableArray[pos]; tempSlot->next != nullptr; tempSlot = tempSlot->next) {
        if (tempSlot->next->key == key) {
            Link deleteSlot = tempSlot->next;
            tempSlot->next = deleteSlot->next;
            delete deleteSlot;
            return;
        }
    }

}

template <class keyType, class dataType>
bool Table<keyType, dataType>::lookup(const keyType &key, dataType &data) {
    int pos = hash(key);
    Link searchPointer = TableArray[pos];
    if (search(searchPointer, key)) {
        data = searchPointer->data;
        return true;
    }
    return false;
}

template <class keyType, class dataType>
void Table<keyType, dataType>::dump() {
    for(int i = 0; i < MAX_TABLE; i++) {
        std::cout << "HEAD - " << i << '\t';
        std::cout << "\n";
        std::cout << "----" << '\n';
        for (Link tempSlot = TableArray[i]; tempSlot != nullptr; tempSlot = tempSlot->next) {
            std::cout << "key \t" << tempSlot->key << "\n";
            std::cout << "data \t" << tempSlot->data << "\n";
            std::cout << "----" << '\n';
        }
        std::cout <<" ==================== "<< '\n';
    }
}


#endif //HASHTABLEARRAY_TABLE_H
