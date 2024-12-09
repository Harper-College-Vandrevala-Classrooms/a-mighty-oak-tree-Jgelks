#include <iostream>
#include <string>

using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel(string name) : name(name) {}

    string get_name() const {
        return name;
    }
};

class Node {
private:
    Squirrel* squirrel;
    Node* left;
    Node* right;

public:

    Node(Squirrel* squirrel) : squirrel(squirrel), left(nullptr), right(nullptr) {}

    void set_left(Node* left_node) {
        left = left_node;
    }

    void set_right(Node* right_node) {
        right = right_node;
    }

    Node* get_left() {
        return left;
    }

    Node* get_right() {
        return right;
    }

    Squirrel* get_squirrel() {
        return squirrel;
    }

    void in_order_traversal() {
        if (left != nullptr) {
            left->in_order_traversal();
        }
        cout << squirrel->get_name() << " ";
        if (right != nullptr) {
            right->in_order_traversal();
        }
    }
};

int main() {
   
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");

    Node node_one(&cheeks);
    Node node_two(&squeaks);
    Node node_three(&fluffybutt);

    node_one.set_left(&node_two);
    node_one.set_right(&node_three);


    cout << "Left child of node_one: " << node_one.get_left()->get_squirrel()->get_name() << endl;
    cout << "Right child of node_one: " << node_one.get_right()->get_squirrel()->get_name() << endl;

    cout << "In-order traversal: ";
    node_one.in_order_traversal();
    cout << endl;

    return 0;
}