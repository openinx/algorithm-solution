#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct _node{
    int key;
    struct _node* forward[1];
}node;

class SkipList{
public:
    SkipList(){
        head = newNode(MAX_LEVEL, 0 );
        level = 1 ;
    }
    ~SkipList(){
        deleteNode(head);
    }

private:
    node* newNode(int level, int key){
        node* nd = (node*)malloc(sizeof(node) + level * sizeof(node*));
        nd->key = key;
        for(int i = 0 ; i < level; ++ i){
            nd->forward[i] = NULL;
        }
        return nd;
    }

    void deleteNode(node *nd){
        free(nd);
    }

    static int randomLevel(){
        int level = 1 ;
        while(rand() & 0xFFFF < (0.5 * 0xFFFF)){
            level += 1;
        }
        return level < MAX_LEVEL ? level: MAX_LEVEL;
    }

    void insert(int key){
        node *update[MAX_LEVEL];
        node *nd = head ; 
        for(int i = level - 1 ; i >= 0 ; -- i){
            while(nd->forward[i] != NULL && nd->forward[i]->key < key)
                nd = nd->forward[i];
            update[i] = nd;
        }
        int curlvl = randomLevel();
        if(curlvl > level){
            for(int i = level; i < curlvl ; ++ i){
                update[i] = head ;
            }
            level = curlvl;
        }
        nd = newNode(level, key);
        for(int i = 0 ; i < level; ++ i){
            nd->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = nd;
        }
    }

    node* find(int key){
        node *nd = head;
        for(int i = level - 1 ; i >= 0 ; -- i){
            while(nd->forward[i] != NULL ){
                if(nd->forward[i]->key < key){
                    nd = nd->forward[i];
                }else if(nd->forward[i]->key == key){
                    return nd->forward[i];
                }else break;
            }
        }
        return NULL;
    }

    void remove(int key){
        node *update[MAX_LEVEL];
        node *nd = head;
        for(int i = level -1 ; i >= 0 ; -- i){
            while(nd->forward[i]!= NULL && nd->forward[i]->key < key)
                nd = nd->forward[i];
            update[i] = nd;
        }
        nd = nd->forward[0];
        if(nd && nd->key == key){
            for(int i = 0 ; i < level ; ++ i){
                if(update[i]->forward[i] == nd){
                    update[i]->forward[i] = nd->forward[i];
                }
            }
        }
        for(int i = level-1 ; i>= 0 ; --i){
            if(head->forward[i] == NULL){
                level -- ;
            }
        }
        deleteNode(nd);
    }

private:
    const static int MAX_LEVEL = 8 ;
    int level;
    node *head;
};

int main(){
    return 0 ;
}
