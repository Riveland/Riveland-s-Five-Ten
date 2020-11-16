#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

typedef struct Lnode *List;
typedef int Position;
struct Lnode{
    int Data[MAXSIZE];
    int Last;
};

List L;

List MakeEmpty();
Position Find(List L, int x);
bool Insert(List L, int x, Position p);
bool Delete_by_num(List L, int x);
bool Delete_by_pos(List L, Position p);
int Lengh(List L);
void ShowList(List L);

int main(){
    L = MakeEmpty();
    Insert(L,1,0);
    Insert(L,2,0);
    Insert(L,3,0);
    Insert(L,999,101);
    ShowList(L);
    Insert(L,4,1);
    ShowList(L);
    Insert(L,5,3);
    ShowList(L);
    printf("现在线性表的长度为%d\n",Lengh(L));
    printf("寻找5,在Data[%d]处\n",Find(L,5));
    Delete_by_num(L,4);
    Delete_by_num(L,867);
    ShowList(L);
    printf("现在线性表的长度为%d\n",Lengh(L));
    Delete_by_pos(L,1);
    Delete_by_pos(L,999);
    ShowList(L);
    printf("现在线性表的长度为%d\n",Lengh(L));
    return 0;

}

List MakeEmpty()
{
    List L;
    L=(List)malloc(sizeof(struct Lnode));
    L->Last = -1;
    return L;
}

bool Insert(List L, int x, Position p)
{
    Position i;
    if(L->Last == MAXSIZE-1)
    {
        printf("表满");
        return false;
    }
    if(p<0 || p > L->Last + 1)
    {
        printf("位置不合法\n");
        return false;
    }
    for(i=L->Last;i>=p;i--)
      L->Data[i+1] = L->Data[i];
    L->Data[p] = x;
    L->Last++;
    printf("在Data[%d]插入了%d\n",p,x);
    return true;

}

int Lengh(List L)
{
    return L->Last+1;
}

void ShowList(List L)
{
    for(int i = 0; i<=Lengh(L);i++)
    {
        printf("Data[%d]-->%d\n",i,L->Data[i]);
    }

}

Position Find(List L, int x)
{
    Position i=0;
    while(i<=L->Last &&  L->Data[i] != x)
        i++;
    if(i > L->Last)
    {
        printf("寻找%d不在表中!\n",x);
        return -1;
    }
    else return i;
}

bool Delete_by_num(List L, int x)
{
    Position i = Find(L,x);
    if(i==-1) return 0;
    for(int j = i; j <= L->Last; j++)
      L->Data[j] = L->Data[j+1];
    L->Last--;
    printf("删除%d,删除了Data[%d]的数据\n",x,i);
    return true;
}
bool Delete_by_pos(List L, Position p)
{
    Position i;
    if(p <0 || p > L->Last)
    {
        printf("位置%d错误！删除失败\n", p);
        return false;
    }
    for(i=p+1; i<=L->Last; i++)
        L->Data[i-1] = L->Data[i];
    L->Last --;
    printf("删除了Data[%d]的数据\n",p);
    return 1;
}
