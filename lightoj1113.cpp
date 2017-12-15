#include<bits/stdc++.h>
using namespace std;

void distroy( stack <string> &q ){

    while(!q.empty())
        q.pop();

}

int main(){

    int tc;
    string str , temp;
    stack<string>Back;
    stack<string>Forward;

    cin>>tc;

    for(int i=1 ; i<=tc ; i++){
        printf("Case %d:\n",i);
        Back.push("http://www.lightoj.com/");

        while(true){
            cin>>str;

            if(str=="VISIT"){
                cin>>str;
                Back.push(str);
                cout<<str<<endl;
                distroy(Forward);
            }

            else if(str=="BACK"){

                if(Back.size()==1)
                    cout<<"Ignored"<<endl;
                else{
                    temp = Back.top();
                    Back.pop();
                    Forward.push(temp);
                    cout<<Back.top()<<endl;
                }
            }

            else if(str=="FORWARD"){
                if(Forward.size()==0)
                    cout<<"Ignored"<<endl;
                else{
                    temp = Forward.top();
                    Forward.pop();
                    Back.push(temp);
                    cout<<Back.top()<<endl;
                }
            }

            else if(str=="QUIT")
                break;
        }
        distroy(Back);
        distroy(Forward);
    }

    return 0;
}
