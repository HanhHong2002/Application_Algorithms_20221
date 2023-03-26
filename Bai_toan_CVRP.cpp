#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 20;
const int MAX_K = 10;
int N; // so khach hang
int K; // so xe tai
int Q; // trong tai cua xe tai
int d[MAX_N]; //d[v] luong hang yeu cau boi khach hang v
int y[MAX_K]; // y[k] la diem khach hang dau tien trong lo trinh cua xe thu k
int x[MAX_K]; // x[v] la diem tiep theo cua diemr v
bool visisted[MAX_N]; // danh dau 1 diem da duoc thawm hay chua
int load[MAX_N]; //load[k] ghi nhan hang hoa cua cac khach hang tren lo trinh cua xe thu k
int seg;
void solution(){
    for (int k = 1; k <= K;k++){
        cout << "Route [" << k << "]: 0";
        int v = y[k];
        while (v >0){
            cout << " - " << v;
            v = x[v];
        }
        cout << " - 0" << endl;

    }
    cout << "----------------------------------------------------------------"<< endl;
}
bool checkX(int v,int u, int k){
    if (v == 0) return true;
    if (visisted[v] == true) return false;
    if (load[k] + d [v] > Q) return false;
    return true;
}
void TryX(int u, int k){
    // kiem tra tat ca cac gtri cua x trong lo trinh k
    for (int v = 0; v <= N;v++){
        if (checkX(v,u,k)){
            x[u] = v;
            visisted[v] = true;
            load[k] += d[v];
            seg ++;
            if (v  == 0){
                if (k == K){
                    if (seg == N+K)
                    solution();
                }
                else{
                    TryX(y[k+1], k+1);

                }
            } else {
                TryX(v,k);
            }
            visisted[v] = false;
            load[k] -= d[v];
            seg --;
        }
    }

}
bool checkY(int v, int k){
    if (visisted[v] == true) return false; // v da nam tren lo trinh
    if (load[k] + d[v] > Q) return false; // neu luong hang da giao truoc do + so hang can giao tai v > tai trong xe
    return true;
}
void TryY(int k){
// Thu gia tri cho y[k], y[1] < y[2] < y[3]...
for (int v = y[k-1] + 1; v <= N;v++){
    if (checkY(v,k)){
        y[k] = v;
        load[k] += d[v];
        visisted[v]= true;
        seg ++;
        if (k == K){
            TryX(y[1], 1);
        }else {
            TryY(k+1);
        }
        load[k] -= d[v];
        visisted[v] = false;
        seg --;
    }
}

} 
int main (){
    cin >> N >> K >> Q;
    for (int i = 1; i <= N;i++ ){
         cin >> d[i];
    }
    for (int i = 1;i <= N;i ++){
        visisted[i] = false;
    }
    for (int k = 1;k <= K;k ++) load[k] = 0;
    seg = 0;
    y[0] = 0;
    TryY(1);
    solution();

    return 0;
}
