#include <iostream>
#include <algorithm> 
#include <iomanip> 
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
struct tabdat
{
public:
    int pid, AT, BT, RT, TAT, WT, CT, priority, timequant;
    tabdat(int pi, int A, int B)
    {
        pid = pi;
        AT = A;
        BT = B;
        RT = -1;
    }
};
struct process
{
    int pid = 0;
    int round_time = 0;
    int burst_time = 0;
    int start_time = 0;
    int completion_time = 0;
    int turnaround_time = 0;
    int waiting_time = 0;
    int response_time = -1;
    int Priorityrity = -1;
};

vector<tabdat> arr;
int n, TimeQuantum;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

bool compareP(process &a, process &b)
{
    if (a.Priorityrity == b.Priorityrity)
    {
        if (a.round_time == b.round_time)
            return a.pid - b.pid;
        return a.round_time - b.round_time;
    }
    return a.Priorityrity < b.Priorityrity;
}

int position(int *at,int size,int x){ 
    for(int i=0;i<size;i++){ 
        if(at[i]==x){ 
            return i;
        }
    }

} 

void FirstComeFirstServe(int at[], int bt[], int np) {
    int wt[np];
    wt[0]=0;
    int tat[np];
    int et = 0;
    float tt;
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

    // std::cout<<"Waiting times of the respective Processes is: ";
    for(int i=0;i<np;i++){ 
        std::cout<<wt[i]<<" ";
    }
    std::cout<<endl;

    // std::cout<<"Response times of the respective Processes is: ";
    for(int i=0;i<np;i++){ 
        std::cout<<wt[i]<<" ";
    }
    std::cout<<endl;

    //  std::cout<<"Turn around time of the respective Processes is: ";
     for(int i=0;i<np;i++){ 
        std::cout<<tat[i]<<" ";
     }
     std::cout<<endl;

    float n=np;
    float thp=n/tt;
     std::cout<<thp;
}

void ShortestJobFirst(int at[], int bt[], int np) {
    int wt[np];
    wt[0]=0;
    int tat[np];
    int et = 0;
    float tt;
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
        // std::cout<< et<<'\n';
        int fiT[np];
        fiT[0] = et;
        while(iterate<np-1){ 
            val=position(at,np,s_at[iterate]);
            et+=s_bt[iterate];
            fiT[val] = et;
            //std::cout<< et<<'\n';
            // tat[val]=et-at[iterate];
            // wt[val]=tat[val]-bt[iterate];
            iterate++;
        }
        tt=et;
        for(int i=0; i<np; i++){
            tat[i] = fiT[i] -at[i];
            wt[i]=tat[i]-bt[i];
        }
        // std::cout<<"Waiting times of the respective Processes is: ";
        std::cout<<"";
        for(int i=0;i<np;i++){ 
            std::cout<<wt[i]<<" ";
        }
        std::cout<<endl;

        // std::cout<<"Response times of the respective Processes is: ";
        std::cout<<"";
        for(int i=0;i<np;i++){ 
            std::cout<<wt[i]<<" ";
        }
        std::cout<<endl;

        std::cout<<"";
        // std::cout<<"Turn around time of the respective Processes is: ";
        for(int i=0;i<np;i++){ 
            std::cout<<tat[i]<<" ";
        }
        std::cout<<endl;

        float n=np;
        float thp=n/tt;
        std::cout<<"Throughput: "<<thp;
}

void ShortestRemainingJobFirst()
{
    struct process p[100];
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));

    std::cout << setprecision(4) << fixed;

    for (int i = 0; i < n; i++)
    {
        p[i].pid = arr[i].pid;
        p[i].round_time = arr[i].AT;
        p[i].burst_time = arr[i].BT;
        burst_remaining[i] = p[i].burst_time;
    }

    int roundient_time = 0;
    int completed = 0;
    int prev = 0;

    while (completed != n)
    {
        int idx = -1;
        int mn = 10000000;
        for (int i = 0; i < n; i++)
        {
            if (p[i].round_time <= roundient_time && is_completed[i] == 0)
            {
                if (burst_remaining[i] < mn)
                {
                    mn = burst_remaining[i];
                    idx = i;
                }
                if (burst_remaining[i] == mn)
                {
                    if (p[i].round_time < p[idx].round_time)
                    {
                        mn = burst_remaining[i];
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1)
        {
            if (burst_remaining[idx] == p[idx].burst_time)
            {
                p[idx].start_time = roundient_time;
                total_idle_time += p[idx].start_time - prev;
            }
            burst_remaining[idx] -= 1;
            roundient_time++;
            prev = roundient_time;

            if (burst_remaining[idx] == 0)
            {
                p[idx].completion_time = roundient_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].round_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
                p[idx].response_time = p[idx].start_time - p[idx].round_time;

                total_turnaround_time += p[idx].turnaround_time;
                total_waiting_time += p[idx].waiting_time;
                total_response_time += p[idx].response_time;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else
        {
            roundient_time++;
        }
    }

    int min_round_time = 10000000;
    int max_completion_time = -1;
    for (int i = 0; i < n; i++)
    {
        min_round_time = min(min_round_time, p[i].round_time);
        max_completion_time = max(max_completion_time, p[i].completion_time);
    }

   
    throughput = float(n) / (max_completion_time - min_round_time);

    for (int i = 0; i < n; i++)
        std::cout << p[i].waiting_time << " ";
    std::cout << endl;
    for(int i=0;i<n;i++)
    std::cout << p[i].response_time << " ";
    std::cout << endl;
    for(int i=0;i<n;i++)
    std::cout << p[i].turnaround_time << " ";
    std::cout << endl;
    std::cout << throughput << endl;
}
void Priority()
{
    vector<process> p;
    for (int i = 0; i < n; i++)
    {
        process input;
        input.pid = i + 1;
        input.round_time = arr[i].AT;
        input.burst_time = arr[i].BT;
        input.Priorityrity = arr[i].priority;
        p.push_back(input);
    }

    vector<process> put_in_queue;
    int time = 0;
    vector<process> gantt;
    int k = 0;

    int flag = 0;
    while (flag != (int)p.size())
    {
        if (time < p[k].round_time && put_in_queue.empty())
        {
            time++;
            gantt.push_back(process());
            continue;
        }
        while (k != (int)p.size() && time == p[k].round_time)
        {
            put_in_queue.push_back(p[k]);
            k++;
        }
    
        sort(put_in_queue.begin(), put_in_queue.end(), compareP);
        put_in_queue[0].burst_time -= 1;
        if (p[put_in_queue[0].pid - 1].response_time == -1)
            p[put_in_queue[0].pid - 1].response_time = time;
        gantt.push_back(put_in_queue[0]);
        time++;
        if (put_in_queue[0].burst_time == 0)
        {
            p[put_in_queue[0].pid - 1].completion_time = time;
            put_in_queue.erase(put_in_queue.begin());
            flag++;
        }
    }

    for (int i = 0; i < (int)p.size(); i++)
    {
        p[i].turnaround_time = p[i].completion_time - p[i].round_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        p[i].response_time = p[i].response_time - p[i].round_time;
    }

    for (int i = 0; i < (int)p.size(); i++)
    {
        std::cout << p[i].waiting_time << " ";
    }
    std::cout << endl;

    for (int i = 0; i < (int)p.size(); i++)
    {
        std::cout << p[i].response_time << " ";
    }
    std::cout << endl;

    for (int i = 0; i < (int)p.size(); i++)
    {
        std::cout << p[i].turnaround_time << " ";
    }
    std::cout << endl;
    std::cout << setprecision(4) << (float)(p.size()) / gantt.size() << endl;
}
bool compare1(process p1, process p2)
{
    return p1.round_time < p2.round_time;
}

bool compare2(process p1, process p2)
{
    return p1.pid < p2.pid;
}
void RoundRobin()
{
    struct process p[100];
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int burst_remaining[100];
    int idx;

    std::cout << setprecision(4) << fixed;

    for (int i = 0; i < n; i++)
    {
        p[i].pid = arr[i].pid;
        p[i].round_time = arr[i].AT;
        p[i].burst_time = arr[i].BT;
        burst_remaining[i] = p[i].burst_time;
    }

    sort(p, p + n, compare1);

    queue<int> q;
    int roundient_time = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;

    while (completed != n)
    {
        idx = q.front();
        q.pop();

        if (burst_remaining[idx] == p[idx].burst_time)
        {
            p[idx].start_time = max(roundient_time, p[idx].round_time);
            total_idle_time += p[idx].start_time - roundient_time;
            roundient_time = p[idx].start_time;
        }

        if (burst_remaining[idx] - TimeQuantum > 0)
        {
            burst_remaining[idx] -= TimeQuantum;
            roundient_time += TimeQuantum;
        }
        else
        {
            roundient_time += burst_remaining[idx];
            burst_remaining[idx] = 0;
            completed++;

            p[idx].completion_time = roundient_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].round_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            p[idx].response_time = p[idx].start_time - p[idx].round_time;

            total_turnaround_time += p[idx].turnaround_time;
            total_waiting_time += p[idx].waiting_time;
            total_response_time += p[idx].response_time;
        }

        for (int i = 1; i < n; i++)
        {
            if (burst_remaining[i] > 0 && p[i].round_time <= roundient_time && mark[i] == 0)
            {
                q.push(i);
                mark[i] = 1;
            }
        }
        if (burst_remaining[idx] > 0)
        {
            q.push(idx);
        }

        if (q.empty())
        {
            for (int i = 1; i < n; i++)
            {
                if (burst_remaining[i] > 0)
                {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }


    throughput = float(n) / (p[n - 1].completion_time - p[0].round_time);

    sort(p, p + n, compare2);

    for (int i = 0; i < n; i++)
        std::cout << p[i].waiting_time << " ";
    std::cout << endl;
    for(int i=0;i<n;i++)
    std::cout << p[i].response_time << " ";
    std::cout << endl;
    for(int i=0;i<n;i++)
    std::cout << p[i].turnaround_time << " ";
    std::cout << endl;
    std::cout << throughput << endl;
}
int main()
{


    int p;
    cin >> p;
    cin >> n;
    int AT[n];
    for(int i=0;i<n;i++)
    cin >> AT[i];
    int BT[n];
    for(int i=0;i<n;i++)
    cin >> BT[i];
    for(int i=0;i<n;i++)
    {
        arr.push_back(tabdat(i + 1, AT[i], BT[i]));
    }
    switch (p)
    {
    case 1:
        FirstComeFirstServe(AT, BT, n);
        break;
    case 2:
        ShortestJobFirst(AT, BT, n);
        break;
    case 3:
        ShortestRemainingJobFirst();
        break;
    case 4:
        for (int i = 0; i < n; i++)
            cin >> arr[i].priority;
        Priority();
        break;
    case 5:
        cin >> TimeQuantum;
        RoundRobin();
        break;
    }
}