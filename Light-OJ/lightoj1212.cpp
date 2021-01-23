#include<bits/stdc++.h>

using namespace std;


void clear_stack(stack<int>&s){
    while(!s.empty())
        s.pop();
}

void exchange(stack<int>&s , stack<int>&temp){
    int t;
    while(!s.empty()){
        t = s.top();
        s.pop();
        temp.push(t);
    }
}

int pop_top(stack<int>& s){

    stack<int>temp;
    exchange(s,temp);
    int ret = temp.top();
    temp.pop();
    exchange(temp,s);

    return ret;
}

int main(){

    stack<int>left;
    stack<int>right;

    int t , n , m ,data , stack_size;
    string str;

    scanf("%d",&t);

    for( int i=1 ; i<=t ; i++){

        printf("Case %d:\n",i);
        scanf("%d %d",&n,&m);
        stack_size = 0;

        while(m--){
            cin>>str;

            if(str=="pushLeft"){
                scanf("%d",&data);
                if(stack_size>=n)
                    printf("The queue is full\n");
                else{
                    left.push(data);
                    stack_size++;
                    printf("Pushed in left: %d\n",data);
                }
            }

            else if(str=="pushRight"){
                scanf("%d",&data);
                if(stack_size>=n)
                    printf("The queue is full\n");
                else{
                    right.push(data);
                    stack_size++;
                    printf("Pushed in right: %d\n",data);
                }
            }

            else if(str=="popLeft"){
                if(stack_size<=0)
                    printf("The queue is empty\n");
                else if(left.size()==0){
                    data = pop_top(right);
                    printf("Popped from left: %d\n",data);
                    stack_size--;
                }
                else{
                    printf("Popped from left: %d\n",left.top());
                    left.pop();
                    stack_size--;
                }
            }

            else if(str=="popRight"){
                if(stack_size<=0)
                    printf("The queue is empty\n");
                else if(right.size()==0){
                    data = pop_top(left);
                    printf("Popped from right: %d\n",data);
                    stack_size--;
                }
                else{
                    printf("Popped from right: %d\n",right.top());
                    right.pop();
                    stack_size--;
                }
            }
        }

        clear_stack(left);
        clear_stack(right);
    }
}
