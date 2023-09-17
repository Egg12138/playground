// index: 0, 1 2, 3 4 5 6, 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 32
#define isleft(i) ((i) != 0 && ((i) % 2 != 0)) 
#define layer_first_idx(l) (2 << ((l)-1) - 1)
#define layer_num(i) floor(log((i) + 1, 2) + 1)
#define parentof(i) (floor((i)))
#define not_root(i) ((i) != 0)
#define leftof(i) (2 * (i) + 1)
#define rightof(i) (leftof((i)) + 1)
//#define isvalid(i) \
        ((isleft((i))) ? \
         (tree->SqBiTNode[(i)] < tree->SqBiTNode[(parentof((i)))]) \
         : (tree->SqBiTNode[(i)] > tree->SqBiTNode[(parentof((i)))]) \
         )\


typedef struct {
        int SqBiTNode[MAX_SIZE];
        int ElemNum;
} sqbitree;

//bool wrong_version_is_bts(sqbitree *tree) {
//
        //int i = tree->ElemNum - 1;
        ////int layernum = layer_num(tree->ElemNum);  // init: that last layer        
        //for (; layernum > 1; layernum--) {
                //while ( i >= (2 << layernum - 1)) 
                        //if (!isvalid(i)) return false;
        ////}
        ////return true;
////}

static int t1[10] = {40, 25, 60, -1, 30, -1, 80, -1, -1, 27};
static int t2[11] = {40, 50, 60, -1, 30, -1, -1, -1, -1, -1, 35};

bool is_valid(int t[], int idx) {
        if (t[idx] > 0) {
                return  (t[leftof(idx)] < t[idx])
                        && (t[rightof(idx)] > t[idx])
                        && (is_valid(t, leftof(idx)))
                        && (is_valid(t, rightof(idx)));
        } else return true;
}

bool is_bts(int t[], size_t num) {
        is_valid();

}

int
main()
{
                
        return 0;
}
