#include <bits/stdc++.h>
using namespace std;

struct BinNode {
    int key;
    int degree;
    BinNode *sib, *parent, *child;

    BinNode() {
        this->key = 0;
        this->degree = 0;
        this->sib = this->parent = this->child = NULL;
    }
    BinNode(int key) {
        this->key = key;
        this->degree = 0;
        this->sib = this->parent = this->child = NULL;
    }
};
class BinHeap {
private:
    BinNode *roots;
    BinNode *min;
public:
    BinHeap(){this->roots = NULL;}
    BinHeap(BinNode *x){this->roots = x;}
    bool isEmpty(){return (this->roots == NULL);}
    void insert(BinNode *x){this->merge(new BinHeap(x));}
    BinNode* first(){return this->min;}
    void Delete(BinNode *x){
        decreaseKey(x, INT_MIN);
        extractMin();
    }
    void linkTrees(BinNode *y, BinNode *z) {
        y->parent = z;
        y->sib = z->child;
        z->child = y;
        z->degree = z->degree + 1;
    }
    void merge(BinHeap *bh) {
        BinHeap *H = new BinHeap();
        H->roots = mergeRoots(this, bh);

        if (H->roots == NULL){
            this->roots = NULL;
            this->min = NULL;
            return;
        }

        BinNode *prevX = NULL;
        BinNode *x = H->roots;
        BinNode *nextX = x->sib;
        while (nextX != NULL) {
            if (x->degree != nextX->degree || (nextX->sib != NULL && nextX->sib->degree == x->degree)) {
                prevX = x;
                x = nextX;
            }else if (x->key <= nextX->key){
                x->sib = nextX->sib;
                linkTrees(nextX, x);
            }else {
                if (prevX == NULL)H->roots = nextX;
                else prevX->sib = nextX;
                linkTrees(x, nextX);
                x = nextX;
            }
            nextX = x->sib;
        }
        
        this->roots = H->roots;
        this->min = H->roots;
        BinNode *cur = this->roots;
        while (cur != NULL) {
            if (cur->key < this->min->key) this->min = cur;
            cur = cur->sib;
        }
    }
    BinNode* mergeRoots(BinHeap *x, BinHeap *y) {
        BinNode *ret = new BinNode();
        BinNode *end = ret;

        BinNode *L = x->roots;
        BinNode *R = y->roots;
        if (L == NULL) return R;
        if (R == NULL) return L;
        while (L != NULL || R != NULL) {
            if (L == NULL) {
                end->sib = R;
                end = end->sib;
                R = R->sib;
            }else if (R == NULL) {
                end->sib = L;
                end = end->sib;
                L = L->sib;
            }else {
                if (L->degree < R->degree) {
                    end->sib = L;
                    end = end->sib;
                    L = L->sib;
                }
                else {
                    end->sib = R;
                    end = end->sib;
                    R = R->sib;
                }
            }
        }
        return (ret->sib);
    }
    BinNode* extractMin() {
        BinNode *ret = this->first();
        BinNode *prevX = NULL;
        BinNode *x = this->roots;
        while (x != ret) {
            prevX = x;
            x = x->sib;
        }
        if (prevX == NULL)this->roots = x->sib;
        else prevX->sib = x->sib;

        BinNode *revChd = NULL;
        BinNode *cur = ret->child;
        while (cur != NULL) {
            BinNode *next = cur->sib;
            cur->sib = revChd;
            revChd = cur;
            cur = next;
        }
        BinHeap *H = new BinHeap();
        H->roots = revChd;
        this->merge(H);
        return ret;
    }

    void decreaseKey(BinNode *x, int newKey) {
        x->key = newKey;
        BinNode *y = x;
        BinNode *z = y->parent;
        while (z != NULL && y->key < z->key) {
            swap(y->key, z->key);
            y = z;
            z = y->parent;
        }
        if (y->key < this->min->key) this->min = y;
    }
};
int main() {
    BinHeap *bh = new BinHeap();
    BinNode *x = new BinNode(14);
    BinNode *y = new BinNode(11);

    bh->insert(x);
    bh->insert(y);
    bh->insert(new BinNode(13));
    bh->insert(new BinNode(20));
    bh->insert(new BinNode(43));

    bh->decreaseKey(x, 2);
    while (!bh->isEmpty())printf("%d ", bh->extractMin()->key);
}
