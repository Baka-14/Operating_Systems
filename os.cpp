#include <iostream> 
#include <queue>

using namespace std;

int main(){ 

    int sc;
    int np;
    cout<<"Please choose the scheduling algorithim\n"; 
    cout<<"1-FCFS\n2-Shortest-job first\n3-Shortest remaining time first\n4-Priority scheduling\n5-Round-Robin scheduling: \n";
    cin>>sc;
    cout<<sc; 
    cout<<"Enter the number of processes: ";
    cin>>np; 

    int at[np];
    int bt[np];
    for(int i=0;i<np;i++){ 
        cin>>at[i];
    }

    for(int i=0;i<np;i++){ 
        cin>>bt[i];
    }  

    int wt[np];
    int rp[np];
    int tat[np];
    int thp; 
    int tt;

    if(sc==1){  
        queue<int> fcfs;
        int time=0;
        for(int i=0;i<np;i++){ 
            fcfs.push(bt[i]);
        } 

        while(!fcfs.empty()){ 
            fcfs.front() 
            
        }

        
        
    } 


    else if(sc==2){ 

    } 

    else if(sc==3){ 

    } 

    else if(sc==4){ 
        int pt[np];
        for(int i=0;i<np;i++){ 
            cin>>pt[i];
        } 

    } 

    else{  
        int tq;
        cin>>tq;


    } 
    cout<<"Waiting times of the respective Processes is: ";
    for(int i=0;i<np;i++){ 
        cout<<wt[i]<<" ";
    }  
    cout<<"Response times of the respective Processes is: ";
    for(int i=0;i<np;i++){ 
        cout<<rp[i]<<" ";
    } 
    cout<<"Turn around time of the respective Processes is: ";
    for(int i=0;i<np;i++){ 
        cout<<tat[i]<<" ";
    }

    thp=np/tt;
    cout<<"Throughput: "<<thp;
    
}

