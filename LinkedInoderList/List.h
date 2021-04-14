#ifndef LINKEDLIST__INORDERLIST_H
#define LINKEDLIST__INORDERLIST_H

typedef int ListElementType;
struct Node;
typedef Node* Link;
struct Node {
    ListElementType elem;
    Link next;
};

class List {
public:
    // 생성자를 호출 하면, Dummy Head 를 생성한다. Dummy Head 는 Head 가 없는 Special case 를 지우기 위함이다.
    List();
    // 함수가 끝나면 Delete 한다. (head 가 없을 때 까지 head 를 증가시키며 head 를 삭제한다.)
    ~List();
    // 순서를 지키며 값을 Insert 한다.
    void insert(const ListElementType &elem);
    // 매개변수로 들어온 target 을 삭제한다.
    void remove(const ListElementType &target);
    // 0번째 에 있는 값을 elem 에 넣어준다.
    // 제대로 실행되면, true 를 반환. head.next 가 없으면 false 를 반환.
    bool first(ListElementType &elem);
    // current.next 의 값을 elem 에 넣어준다.
    // current.next 가 마지막이라면, false 를 반환. 그 이외에 case 에서는 true 를 반환한다.
    bool next(ListElementType &elem);

private:
    Link head;
    Link current;
};

#endif //LINKEDLIST__INORDERLIST_H
