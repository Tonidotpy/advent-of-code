#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
    Node* parent;
    int depth;
};

Node* newNode(int val, Node* parent, int depth) {
    Node* node = new Node;
    node->val = val;
    node->l = NULL;
    node->r = NULL;
    node->parent = parent;
    node->depth = depth;
    return node;
}
Node* parse(string s) {
    Node* tree = newNode(-1, NULL, 0);
    Node* curr = tree;

    bool isLeft = true;
    int depth = 0;
    for (int i=0; i < s.size(); ++i)
    {
        if (s[i] == '[') {
            isLeft = true;
            ++depth;
            curr->l =  newNode(-1, curr, depth);
            curr->r =  newNode(-1, curr, depth);
            curr = curr->l;
        }
        else if (isdigit(s[i])) {
            string num = "";
            while (isdigit(s[i])) {
                num += s[i];
                ++i;
            }
            --i;
            curr->val = stoi(num);
        }
        else if (s[i] == ',') {
            isLeft = false;
            curr = curr->parent->r;
        }
        else if (s[i] == ']') {
            --depth;
            curr = curr->parent;
        }
    }
    return tree;
}
void incDepth(Node* tree) {
    if (tree == NULL)
        return;

    ++tree->depth;
    incDepth(tree->l);
    incDepth(tree->r);
}
Node* merge(Node* l, Node* r) {
    Node* tree = newNode(-1, NULL, -1);
    l->parent = tree;
    r->parent = tree;
    tree->l = l;
    tree->r = r;

    incDepth(tree);
    return tree;
}

void explode(Node* node) {
    Node* l = node;
    Node* r = node;

    while (l->depth > 0 && l->parent->l == l)
        l = l->parent;
    if (l->depth > 0) {
        l = l->parent->l;
        while(l->r != NULL)
            l = l->r;
        l->val += node->l->val;
    }

    // ---
    while (r->depth > 0 && r->parent->r == r)
        r = r->parent;
    if (r->depth > 0) {
        r = r->parent->r;
        while(r->l != NULL)
            r = r->l;
        r->val += node->r->val;
    }

    node->val = 0;
    delete node->l;
    delete node->r;

    node->l = NULL;
    node->r = NULL;
}
void split(Node* node) {
    int lVal = node->val / 2;
    int rVal = node->val / 2 + node->val % 2;

    node->val = -1;
    node->l = newNode(lVal, node, node->depth + 1);
    node->r = newNode(rVal, node, node->depth + 1);
}

bool reduce(Node* tree) {
    if (tree == NULL)
        return false;

    if (tree->depth > 4 && tree->l == NULL && tree->r == NULL) {
        explode(tree->parent);
        return true;
    }
    if (tree->val > 9) {
        split(tree);
        return true;
    }

    if (reduce(tree->l))
        return true;
    if (reduce(tree->r))
        return true;

    return false;
}

ll getMag(Node* tree) { 
    if (tree == NULL) return 0;

    if (tree->val >= 0)
        return tree->val;

    ll mag = 0;
    mag += 3 * getMag(tree->l);
    mag += 2 * getMag(tree->r);

    return mag;
}

void printTree(Node* tree) {
    if (tree == NULL)
        return;

    if (tree->val != -1) {
        cout << tree->val;
    }

    if (tree->val == -1)
        cout << "[";

    printTree(tree->l);

    if (tree->val == -1)
        cout << ",";
    
    printTree(tree->r);
    
    if (tree->val == -1)
        cout << "]";
}
void deinit(Node* tree) {
    if (tree == NULL) return;

    if (tree->l == NULL && tree->r == NULL)
    {
        delete tree;
        return;
    }

    if (tree->l != NULL)
        deinit(tree->l);
    if (tree->r != NULL)
        deinit(tree->r);
}

int main(int argc, char const *argv[])
{
    vector<string> lines;
    while (!cin.eof()) {
        string s;
        cin >> s;
        if (!s.empty())
            lines.push_back(s);
    }
    cout << endl;

    freopen("out.txt", "w", stdout);
    Node* tree = parse(lines[0]);
    for (int i = 1; i < lines.size(); i++)
    {
        tree = merge(tree, parse(lines[i]));
        printTree(tree);
        while(reduce(tree)) {
            printTree(tree);
            cout << endl;
        }
    }
    printTree(tree);
    cout << endl;

    cout << getMag(tree) << endl;
    
    deinit(tree);
}