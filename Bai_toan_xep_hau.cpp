// #include<bits/stdc++.h>
// using namespace std;
// int n = 4;
// int Row[1000001];
// bool bCol[1000001],bDiag1[1000001] ,bDiag2[1000001] ;// kiểm tra xem có quân hậu nào trùng cột/ đường chéo hay không; Nếu trùng == false, không trùng == true

// void Try (int i){
//     for (int j = 1; j <= n; j ++){ 
//     if (bCol[j] && bDiag1[i+j] && bDiag2[i-j]){
//       Row[i] = j;
//       bCol[j] = false;
//       bDiag1[i+j] = false;
//       bDiag2[i-j] = false;
//       if(i == n){
//         for (int k = 1; k <= n; k ++){
//             cout << Row[k] <<" ";
//         }
//         cout <<endl;

//       }
//       else Try(i+1);
//       bCol[j] = true;
//       bDiag1[i+j] = true;
//       bDiag2[i-j] = true;

//     }
//     }
// }
// int main(){
//     for (int i = 1; i <= n;i ++){
//         bCol[i] = true;
//         bDiag1[i] = true;
//         bDiag2[i] = true;
//     }
//     Try(1);
//     return 0;
// }

#include<bits/stdc++.h>
int a[20];
bool Ok(int x2,int y2){
	//kiểm tra cách đặt có thỏa mãn không
	for(int i = 1; i < x2 ;i++)
		if(a[i] == y2 || abs(i-x2) == abs(a[i] - y2) )
			return false;
	//Nếu kiểm tra hết các trường hợp vẫn không sai thì trả về true
	return true;
}

void Xuat(int n){
	//in ra một kết quả
	for(int i=1;i<=n;i++)
		printf(" %d",a[i]);
	printf("\n");
}

void Try(int i,int n){
	for(int j = 1;j<=n;j++){
		// thử đặt quân hậu vào các cột từ 1 đến n
		if(Ok(i,j)){
			//nếu cách đặt này thỏa mãn thì lưu lại vị trí
			a[i] = j;
                        //nếu đặt xong quân hậu thứ n thì xuất ra một kết quả
			if(i==n) Xuat(n);
			Try(i+1,n);
		}
	}
}

int main(){
	int n = 8;// ở đây mình cho bài toán là 8 quân hậu trên bàn 8*8
	Try(1,n);
	return 0;
}