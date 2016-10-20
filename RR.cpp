#include<stdio.h>
#include<stdlib.h>
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

//初始化就绪进程队列 
void enReadyQueue() {
	PCB *p;
	p = (PCB*)malloc(sizeof(PCB));
		
	p->state = 1;
	printf("进程名：\n");  
	scanf("%d", &p->pid); 
	printf("运行需要时间：\n" );
	scanf("%d", &p->cpu_time); 
		
	p->next=NULL;
	if(ready_head == NULL) {
		ready_head = ready_tail = p;
	} else {
		ready_tail->next = p;
		ready_tail = p;
	}
} 
//初始化阻塞进程队列 
void enBlockedQueue() {
	PCB *p;
	p = (PCB*)malloc(sizeof(PCB));
	
	p->state = 0;
	//记录一个错误，我忘了pid是int型，一赋值字母就出错。。 
	printf("进程名：\n");
	scanf("%d", &p->pid); 
	printf("运行需要时间：\n"); 
	scanf("%d", &p->cpu_time);

	p->next=NULL;
	if(blocked_head == NULL) {
		blocked_head = blocked_tail = p;
	} else {
		blocked_tail->next = p;
		blocked_tail = p;
	}
}

//读入假设的数据，设置系统初始状态
void start_state(int n, int m) {
	printf("就绪队列进程信息:\n");
	for (int i=0; i<n; i++) {
		enReadyQueue();
	}
	
	printf("阻塞队列进程信息:\n"); 
	for (int i=0; i<m; i++) {
		enBlockedQueue();	
	}
} 
//模拟调度
void dispath(int t){
	while (ready_head != NULL || blocked_head != NULL) {
		if (ready_head != NULL) {
			PCB *p;
			p = (PCB*)malloc(sizeof(PCB));
			p = ready_head;
			p->state = 2;
			p->cpu_time--;
			use_cpu++;
			if (p->cpu_time > 0) {
				//将p加入到就绪队列队尾 
				ready_tail->next = p;
				ready_tail = p;
				ready_head = ready_head->next;
				p->next = NULL;
			} else {
				//释放p 
				if(ready_head == ready_tail) {
					ready_head = ready_tail = NULL;
				} else {
					ready_head = ready_head->next;
				} 			
				free(p);
			}
		} else {
			unuse_cpu++;
		}
		x++;
		if (x == t) {
			if (blocked_head != NULL) {
				PCB *q;
				q = (PCB*)malloc(sizeof(PCB));
				//将阻塞队列队首添加到就绪队列队尾 
				q =  blocked_head;
				q->state = 2;
				//就绪队列为空，cpu一直处于空闲，到第t个时间片释放资源，所以要先判断就绪队列是否为空 
				if (ready_head == ready_tail) {
					ready_head = ready_tail = q;
				} else {
					ready_tail->next = q;
					ready_tail = q;
				}
				blocked_head = blocked_head->next;
				x = 0;		
			}	
		}
	}
}     
//计算CPU利用率
void calculate() {
	int rate;
	rate = (use_cpu * 100) / (use_cpu + unuse_cpu);
	printf("cpu利用率：%d %%\n", rate);
}
  

int main() {
	//有n个就绪状态进程, m个阻塞状态进程
	//每过t个时间片系统释放资源,唤醒处于阻塞队列队首的进程。
	int n=2, m=3, t=5;	
	start_state(n, m);
	dispath(t);
	calculate();
}

