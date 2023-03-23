#include <iostream>
#include <iomanip>

using namespace std;

void RodCut(int p[], int n){
    int *r = (int *)malloc((n+1)*sizeof(int)); //紀錄販售長度為i的rod獲得之最大收入
    int *c = (int *)malloc((n+1)*sizeof(int)); //紀錄長度i的rod最佳切點
    
    r[0]=0;
    c[0]=0;
    //int priceSize = 10;
    for(int j=1;j<=n;j++){
        int s = 0;
        for(int i=1;i<=j;i++){
                if(s<p[i]+r[j-i]){
                    s = p[i]+r[j-i];
                    c[j]=i; //更新最佳切點
                }           
        }
        r[j]=s;
    }

    //輸出表
    cout << setw(3) << "i" << "|" << setw(5) << "p[i]" << "|" << setw(5) << "r[i]" << "|" << setw(5) << "c[i]" << endl;
    cout << "-----------------------\n";
    for(int i=0;i<n+1;i++){
        cout << setw(3) << i << "|";
        if(i<=10){
            cout << setw(5) << p[i] << "|";
        }else{
            cout << setw(5) << "None" << "|";   
        }
        cout << setw(5) << r[i] << "|";
        cout << setw(5) << c[i] << endl;
    }
}

int main(){
    int rodPrice[11] = {0,1,3,8,8,9,10,18,18,23,25};
    RodCut(rodPrice,10);    
}