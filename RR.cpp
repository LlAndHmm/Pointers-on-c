#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
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

//�����������ݣ�����ϵͳ��ʼ״̬
void start_state(int n, int m) {
	//��ʼ���������̶��� 
	for (int i=0; i<n; i++) {
		PCB *p;
		p = (PCB*)malloc(sizeof(PCB));
		
		p->state = 1;
		cout << "��������" << endl; 
		cin >> p->pid; 
		cout << "������Ҫʱ�䣺" << endl; 
		cin >> p->cpu_time;
		
		p->next=NULL;
		if(ready_head == NULL) {
			ready_head = ready_tail = p;
		} else {
			ready_tail->next = p;
			ready_tail = p;
		}
	}
	//��ʼ���������̶��� 
	for (int i=0; i<m; i++) {
		PCB *p;
		p = (PCB*)malloc(sizeof(PCB));
		
		p->state = 0;
		cout << "��������" << endl; 
		cin >> p->pid; 
		cout << "������Ҫʱ�䣺" << endl; 
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
//ģ�����
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
						//���������ж�����ӵ��������ж�β 
						q =  blocked_head->next;
						ready_tail->next = q;
						ready_tail = q; 
						blocked_head->next = blocked_head->next->next;		
					}	
				}
			} else {
				//�ͷ�p 
				ready_head->next = ready_head->next->next;
				free(p);
			}
		} else {
			unuse_cpu++;
		}
	}
}     
//����CPU������
void calculate() {
	float rate;
	rate = use_cpu / (use_cpu + unuse_cpu);
	cout << "cpu�����ʣ�" << rate << endl;
}
  

int main() {
	//��n������״̬����, m������״̬����
	//ÿ��t��ʱ��Ƭϵͳ�ͷ���Դ,���Ѵ����������ж��׵Ľ��̡�
	int n=2, m=3, t=5;	
	start_state(n, m);
	dispath(t);
	calculate();
}

