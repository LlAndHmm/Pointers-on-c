#include <stdlib.h>
#include <stdio.h>
  
int board[8][8] = {0};	//��ʾ���̣���ʼΪ0����ʾδ���ûʺ�
int num = 0;		//����Ŀ

//��������ǰrow-1���ѷ��úûʺ�
//����ڵ�row�С���column�з���һö�ʺ��Ƿ����
bool check(int row,int col) {
    if(row == 0) return true;
    int i,j;
    //����ֻ����һö�ʺ�
    for(i = 0; i <= row - 1; i++) {
        if(board[i][col] == 1) return false;
    }
    //���Խ���Ԫ��row-col��� 
    //����������ֻ����һö�ʺ�
    i = row - 1;
    j = i - (row - col);
    while(i >= 0 && j >= 0) {
        if(board[i][j] == 1) return false;
        i--;
        j--;
    }
    //���ڸ��Խ��ߵ�Ԫ��row+col��� 
    //����������ֻ����һö�ʺ�
    i = row - 1;
    j = row + col - i;
    while(i >= 0 && j <= 7) {
        if(board[i][j] == 1) return false;
        i--;
        j++;
    }
    return true;
}

//���ѷ���8ö�ʺ�Ϊ���н�ʱ���������
void output() {
    int i,j;
    num++;
    printf("answer %d:\n",num);
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) printf("%d ",board[i][j]);
        printf("\n");
    }
}

//���õݹ麯��ʵ�ְ˻ʺ�����㷨
//�ú�����⵱����ǰrow-1���ѷ��úûʺ��ڵ�row�з��ûʺ�
void solve(int row) {
    int j;
    //�����ڵ�row�еĸ��з��ûʺ�
    for (j = 0; j < 8; j++) {
        //������һ�з��ûʺ�
        board[row][j] = 1;
        //����ڸ��з��ûʺ��Ƿ����
        if (check(row, j) == true) {
            //�����пɷ��ûʺ��Ҹ���Ϊ���һ�У����ҵ�һ���н⣬���
            if(row == 7) output();
            //�����пɷ��ûʺ�������һ�У��������������
            else solve(row + 1);
        }
        //ȡ�����еĻʺ󣬽��л��ݣ��������з��ûʺ�
        board[row][j] = 0;
    }
}

int main() {
    solve(0);
    return 0;
}
