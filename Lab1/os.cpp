#include <iostream> 
#include<algorithm>
#include<queue>

using namespace std;

class Process_RR
{
   int at;
   int bt;
   int pid;
   int rem_time;
public:
   Process_RR(int at, int bt ,int pid, int rem_time)
   {
      this->at = at;
      this->bt = bt;
      this->pid = pid;
      this->rem_time = rem_time;
   }
   int getAT() const { return at;}
   int getBT() const { return bt;}
   int getPID() const {return pid;}
   int getRT() const {return rem_time;}

};


class Compare_BT_RR
{
public:
    int operator() (const Process_RR& p1, const Process_RR& p2)
    {
        return p1.getBT() > p2.getBT();
    }
};


bool sort_AT_RR(const Process_RR& p1, const Process_RR& p2)
{
    return p1.getAT() < p2.getAT();
}



int position(int *at,int size,int x){ 
    for(int i=0;i<size;i++){ 
        if(at[i]==x){ 
            return i;
        }
    }

} 

int search(int *checked,int size,int x){ 
    int flag=0;
    for(int i=0;i<size;i++){ 
        if(x==checked[i]){ 
            flag++;
            return flag;
        }
    }
    return flag;
}

int min_value(int *priority,int size,int *checked,int size_checked){ 
    int index=999999;
    int low=9999999;

    for(int i=0;i<size;i++){ 
        if(checked[i]==0){ //should check if its checked or not
            continue;

        }
        else{ 
            if(priority[i]<low){ 
                index=i;
                low=priority[i];
            }
        }
    }
    return index;

}

int main(){ 

    int sc;
    int np;
    cout<<"Please choose the scheduling algorithm\n"; 
    cout<<"1-FCFS\n2-Shortest-job first\n3-Shortest remaining time first\n4-Priority scheduling\n5-Round-Robin scheduling: \n";
    cin>>sc;
    cout<<sc; 
    cout<<"Enter the Number of Processes: ";
    cin>>np; 

    int at[np];
    int bt[np];
    cout<<"Please Enter Arrival Time: \n";
    for(int i=0;i<np;i++){ 
        cin>>at[i];
    }
    cout<<"Please Enter Burst Time: \n";
    for(int i=0;i<np;i++){ 
        cin>>bt[i];
    }  

    int wt[np];
    int rp[np];
    int tat[np];
    float thp; 
    float tt; 
    //for the exit time
    int et=0;

    if(sc==1){   
        wt[0]=0;
        et=bt[0]+at[0];
        tat[0]=et-at[0];
        int index=1;
        while(index<np){ 
            if(at[index]>et){ 
                et=et+(index-et);
            }
            et+=bt[index];
            tat[index]=et-at[index];
            wt[index]=tat[index]-bt[index];
            index++;
        }
    //total time is the exit time in the end
        tt=et;  
    } 


    else if(sc==2){  
        wt[0]=0;
        et=bt[0]+at[0];
        tat[0]=et-at[0];
        int index=1; 
  
        int c=1;
        int s_bt[np-1];
        int s_at[np-1];
        for(int i=0;i<np-1;i++){ 
            s_bt[i]=bt[c];
            s_at[i]=at[c];
            c++; 
        }

        int temp=0;
        int at_temp=0;
        for(int i=0;i<np-1;i++){ 
            for(int j=i+1;j<np-1;j++){ 
                if(s_bt[i]>s_bt[j]){ 
                    at_temp=s_at[i];
                    s_at[i]=s_at[j];
                    s_at[j]=at_temp;

                    temp=s_bt[i];
                    s_bt[i]=s_bt[j];
                    s_bt[j]=temp;
                }
            }
        }
        

        int iterate=0;
        int val=0;
        // cout<< et<<'\n';
        int fiT[np];
        fiT[0] = et;
        while(iterate<np-1){ 
            val=position(at,np,s_at[iterate]);
            et+=s_bt[iterate];
            fiT[val] = et;
            //cout<< et<<'\n';
            // tat[val]=et-at[iterate];
            // wt[val]=tat[val]-bt[iterate];
            iterate++;
        }
        tt=et;
        for(int i=0; i<np; i++){
            tat[i] = fiT[i] -at[i];
            wt[i]=tat[i]-bt[i];
        }
    }
    

    else if(sc==3){ 

    } 

    else if(sc==4){ 
        int pt[np];
        cout<<"Please enter the priority list: ";
        for(int i=0;i<np;i++){ 
            cin>>pt[i];
        } 
        // int checked[np];
        // int checked_index[np];
        // int size_checkedindex=0;
        // for(int i=0;i<np;i++){ 
        //     checked[i]=min_value(pt,np,checked,size_checkedindex);
        //     et+=bt[checked[i]];
        //     size_checkedindex+=1;
        //     tat[i]=et-at[checked[i]];
        // }
        // for(int i=0;i<np;i++){ 
        //     wt[i]=tat[checked[i]]-bt[i];
        // }
        // tt=et;
        for(int i = 0; i<np; i++) {
            cout<<wt[i] << " ";
        }
        cout << endl;
        wt[0]=0;
        et=bt[0]+at[0];
        tat[0]=et-at[0];
        int index=1; 
  
        int c=1;
        int s_bt[np-1];
        int s_at[np-1];
        for(int i=0;i<np-1;i++){ 
            s_bt[i]=bt[c];
            s_at[i]=at[c];
            c++; 
        }

        int temp=0;
        int at_temp=0;
        for(int i=0;i<np-1;i++){ 
            for(int j=i+1;j<np-1;j++){ 
                if(pt[i]>pt[j]){ 
                    at_temp=s_at[i];
                    s_at[i]=s_at[j];
                    s_at[j]=at_temp;

                    temp=s_bt[i];
                    s_bt[i]=s_bt[j];
                    s_bt[j]=temp;

                    temp = pt[i];
                    pt[i] = pt[j];
                    pt[j] = temp;
                }
            }
        }
        

        int iterate=0;
        int val=0;
        // cout<< et<<'\n';
        int fiT[np];
        fiT[0] = et;
        while(iterate<np-1){ 
            val=position(at,np,s_at[iterate]);
            et+=s_bt[iterate];
            fiT[val] = et;
            //cout<< et<<'\n';
            // tat[val]=et-at[iterate];
            // wt[val]=tat[val]-bt[iterate];
            iterate++;
        }
        tt=et;
        for(int i=0; i<np; i++){
            tat[i] = fiT[i] -at[i];
            wt[i]=tat[i]-bt[i];
        }

    } 

    else{  
       

    } 

    cout<<"Waiting times of the respective Processes is: ";
    for(int i=0;i<np;i++){ 
        cout<<wt[i]<<" ";
    }
    cout<<endl;

    if(sc==1 || sc==2 || sc==4){
    cout<<"Response times of the respective Processes is: ";
    for(int i=0;i<np;i++){ 
        cout<<wt[i]<<" ";
    } 
    cout<<endl;
    }
    
    else{
    cout<<"Response times of the respective Processes is: ";
    for(int i=0;i<np;i++){ 
        cout<<rp[i]<<" ";
    
    }
    cout<<endl;
    }

     cout<<"Turn around time of the respective Processes is: ";
     for(int i=0;i<np;i++){ 
        cout<<tat[i]<<" ";
     }
     cout<<endl;

    float n=np;
     thp=n/tt;
     cout<<"Throughput: "<<thp;
    
}


