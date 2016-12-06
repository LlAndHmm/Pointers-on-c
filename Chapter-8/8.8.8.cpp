#include <stdlib.h>
#include <stdio.h>
  
int board[8][8] = {0};	//表示棋盘，初始为0，表示未放置皇后
int num = 0;		//解数目

//对于棋盘前row-1行已放置好皇后
//检查在第row行、第column列放置一枚皇后是否可行
bool check(int row,int col) {
    if(row == 0) return true;
    int i,j;
    //纵向只能有一枚皇后
    for(i = 0; i <= row - 1; i++) {
        if(board[i][col] == 1) return false;
    }
    //主对角线元素row-col相等 
    //左上至右下只能有一枚皇后
    i = row - 1;
    j = i - (row - col);
    while(i >= 0 && j >= 0) {
        if(board[i][j] == 1) return false;
        i--;
        j--;
    }
    //处在副对角线的元素row+col相等 
    //右上至左下只能有一枚皇后
    i = row - 1;
    j = row + col - i;
    while(i >= 0 && j <= 7) {
        if(board[i][j] == 1) return false;
        i--;
        j++;
    }
    return true;
}

//当已放置8枚皇后，为可行解时，输出棋盘
void output() {
    int i,j;
    num++;
    printf("answer %d:\n",num);
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) printf("%d ",board[i][j]);
        printf("\n");
    }
}

//采用递归函数实现八皇后回溯算法
//该函数求解当棋盘前row-1行已放置好皇后，在第row行放置皇后
void solve(int row) {
    int j;
    //考虑在第row行的各列放置皇后
    for (j = 0; j < 8; j++) {
        //在其中一列放置皇后
        board[row][j] = 1;
        //检查在该列放置皇后是否可行
        if (check(row, j) == true) {
            //若该列可放置皇后，且该列为最后一列，则找到一可行解，输出
            if(row == 7) output();
            //若该列可放置皇后，则向下一行，继续搜索、求解
            else solve(row + 1);
        }
        //取出该列的皇后，进行回溯，在其他列放置皇后
        board[row][j] = 0;
    }
}

int main() {
    solve(0);
    return 0;
}
