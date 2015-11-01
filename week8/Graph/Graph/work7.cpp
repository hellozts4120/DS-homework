const int  MAXINT = 10000;
const int MAXNUM = 100;
int dist[MAXNUM];
int prev[MAXNUM];

int A[MAXUNM][MAXNUM];

void Dijkstra(int v0)
{
  ����bool S[MAXNUM];                                  // �ж��Ƿ��Ѵ���õ㵽S������
      int n=MAXNUM;
  ����for(int i=1; i<=n; ++i)
 ���� {
      ����dist[i] = A[v0][i];
      ����S[i] = false;                                // ��ʼ��δ�ù��õ�
      ����if(dist[i] == MAXINT)    
            ����prev[i] = -1;
 ����     else 
            ����prev[i] = v0;
   ����}
   �� dist[v0] = 0;
   �� S[v0] = true; ����
 ���� for(int i=2; i<=n; i++)
 ���� {
       ����int mindist = MAXINT;
       ����int u = v0; ����                            // �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
      ���� for(int j=1; j<=n; ++j)
      ����    if((!S[j]) && dist[j]<mindist)
      ����    {
         ����       u = j;                             // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ��� 
         �� ��      mindist = dist[j];
       ����   }
       ����S[u] = true; 
       ����for(int j=1; j<=n; j++)
       ����    if((!S[j]) && A[u][j]<MAXINT)
       ����    {
           ��    ��if(dist[u] + A[u][j] < dist[j])     //��ͨ���¼����u��·���ҵ���v0����̵�·��  
           ��    ��{
                   ����dist[j] = dist[u] + A[u][j];    //����dist 
                   ����prev[j] = u;                    //��¼ǰ������ 
            ����    }
        ��    ��}
   ����}
}