//������ͷ����˫������
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <locale.h>
struct NODE {
	int          data;
	struct NODE *next;
	struct NODE *prev;
} *head, *p, *q, *s, *p1, *p2, *q1, **ta;
int i, k, n, t, m, v, N = 10;
int main() {
	setlocale(LC_ALL, "chs");
	srand(time(NULL));

	head = NULL;

	printf("����%d���ڵ��˫������:", N);//����N���ڵ��˫������
	p = head;
	for (i = 0; i < N; i++) {
		q = (struct NODE *)malloc(sizeof(struct NODE));
		if (NULL == q) exit(1);
		q->data = rand() % 100;//��д0..99�����ֵ
		q->next = NULL;
		q->prev = NULL;
		if (NULL == p) {
			head = q;
			p = head;
		}
		else {
			p->next = q;
			q->prev = p;
			p = q;
		}
	}

	//�������˫������
	s = head;
	while (1) {
		if (NULL == s) {
			printf("\n");
			break;
		}
		printf("%02d<->", s->data);
		if (NULL != s->next && s->next->prev != s) { printf(" !\n"); break; }
		s = s->next;
	}

	k = 3;
	v = 5;
	printf("��ֵΪ%d�Ľ����뵽˫������ĵ�%d�����ǰ:", v, k);//��ֵΪv�Ľ����뵽˫������ĵ�k�����ǰ
	n = 0;
	p = head;
	while (1) {
		if (NULL == p) {
			break;
		}
		n++;
		if (k == 1) {
			q = (struct NODE *)malloc(sizeof(struct NODE));
			if (NULL == q) exit(1);
			q->data = v;
			q->next = head;
			q->prev = NULL;
			head->prev = q;
			head = q;
			break;
		}
		else {
			if (k - 1 == n) {
				q = (struct NODE *)malloc(sizeof(struct NODE));
				if (NULL == q) exit(1);
				q->data = v;
				q->next = p->next;
				q->prev = p;
				p->next->prev = q;
				p->next = q;
				break;
			}
		}
		p = p->next;
	}

	//�������˫������
	s = head;
	while (1) {
		if (NULL == s) {
			printf("\n");
			break;
		}
		printf("%02d<->", s->data);
		if (NULL != s->next && s->next->prev != s) { printf(" !\n"); break; }
		s = s->next;
	}

	k = 5;
	printf("ɾ����%d���ڵ�:", k);//ɾ����k���ڵ�
	n = 0;
	p = head;
	while (1) {
		if (NULL == p) {
			break;
		}
		n++;
		if (k == 1) {
			q = head;
			head = head->next;
			head->prev = NULL;
			free(q);
			break;
		}
		else {
			if (k - 1 == n) {
				q = p->next;
				if (q) {
					p->next = q->next;
					if (q->next) q->next->prev = p;
					free(q);
				}
				break;
			}
		}
		p = p->next;
	}

	//�������˫������
	s = head;
	while (1) {
		if (NULL == s) {
			printf("\n");
			break;
		}
		printf("%02d<->", s->data);
		if (NULL != s->next && s->next->prev != s) { printf(" !\n"); break; }
		s = s->next;
	}

	printf("��С��������:");//��С��������
	for (p = head, p1 = NULL; p != NULL; p1 = p, p = p->next) {
		for (q = p->next, q1 = p; q != NULL; q1 = q, q = q->next) {
			if (p->data > q->data) {

				//����data
//              printf("swap %02d %02d\n",p->data,q->data);
//              t=p->data;p->data=q->data;q->data=t;

				//����

				//����prev��next
//              printf("swap %02d %02d\n",p->data,q->data);
				if (p == head) {//p��ͷ
					if (p->next == q) {//pq����
						head = q;
						head->prev = NULL;
						p->next = q->next;
						p->prev = q;
						if (q->next) q->next->prev = p;
						q->next = p;
						q = p;
						p = head;
					}
					else {//pq������
						head = q;
						head->prev = NULL;
						p2 = p->next;
						p->next = q->next;
						p->prev = q->prev;
						if (q->next) q->next->prev = p;
						q->next = p2;
						p2->prev = q;
						q1->next = p;
						q = p;
						p = head;
					}
				}
				else {//p����ͷ
					if (p->next == q) {//pq����
						p1->next = q;
						p->next = q->next;
						p->prev = q;
						if (q->next) q->next->prev = p;
						q->next = p;
						q->prev = p1;
						q = p;
						p = p1->next;
					}
					else {//pq������
						p1->next = q;
						p2 = p->next;
						p->next = q->next;
						p->prev = q->prev;
						if (q->next) q->next->prev = p;
						q->next = p2;
						p2->prev = q;
						q->prev = p1;
						q1->next = p;
						q = p;
						p = p1->next;
					}
				}

				//�������˫������
//              s=head;
//              while (1) {
//                  if (NULL==s) {
//                      printf("\n");
//                      break;
//                  }
//                  printf("%02d<->",s->data);
//                  if (NULL!=s->next && s->next->prev!=s) {printf(" !\n");break;}
//                  s=s->next;
//              }
//              getchar();
			}
		}
	}

	//�������˫����������������n
	n = 0;
	s = head;
	while (1) {
		if (NULL == s) {
			printf("\n");
			break;
		}
		printf("%02d<->", s->data);
		if (NULL != s->next && s->next->prev != s) { printf(" !\n"); break; }
		n++;
		s = s->next;
	}

	printf("��������������:");//��������������
	if (n >= 2) {
		p = head;
		q = p->next;
		p->next = NULL;
		while (1) {
			q1 = q->next;
			q->next = p;
			p->prev = q;
			p = q;
			q = q1;
			if (NULL == q) break;
		}
		head = p;
		head->prev = NULL;
	}

	//�������˫������
	s = head;
	while (1) {
		if (NULL == s) {
			printf("\n");
			break;
		}
		printf("%02d<->", s->data);
		if (NULL != s->next && s->next->prev != s) { printf(" !\n"); break; }
		s = s->next;
	}

	m = 4;
	n = 6;
	printf("��˫��������ǰ%d�����ͺ�%d�������л���:", m, n);//��˫��������ǰm�����ͺ�n�������л���,m+nΪ�����ܳ�
	k = 0;
	p = head;
	while (1) {
		if (NULL == p) {
			break;
		}
		k++;
		if (m == k) {
			q = p;
		}
		s = p;
		p = p->next;
	}
	q1 = head;
	head = q->next;
	head->prev = NULL;
	s->next = q1;
	q1->prev = s;
	q->next = NULL;

	//�������˫������
	s = head;
	while (1) {
		if (NULL == s) {
			printf("\n");
			break;
		}
		printf("%02d<->", s->data);
		if (NULL != s->next && s->next->prev != s) { printf(" !\n"); break; }
		s = s->next;
	}

	//�ͷ����нڵ�
	p = head;
	while (1) {
		if (NULL == p) {
			break;
		}
		q = p->next;
		free(p);
		p = q;
	}

	return 0;
}
//����10���ڵ��˫������:93<->03<->60<->05<->57<->71<->02<->41<->26<->85<->
//��ֵΪ5�Ľ����뵽˫������ĵ�3�����ǰ:93<->03<->05<->60<->05<->57<->71<->02<->41<->26<->85<->
//ɾ����5���ڵ�:93<->03<->05<->60<->57<->71<->02<->41<->26<->85<->
//��С��������:02<->03<->05<->26<->41<->57<->60<->71<->85<->93<->
//��������������:93<->85<->71<->60<->57<->41<->26<->05<->03<->02<->
//��˫��������ǰ4�����ͺ�6�������л���:57<->41<->26<->05<->03<->02<->93<->85<->71<->60<->
//
