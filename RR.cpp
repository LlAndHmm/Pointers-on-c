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
 	//��¼һ������pid��int�ͣ�һ��ֵ��ĸ�ͳ�����  
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
 	for (int j=0; j<m; j++) { 
 		enBlockedQueue();	 
 	} 
 }  
//ģ����� 
void dispath(int t){ 
	int count = 1;
 	while (ready_head != NULL || blocked_head != NULL) { 
		printf("��%d��ʱ��Ƭ: ", count);
 		if (ready_head != NULL) { 
 			PCB *p; 
 			p = ready_head; 
			printf("����%dռ�� \n", p->pid);
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
			printf("����\n");
 			unuse_cpu++; 
 		} 
 		x++; 
 		if (x == t) { 
 			if (blocked_head != NULL) { 
 				PCB *q;  
 				//���������ж�����ӵ��������ж�β  
 				q =  blocked_head; 
 				q->state = 2;
 				printf("ϵͳ�ͷ���Դ�����ѽ���%d\n", q->pid);
				 //�������������Ƿ�ֻ��һ�����
				if (blocked_head == blocked_tail) {
					blocked_head = blocked_head->next;
					blocked_tail = NULL;
				} else {
					blocked_head = blocked_head->next;
					q->next = NULL;
				} 
 				//��������Ϊ�գ�cpuһֱ���ڿ��У�����t��ʱ��Ƭ�ͷ���Դ������Ҫ���жϾ��������Ƿ�Ϊ��  
 				if (ready_head == ready_tail) { 
 					ready_head = ready_tail = q; 
 				} else { 
 					ready_tail->next = q; 
 					ready_tail = q; 
 				}  
 				x = 0;		 
 			}	 
 		} 
		count++;
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
 	int n, m, t;
	printf("����״̬��������\n");
	scanf("%d", &n);
	printf("����״̬��������\n");
	scanf("%d", &m);
	printf("��t��ʱ��Ƭϵͳ�ͷ���Դ��������t��\n");
	scanf("%d", &t);
 	start_state(n, m); 
 	dispath(t); 
 	calculate();
	return 0;
} 

