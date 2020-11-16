#include<stdio.h>
#include<malloc.h>

typedef struct Lnode *PtrToNode;
struct Lnode
{
    int Data;
    PtrToNode Next;
};
typedef PtrToNode List;
typedef PtrToNode Position;

List initList();
void display(List L);
void Length(List L);
void Find(List L, int x);
Position Find_re(List L, int x);
bool Insert(List L, int x, Position p);
bool Delete( List L, Position p);

int main()
{
    printf("��ʼ׼����ʼ������\n");
    List L = initList();
    display(L);
    Length(L);
    Find(L,3);
    Insert(L,5,Find_re(L,3));
    display(L);
    Length(L);
    Find(L,4);
    Insert(L,5,Find_re(L,4));
    display(L);
    Length(L);
    Find(L,4);
    Delete(L,Find_re(L,3));
    display(L);
    Length(L);
    Find(L,4);
    return 0;
}


List initList()
{
    List L = (List)malloc(sizeof(List));
    Position temp = L;
    for (int i=1; i<5; i++) {
    List a=(List)malloc(sizeof(List));
    a->Data=i;
    a->Next=NULL;
    temp->Next=a;
    temp=temp->Next;
    }
    return L;
}

void display(List L)
{
    Position temp = L;
    int i = 1;
    while (temp->Next) {
        temp=temp->Next;
        printf("��%d�����:%d\n",i,temp->Data);
        i++;
    }
}

void Length(List L)
{
    Position temp = L;
    int t = 0;
    while(temp->Next)
    {
        temp = temp->Next;
        t++;
    }
    printf("����ĳ���Ϊ%d���ڵ�\n",t);
}

void Find(List L, int x)
{
    Position temp = L;
    int i=0;
    while(temp && temp->Data != x)
    {temp = temp->Next;i++;}
    if(temp)
    {
        printf("%d���ڵ�λ����%d\n",x,i);
    }else printf("û�ҵ�!");

}

Position Find_re(List L, int x)
{
    Position temp = L;
    int i=0;
    while(temp && temp->Data != x)
    {temp = temp->Next;i++;}
    return temp;
}

bool Insert(List L, int x, Position p)
{
    printf("׼������%d\n",p->Data);
    Position pre;
    for ( pre=L; pre&&pre->Next!=p; pre=pre->Next ) ;
    if ( pre==NULL )
    {
        printf("����λ�ò�������\n");
        return false;
    }else{
        printf("�ɹ�����%d!\n", p->Data);
        Position temp = (List)malloc(sizeof(List));
        temp->Data = x;
        temp->Next = p;
        pre->Next = temp;
        return true;
    }
}

bool Delete( List L, Position p)
{
    printf("׼��ɾ��%d\n",p->Data);
    Position pre;
    for ( pre=L; pre&&pre->Next!=p; pre=pre->Next ) ;
    if ( pre==NULL || p==NULL) {
        printf("ɾ��λ�ò�������\n");
        return false;
    }
    else {
        printf("�ɹ�ɾ��%d!\n", p->Data);
        pre->Next = p->Next;
        free(p);
        return true;
    }
}
