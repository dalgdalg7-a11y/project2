#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_LENGTH 50

// 책 정보를 저장할 구조체 정의
typedef struct {
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    char publisher[MAX_LENGTH];
} Book;

int main() {
    Book library[MAX_BOOKS]; // 책을 저장할 배열
    int bookCount = 0;       // 현재 저장된 책의 개수
    char input[MAX_LENGTH];  // 사용자 입력을 받을 임시 변수

    printf("=== 도서 정보 등록 프로그램 ===\n");
    printf("('출력'을 입력하면 지금까지 저장된 책 목록을 보여줍니다.)\n\n");

    while (1) {
        // 첫 번째 입력(제목)을 받으면서 동시에 '출력' 여부 확인
        printf("%d번째 책 제목을 입력하세요 (또는 '출력' 입력): ", bookCount + 1);
        
        // 공백을 포함해서 입력받기 위해 %[^\n] 사용
        scanf(" %[^\n]", input); 
        
        // 입력받은 단어가 "출력"인지 확인
        if (strcmp(input, "출력") == 0) {
            break; // 반복문 탈출 후 출력 프로세스로 이동
        }

        // 배열 개수 초과 방지
        if (bookCount >= MAX_BOOKS) {
            printf("더 이상 책을 저장할 수 없습니다! (최대 %d권)\n", MAX_BOOKS);
            break;
        }

        // '출력'이 아니라면 구조체 배열에 제목 저장
        strcpy(library[bookCount].title, input);

        // 작가 입력 받기
        printf("작가 이름을 입력하세요: ");
        scanf(" %[^\n]", library[bookCount].author);

        // 출판사 입력 받기
        printf("출판사를 입력하세요: ");
        scanf(" %[^\n]", library[bookCount].publisher);

        bookCount++; // 등록된 책 개수 증가
        printf("👉 성공적으로 등록되었습니다!\n\n");
    }

    // --- 저장된 데이터 출력 세션 ---
    printf("\n================ 저장된 도서 목록 ================\n");
    if (bookCount == 0) {
        printf("저장된 도서 정보가 없습니다.\n");
    } else {
        for (int i = 0; i < bookCount; i++) {
            printf("[%d번째 도서]\n", i + 1);
            printf("• 제  목: %s\n", library[i].title);
            printf("• 작  가: %s\n", library[i].author);
            printf("• 출판사: %s\n", library[i].publisher);
            printf("------------------------------------------------\n");
        }
        printf("총 %d권의 도서가 출력되었습니다.\n", bookCount);
    }
    printf("==================================================\n");

    return 0;
}