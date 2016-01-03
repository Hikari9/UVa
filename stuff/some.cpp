const int N = 100001;
 
VI Q[N], ID[N];
// 询问..
 
int A[N]; LL B[N]; int n, m, a, b; LL d;
// A[] 存初始数组，B[] 存答案, a, b 表示询问区间。
 
LL K[4*N], D[4*N], KK[4*N], DD[4*N];
// 线段树，单点加减，区间成段最值 -> 成段加减，区间最值
// 当前的最大值，延迟标记，历史最大值，历史延迟标记。
 
int ____[N], Hash[N];
 
#define root 1, 1, n
#define lx (x << 1)
#define rx (lx | 1)
#define lc lx, l, m
#define rc rx, m+1, r
 
#define Update KK[x] = max(max(KK[lx], K[lx] + DD[lx]), max(KK[rx], K[rx] + DD[rx])), K[x] = max(K[lx] + D[lx],  K[rx] + D[rx])
#define Release checkMax(DD[lx], D[lx] + DD[x]), checkMax(DD[rx], D[rx] + DD[x]), D[lx] += D[x], D[rx] += D[x], DD[x] = -INF, D[x] = 0
 
void Insert(int x, int l, int r){
    if (a <= l && r <= b){
        D[x] += d, checkMax(DD[x], D[x]);
    }
    else {
        int m = (l + r) >> 1; Release;
        if (a <= m) Insert(lc); if (m < b) Insert(rc); Update;
    }
}
 
LL Query(int x, int l, int r){
    if (a <= l && r <= b){
        return max(KK[x], K[x] + DD[x]);
    }
    else {
        int m = (l + r) >> 1; Release, Update;
        return max((a <= m ? Query(lc) : -INF), (m < b ? Query(rc) : -INF));
    }
}
 
int main(){
 
    //freopen("in.txt", "r", stdin);
 
    REP_1_C(i, _RD(n)) RD(A[i]);
 
    REP_C(i, _RD(m)) RD(a, b), Q[b].PB(a), ID[b].PB(i);
 
    REP_1_N(b, n){
 
        a = Hash[A[b]] + 1, d = A[b], Insert(root), Hash[d] = b;
 
        REP(i, SZ(Q[b])){
            a = Q[b][i], B[ID[b][i]] = Query(root);
        }
    }
 
    REP(i, m) OT(B[i]);
}