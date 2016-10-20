#include<stdio.h>
#include<stdlib.h>
typedef struct PCB_type {
    int pid;     //������
	int state;		//����״̬ 
					// 2--��ʾ"ִ��"״̬
					// 1--��ʾ"����"״̬ 
					// 0--��ʾ"����"״̬
	int cpu_time;  //������Ҫ��CPUʱ�䣨�����е�ʱ��Ƭ������
	struct PCB_type *next;
}PCB;


PCB	*ready_head = NULL,      
	*ready_tail = NULL,       
	*blocked_head = NULL,    
	*blocked_tail = NULL;     

int use_cpu=0, x=0, unuse_cpu=0;

//��ʼ���������̶��� 
void enReadyQueue() {
	PCB *p;
	p = (PCB*)malloc(sizeof(PCB));
		
	p->state = 1;
	printf("��������\n");  
	scanf("%d", &p->pid); 
	printf("������Ҫʱ�䣺\n" );
	scanf("%d", &p->cpu_time); 
		
	p->next=NULL;
	if(ready_head == NULL) {
		ready_head = ready_tail = p;
	} else {
		ready_tail->next = p;
		ready_tail = p;
	}
} 
//��ʼ���������̶��� 
void enBlockedQueue() {
	PCB *p;
	p = (PCB*)malloc(sizeof(PCB));
	
	p->state = 0;
	//��¼һ������������pid��int�ͣ�һ��ֵ��ĸ�ͳ����� 
	printf("��������\n");
	scanf("%d", &p->pid); 
	printf("������Ҫʱ�䣺\n"); 
	scanf("%d", &p->cpu_time);

	p->next=NULL;
	if(blocked_head == NULL) {
		blocked_head = blocked_tail = p;
	} else {
		blocked_tail->next = p;
		blocked_tail = p;
	}
}

//�����������ݣ�����ϵͳ��ʼ״̬
void start_state(int n, int m) {
	printf("�������н�����Ϣ:\n");
	for (int i=0; i<n; i++) {
		enReadyQueue();
	}
	
	printf("�������н�����Ϣ:\n"); 
	for (int i=0; i<m; i++) {
		enBlockedQueue();	
	}
} 
//ģ�����
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
				//��p���뵽�������ж�β 
				ready_tail->next = p;
				ready_tail = p;
				ready_head = ready_head->next;
				p->next = NULL;
			} else {
				//�ͷ�p 
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
				//���������ж�����ӵ��������ж�β 
				q =  blocked_head;
				q->state = 2;
				//��������Ϊ�գ�cpuһֱ���ڿ��У�����t��ʱ��Ƭ�ͷ���Դ������Ҫ���жϾ��������Ƿ�Ϊ�� 
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
//����CPU������
void calculate() {
	int rate;
	rate = (use_cpu * 100) / (use_cpu + unuse_cpu);
	printf("cpu�����ʣ�%d %%\n", rate);
}
  

int main() {
	//��n������״̬����, m������״̬����
	//ÿ��t��ʱ��Ƭϵͳ�ͷ���Դ,���Ѵ����������ж��׵Ľ��̡�
	int n=2, m=3, t=5;	
	start_state(n, m);
	dispath(t);
	calculate();
}

