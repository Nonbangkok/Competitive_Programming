#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int val;
    Non* next;
};

Non* Create(int num){
    Non* node = new Non;
    node->val=num;
    node->next=NULL;
    return node;
}

const int N=1001;
Non* A[N];

int main() {macos;

    int k=1,size=0,num;
    char ch;
    Non* first;
    while(1){
        cout << "Enter command: ";
        cin >> ch;
        if(ch=='A'){
            cout << "Enter Data: ";
            cin >> num;
            A[k]=Create(num);
            if(k!=1)A[k-1]->next=A[k];
            if(!size){
                k=1;
                first=A[k];
            }
            k++;size++;
        }else if(ch=='D'){
            cout << "Enter Data: ";
            cin >> num;
            Non* head=first;
            if(head->val==num){
                first = head->next;
                delete A[1];
            }else{
                while(head!=NULL){
                    if(head->next->val==num){
                        if(head->next->next==NULL){
                            Non* backup = head->next;
                            head->next = NULL;
                            delete backup;
                            k--;
                        }else{
                            Non* backup = head->next;
                            head->next = head->next->next;
                            delete backup;
                            break;
                        }
                    }
                    head=head->next;
                }
            }
        }else if(ch=='P'){
            cout << "***Data in Link List are: ";
            Non* head=first;
            while(head!=NULL){
                cout << head->val << sp;
                head=head->next;
            }
            cout << "***" << endll;
        }else break;
    }

    return 0;
}