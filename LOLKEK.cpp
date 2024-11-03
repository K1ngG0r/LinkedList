#include <iostream>

template <typename T>
class LinkedList {
private:
    class Node {
    public:
        T value;
        Node* next;
        Node(T value) 
            : value{ value }, next{ nullptr } {}

    };
    Node* first;
    Node* last;
public:
    LinkedList() :first{ nullptr }, last{ nullptr } {}
    ~LinkedList() {
        if (!IsEmpty()) {
            Node* current = first->next;
            while (current != nullptr) {
                delete first;
                first = current;
                current = current->next;
            }
            delete first;
            first = nullptr;
            last = nullptr;
        }
    }

    LinkedList& AddToTail(T value) {
        Node* node = new Node(value);
        if (IsEmpty()) {
            first = node;
            last = node;
            return *this;
        }
        last->next = node;
        last = node;
    }
    bool IsEmpty() const {
        return first == nullptr;
    }
    int Size() {
        int count = 0;
        Node* current = first->next;
        while (current != nullptr) 
            count++;
        return count;
    }

    LinkedList& AddToHead(T value) {
        Node* node = new Node(value);
        if (IsEmpty()) {
            first = node;
            last = node;
            return *this;
        }
        node->next = first;
        first = node;
        return *this;
    }

    LinkedList& DeleteFromHead() {
        if (IsEmpty()) {
            std::cout << "List is empty!" << std::endl;
            return *this;
        }
        Node* current = first;
        first = current->next;
        delete current;

        return *this;
    }

    LinkedList& DeleteFromTail() {
        if (IsEmpty()) {
            std::cout << "List is empty!" << std::endl;
            return *this;
        }
        Node* current = first;
        while (current->next != last)
            current = current->next;
        delete last;
        current->next = nullptr;
        last = current;
        return *this;
    }


    friend std::ostream& operator <<(std::ostream& out, const LinkedList& list) {
        if (!list.IsEmpty()) {
            Node* current = list.first;
            while (current != nullptr) {
                out << current->value << '\t';
                current = current->next;
            }
        }
        else
            std::cout << "List is empty" << std::endl;
        return out;
    }

    LinkedList& DeleteAll() {
        Node* current = first->next;
        while (current != nullptr) {
            delete first;
            first = current;
            current = current->next;
        }
        delete first;
        first = nullptr;
        last = nullptr;
        return *this;
    }
    
    LinkedList& AddInPozition(T element, unsigned int pozinion) {
        if (pozinion < Size())
        {
            Node* current = first->next;
            for (size_t i = 0; i < pozinion; i++)
                current = current->next;
            current->value = element;
        }
        return *this;
    }

};

int main()
{
    LinkedList<int> list{};
    list.AddToTail(5);
    list.AddToTail(3);
    list.AddToTail(2);
    list.AddToTail(1);
    list.AddToHead(0);
    std::cout << list << std::endl;
    std::cout << list.DeleteFromHead() << std::endl;
    std::cout << list.DeleteFromTail() << std::endl;
    std::cout << list.AddInPozition(10, 2) << std::endl;



    return 0;
}