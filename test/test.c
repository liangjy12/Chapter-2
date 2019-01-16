//不带表头结点的双向链表
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

	printf("创建%d个节点的双向链表:", N);//创建N个节点的双向链表
	p = head;
	for (i = 0; i < N; i++) {
		q = (struct NODE *)malloc(sizeof(struct NODE));
		if (NULL == q) exit(1);
		q->data = rand() % 100;//填写0..99的随机值
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

	//输出整个双向链表
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
	printf("将值为%d的结点插入到双向链表的第%d个结点前:", v, k);//将值为v的结点插入到双向链表的第k个结点前
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

	//输出整个双向链表
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
	printf("删除第%d个节点:", k);//删除第k个节点
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

	//输出整个双向链表
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

	printf("从小到大排序:");//从小到大排序
	for (p = head, p1 = NULL; p != NULL; p1 = p, p = p->next) {
		for (q = p->next, q1 = p; q != NULL; q1 = q, q = q->next) {
			if (p->data > q->data) {

				//交换data
//              printf("swap %02d %02d\n",p->data,q->data);
//              t=p->data;p->data=q->data;q->data=t;

				//或者

				//交换prev和next
//              printf("swap %02d %02d\n",p->data,q->data);
				if (p == head) {//p是头
					if (p->next == q) {//pq挨着
						head = q;
						head->prev = NULL;
						p->next = q->next;
						p->prev = q;
						if (q->next) q->next->prev = p;
						q->next = p;
						q = p;
						p = head;
					}
					else {//pq不挨着
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
				else {//p不是头
					if (p->next == q) {//pq挨着
						p1->next = q;
						p->next = q->next;
						p->prev = q;
						if (q->next) q->next->prev = p;
						q->next = p;
						q->prev = p1;
						q = p;
						p = p1->next;
					}
					else {//pq不挨着
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

				//输出整个双向链表
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

	//输出整个双向链表并计算链表长度n
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

	printf("将整个链表逆序:");//将整个链表逆序
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

	//输出整个双向链表
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
	printf("将双向链表中前%d个结点和后%d个结点进行互换:", m, n);//将双向链表中前m个结点和后n个结点进行互换,m+n为链表总长
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

	//输出整个双向链表
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

	//释放所有节点
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
//创建10个节点的双向链表:93<->03<->60<->05<->57<->71<->02<->41<->26<->85<->
//将值为5的结点插入到双向链表的第3个结点前:93<->03<->05<->60<->05<->57<->71<->02<->41<->26<->85<->
//删除第5个节点:93<->03<->05<->60<->57<->71<->02<->41<->26<->85<->
//从小到大排序:02<->03<->05<->26<->41<->57<->60<->71<->85<->93<->
//将整个链表逆序:93<->85<->71<->60<->57<->41<->26<->05<->03<->02<->
//将双向链表中前4个结点和后6个结点进行互换:57<->41<->26<->05<->03<->02<->93<->85<->71<->60<->
//
