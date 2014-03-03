#include <stdio.h>
#include <string.h>

#define MAXV  501

int map[MAXV][MAXV];
int reminder[MAXV];
int send[MAXV];
int back[MAXV];
int times[MAXV];
int flag[MAXV];
int path[MAXV][MAXV];

int findMinTimesPoint(int);
int main()
{
    int Cmax,N,Sp,M,s,e,i;
    while(scanf("%d%d%d%d",&Cmax,&N,&Sp,&M) != EOF){
        for(i=1;i<=N;++i)
            scanf("%d",&reminder[i]);
        memset(map,0,sizeof(map));
        for(i=0;i<M;++i){
            scanf("%d%d",&s,&e);
            scanf("%d",&map[s][e]);
            map[e][s] = map[s][e];
        }
        memset(send,0,sizeof(send));
        memset(back,0,sizeof(back));
        memset(flag,0,sizeof(flag));
        memset(path,0,sizeof(path));
        s = 0;
        send[s] = 0;
        back[s] = 0;
        flag[s] = 1;
        path[0][0] = 1;
        path[0][1] = 0;
        for(i=1;i<=N;++i){
            times[i] = -1;
            if(map[s][i]){
                times[i] = map[s][i];
                send[i] = Cmax / 2 - reminder[i];
                if(send[i] < 0)
                    send[i] = 0;
                back[i] = reminder[i] - Cmax / 2;
                if(back[i] < 0)
                    back[i] = 0;
                path[i][0] = 2;
                path[i][1] = 0;
                path[i][2] = i;
            }
        }
        times[s] = 0;
        while(!flag[Sp]){
            s = findMinTimesPoint(N);
            flag[s] = 1;
            for(i=1;i<=N;++i){
                if(!flag[i] && map[s][i]){
                    if(times[i] == -1 || (times[i] > times[s] + map[s][i])){
                        times[i] = times[s] + map[s][i];
                        path[i][0] = path[s][0] + 1;
                        int j;
                        for(j=1;j<=path[s][0];++j)
                            path[i][j] = path[s][j];
                        path[i][j] = i;
                        int t = Cmax / 2 - reminder[i];
                        if(t == 0){
                            send[i] = send[s];
                            back[i] = back[s];
                        }
                        else if(t > 0){
                            if(t-back[s] >= 0){
                                back[i] = 0;
                                send[i] = send[s] + t - back[s];
                            }
                            else{
                                send[i] = send[s];
                                back[i] = back[s] - t;
                            }
                        }
                        else{
                            send[i] = send[s];
                            back[i] = back[s] - t;
                        } 
                    }
                    else if(times[i] == times[s] + map[s][i]){
                        int t = Cmax / 2 - reminder[i];
                        int tSend,tBack;
                        if(t==0){
                            tSend = send[s];
                            tBack = back[s];
                        }
                        else if(t > 0){
                            if(t-back[s] >= 0){
                                tBack = 0;
                                tSend = send[s] + t - back[s];
                            }
                            else{
                                tSend = send[s];
                                tBack = back[s] - t;
                            }
                        }
                        else{
                            tSend = send[s];
                            tBack = back[s] - t;
                        }
                        if(tSend < send[i] || (tSend == send[i] && tBack < back[i])){
                            send[i] = tSend;
                            back[i] = tBack;
                            path[i][0] = path[s][0] + 1;
                            int j;
                            for(j=1;j<=path[s][0];++j)
                                path[i][j] = path[s][j];
                            path[i][j] = i;
                        }
                    }
                }
            }
        }
        printf("%d %d",send[Sp],path[Sp][1]);
        for(i = 2;i<=path[Sp][0];++i){
            printf("->%d",path[Sp][i]);
        }
        printf(" %d\n",back[Sp]);
    }
    return 0;
}

int findMinTimesPoint(int n)
{
    int i = 1;
    int minPointInd;
    while(i<=n && (times[i] == -1 || flag[i]))
        ++i;
    if(i > n)
        return -1;
    minPointInd = i;
    for(;i<=n;++i){
        if(!flag[i] && times[i] != -1 && (times[i] < times[minPointInd] || 
            (times[i] == times[minPointInd] && send[i]<send[minPointInd]) ||
            (send[i]==send[minPointInd] && back[i]<back[minPointInd])))
            minPointInd = i;
    }
    return minPointInd;
}
