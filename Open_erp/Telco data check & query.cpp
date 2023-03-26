#include<bits/stdc++.h>

using namespace std;

struct callData{
    string from_number;
    string to_number;
    string date;
    string from_time;
    string to_time;
};
    callData calls[200000];
    int i=0;

int check_number(string a){
    if(a.length()!=10) return 0;
    for(int k=0;k<10;k++){
        if(a[k]<'0'||a[k]>'9') return 0;
    }
    return 1;
}


void number_calls_from(string a){
    int count=0;
    for(int k=0;k<i;k++){
        if(a==calls[k].from_number){
            count++;
        }
    }
    cout << count <<endl; 
}

int count_time(string a,string b){
    int start_time=36000*(a[0]-'0')+3600*(a[1]-'0')+600*(a[3]-'0')+60*(a[4]-'0')+10*(a[6]-'0')+(a[7]-'0');
    int end_time=36000*(b[0]-'0')+3600*(b[1]-'0')+600*(b[3]-'0')+60*(b[4]-'0')+10*(b[6]-'0')+(b[7]-'0');
    
    return (end_time-start_time) == 0 ? 1 : end_time-start_time;
}

void count_time_calls_from(string b){
    int total_calls_time=0;
    for(int k=0;k<i;k++){
        if(calls[k].from_number==b){
            total_calls_time+=count_time(calls[k].from_time,calls[k].to_time);
        }
    }
    cout << total_calls_time << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    string b;
    map<string,int> y;
    map<string,int> z;
    bool x=true;
    while(1){
        cin >> a;
        if(a=="call"){
            cin >> b;
            calls[i].from_number=b;
            cin >> b;
            calls[i].to_number=b;
            if(check_number(calls[i].from_number) !=1 || check_number(calls[i].to_number) !=1){
                cin >> b;
                cin >> b;
                cin >> b;
                x=false;
                continue;
            }
            cin >> b;
            //calls[i].date=b;
            cin >> b;
            calls[i].from_time=b;
            cin >> b;
            calls[i].to_time=b;
            if(y.find(calls[i].from_number)!=y.end()){
                y[calls[i].from_number]+=count_time(calls[i].from_time,calls[i].to_time);
            }else{
                y[calls[i].from_number]=count_time(calls[i].from_time,calls[i].to_time);
            }
            if(z.find(calls[i].from_number)!=z.end()){
                z[calls[i].from_number]++;
            }else{
                z[calls[i].from_number]=1;
            }
            i++;
        }else break;
    }
    while(1){
        cin >> a;
        if(a=="?check_phone_number"){
            if(x==true){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }else if(a=="?number_calls_from"){
            cin >> b;
            cout << z[b] << endl;
            //number_calls_from(b);
        }else if(a=="?number_total_calls"){
            cout << i << endl;
        }else if(a=="?count_time_calls_from"){
            cin >> b;
            cout << y[b] << endl;
        }
        if(a=="#") break;
    }
    return 0;
}
