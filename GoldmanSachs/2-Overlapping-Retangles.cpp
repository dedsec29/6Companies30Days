class Solution {
  public:
    bool intersects(int a,int b,int x,int y) {
        bool r1 = (a <= x && x <= b) || (a <= y && y <= b);
        bool r2 = (x <= a && a <= y) || (x <= b && b <= y);
        return r1 || r2;
    }
  
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        return intersects(R1[1],L1[1],R2[1],L2[1]) & intersects(L1[0],R1[0],L2[0],R2[0]);
    }
};