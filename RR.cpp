#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct PCB_type {
    int pid;     //进程名
	int state;		//进程状态 
					// 2--表示"执行"状态
					// 1--表示"就绪"状态 
					// 0--表示"阻塞"状态
	int cpu_time;  //运行需要的CPU时间（需运行的时间片个数）
	struct PCB_type *next;
}PCB;


PCB	*ready_head = NULL,      
	*ready_tail = NULL,       
	*blocked_head = NULL,    
	*blocked_tail = NULL;     

int use_cpu=0, x=0, unuse_cpu=0;

//读入假设的数据，设置系统初始状态
void start_state(int n, int m) {
	//初始化就绪进程队列 
	for (int i=0; i<n; i++) {
		PCB *p;
		p = (PCB*)malloc(sizeof(PCB));
		
		p->state = 1;
		cout << "进程名：" << endl; 
		cin >> p->pid; 
		cout << "运行需要时间：" << endl; 
		cin >> p->cpu_time;
		
		p->next=NULL;
		if(ready_head == NULL) {
			ready_head = ready_tail = p;
		} else {
			ready_tail->next = p;
			ready_tail = p;
		}
	}
	//初始化阻塞进程队列 
	for (int i=0; i<m; i++) {
		PCB *p;
		p = (PCB*)malloc(sizeof(PCB));
		
		p->state = 0;
		cout << "进程名：" << endl; 
		cin >> p->pid; 
		cout << "运行需要时间：" << endl; 
		cin >> p->cpu_time;
		
		p->next=NULL;
		if(blocked_head == NULL) {
			blocked_head = blocked_tail = p;
		} else {
			blocked_tail->next = p;
			blocked_tail = p;
		}
	}
} 
//模拟调度
void dispath(int t){
	while (ready_head != NULL || blocked_head != NULL) {
		if (ready_head != NULL) {
			PCB *p;
			p = (PCB*)malloc(sizeof(PCB));
			p = ready_head->next;
			p->pid = 2;
			p->cpu_time--;
			use_cpu++;
			if (p->cpu_time > 0) {
				ready_tail->next = p;
				ready_tail = p;
				x++;
				if (x == t) {
					if (blocked_head != NULL) {
						PCB *q;
						q = (PCB*)malloc(sizeof(PCB));
						//将阻塞队列队首添加到就绪队列队尾 
						q =  blocked_head->next;
						ready_tail->next = q;
						ready_tail = q; 
						blocked_head->next = blocked_head->next->next;		
					}	
				}
			} else {
				//释放p 
				ready_head->next = ready_head->next->next;
				free(p);
			}
		} else {
			unuse_cpu++;
		}
	}
}     
//计算CPU利用率
void calculate() {
	float rate;
	rate = use_cpu / (use_cpu + unuse_cpu);
	cout << "cpu利用率：" << rate << endl;
}
  

int main() {
	//有n个就绪状态进程, m个阻塞状态进程
	//每过t个时间片系统释放资源,唤醒处于阻塞队列队首的进程。
	int n=2, m=3, t=5;	
	start_state(n, m);
	dispath(t);
	calculate();
}

