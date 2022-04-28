#include <stdio.h>
#include <stdlib.h> // srand 함수 사용을 위한 헤더 파일
#include <time.h> // time 함수 사용을 위한 헤더 파일

// ================ 원형큐 코드 시작 ================= //
typedef struct { // 구조체 element 타입 정의
	int id;
	int arrival_time;
	int service_time;
} element;
// ================ 원형큐 코드 종료 ================= //

// ================ 원형큐 코드 시작 ================= //
#define MAX_QUEUE_SIZE 5
typedef struct { // 구조체 QueueType 타입 정의
	element data[MAX_QUEUE_SIZE]; // element 타입의 인덱스 값 5를 가지는 배열 data
	int front, rear;
} QueueType;

// 오류 함수
void error(const char* message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 함수
void init_queue(QueueType* q){
	// 첫번째 요소의 하나 앞을 가르키는 front와 마지막을 가르키는 rear
	// front와 rear을 0으로 초기화함으로서 큐 초기화
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q){
	// 원형 큐의 마지막 자리는 포화 상태 확인을 위해 비워야 한다.
	// front와 rear의 값이 같다는 것은 아직 아무런 값도 들어가지 않았음을 의미한다.
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q){
	// 원형 큐의 마지막 자리는 포화 상태 확인을 위해 비워야 한다.
	// rear + 1을 큐 사이즈 (5)로 나눴을 때 front 값 (0)이 된다면
	// 해당 큐는 가득찬 것이다.
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q){
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		// 큐가 비어있지 않다면
		// i의 값을 front 값으로 초기화
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i].arrival_time);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType* q, element item){
	if (is_full(q))
		error("큐가 포화상태입니다"); // q가 가득찼다면 error 출력
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // rear을 한 칸 뒤로 보내고
	q->data[q->rear] = item; // 인덱스 rear번의 data에 item 값 대입
}

// 삭제 함수
element dequeue(QueueType* q){
	if (is_empty(q))
		error("큐가 공백상태입니다"); // q가 비어있다면 에러 출력
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // front를 한 칸 뒤로 보내고
	return q->data[q->front]; // 인덱스 front+1번의 data값을 반환
}

// peek 함수
element peek(QueueType* q){
	if (is_empty(q))
		error("큐가 공백상태입니다"); // q가 비어있다면 에러 출력
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE]; // 인덱스 (q->front + 1) % MAX_QUEUE_SIZE번의 data 값을 반환
}
// ================ 원형큐 코드 종료 ================= //

int main(void){
	int minutes = 60; // 총 업무 시간
	int total_wait = 0; // 총 대기 시간
	int total_customers = 0; // 현재 대기 손님
	int service_time = 0; // 업무 처리 시간
	int service_customer; // 업무 중인 손님
	QueueType queue; // QueueType 타입의 queue 생성
	init_queue(&queue); // queue 초기화

	srand(time(NULL)); // 랜덤 난수 생성을 위한 코드
	for (int clock = 0; clock < minutes; clock++) {
		printf("현재시각=%d\n", clock);
		if ((rand() % 10) < 3) { // 랜덤으로 element 타입의 구조체 customer 생성
			element customer;
			customer.id = total_customers++; // cutomer의 id 값은 total_customer++ 값
			customer.arrival_time = clock; // cutomer의 arrival_time 값은 clock 값
			customer.service_time = rand() % 3 + 1; // cutomer의 service_time 값은 난수 값 (최소 값 1)
			enqueue(&queue, customer); // queue에 customer 값 할당
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",
				customer.id, customer.arrival_time, customer.service_time); // 고객 아이디, 고객 도착 시간, 고객 업무 처리 시간 출력
		}
		if (service_time > 0) { // service_time 값이 0보다 크다면 아래 메시지 출력 (현재 고객 업무를 처리하고 있다면)
			printf("고객 %d 업무처리중입니다. \n", service_customer);
			service_time--; // service_time 값 - 1
		}
		else {
			// service_time 값이 0이라면 (현재 고객 업무를 처리하고 있지 않다면)
			if (!is_empty(&queue)) { // queue가 비었는지 확인, 비어있지 않다면
				element customer = dequeue(&queue); // dequeue(&queue)는 (front + 1)번 손님을 반환
				service_customer = customer.id; // service_customer는 해당 큐의 customer.id
				service_time = customer.service_time; // service_time는 해당 큐의 customer.service_time
				printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
					customer.id, clock, clock - customer.arrival_time); // 고객 아이디, 업무 시작 시간, 대기 시간 출력
				total_wait += clock - customer.arrival_time; // 총 대기 시간 값에 대기 시간을 더함
			}
		}
	}
	printf("전체 대기 시간 = %d분 \n", total_wait);
	return 0;
}