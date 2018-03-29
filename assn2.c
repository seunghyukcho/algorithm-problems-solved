#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_line();
int show_menu();
int game_start();
void print_stairs(int, int, int);
void generate_two_numbers(int *, int *);
int pick_one_computer(int, int, int, int);
int win_lose_draw(int, int);
void show_record(int, int);
void print_one(int);
void print_rock_scissors(void);
void print_paper_rock(void);
void print_scissors_paper(void);
void print_RPS(int, int);

int main(void)
{
   char vacant = 0; //임의의 변수, 아래 참조.
   int s = 0, t = 0;
   char n;
   while(1)
   {
      switch (show_menu())
      {
      case 1:
         if (game_start() == -1)
            t += 1;
         else if (game_start() == 1)
            s += 1;
         break;
      case 2:
         show_record(s, t);
         break;
      case 3:
         while (1)
         {
            vacant = getchar();
            /*show_menu에서 숫자를 입력하고 엔터를 친다. 이때 엔터에 의해 전송 된 값은 남아있는데,
            아래 scanf함수에서 문자를 받을 때 엔터를 문자는 인식되므로 아래 scanf를 생략할 수 있다.
            따라서 이를 미연에 방지하기 위해 임의의 char형 변수에 이 enter를 받는다.*/
            printf("게임을 종료하시겠습니까?(y/n) ");
            scanf("%c", &n);
            if (n != 'y' && n != 'Y')
               system("cls"), show_menu();
            else break;
         }
         printf("게임을 종료합니다...\n");
         return 0;
      default:
         break;
      }
   }
}

void draw_line(void)
{
   for (int i = 0; i < 40; i++)
      printf("▩");
   printf("\n");
}

int show_menu(void)
{
   int num = 0;
   system("cls");
   draw_line();
   printf("\n     1. 게임 시작\n");
   printf("     2. 전적 및 승률\n");
   printf("     3. 게임 종료\n\n");
   draw_line();

   printf("메뉴 번호 입력 >> ");
   scanf("%d", &num);
   return num;
}

int game_start(void)
{
   char skip = 'a'; //위에서 설명한 바와 같이, 임의의 enter를 받기 위한 임의의 변수
   int n;//계단수
   system("cls");
   printf("게임을 위한 계단의 개수를 입력<10~30> >> ");
   scanf("%d", &n);
   int p = 0, q = n;// p: 사용자 좌표, q: 컴퓨터 좌표 / 가장 오른쪽: p=q=0, 가장 왼쪽, p=q=n
   while (n < 10 || n > 30)
   {
      printf("게임을 위한 계단의 개수를 입력<10~30> >> ");
      scanf("%d", &n);
   }
   system("cls");
   while (q > 0 && p < n)
   {
      int u1, u2;// 사용자가 선택하는 두 수
      int c1, c2; // 컴퓨터 선택하는 두 수
      int a, b; // a: 사용자가 두 수 중 선택하는 수, b: 컴퓨터가 두 수 중 선택하는 수.
      print_stairs(n, p, q);

      do
      {
         printf("가위<1>, 바위<2>, 보<3> >> ");
         scanf("%d %d", &u1, &u2);

      } while (u1 == u2 || u1 > 3 || u1 < 1 || u2 > 3 || u2 < 1);

      int big_user = u1 > u2 ? u1 : u2; // big_user에 u1, u2 중 큰 수를 저장
      int small_user = u1 > u2 ? u2 : u1; // 작은 수를 저장

      generate_two_numbers(&c1, &c2);

      int big_comp = c1 > c2 ? c1 : c2; // 컴퓨터가 발생한 c1, c2중 큰 수를 big_comp에 저장
      int small_comp = c1 > c2 ? c2 : c1; // 작은 수를 저장

      printf("\n[컴퓨터의 후보]\n");
      print_RPS(big_comp, small_comp); //컴퓨터 후보 출력
      printf("\n[플레이어의 후보]\n");
      print_RPS(big_user, small_user); //사용자 후보 출력

      while (1)
      {
         switch (big_user)
         {
         case 3:
         {
            if (small_user == 2)
               printf("보<3>, 바위<2> >> ");
            else printf("보<3>, 가위<1> >> ");
            break;
         }
         case 2:
            printf("바위<2>, 가위<1> >> ");
         }
         scanf("%d", &a);
         if (a == big_user || a == small_user)
            break;
         else printf("잘못된 입력입니다. 다시 선택하세요");
      }

      system("cls");
      b = pick_one_computer(big_comp, small_comp, big_user, small_user);

      printf("[컴퓨터의 최종 선택]\n");
      print_one(b);

      printf("[플레이어의 최종선택]\n");
      print_one(a);

      if (win_lose_draw(a, b) == 1)
      {
         printf("플레이어가 이겼습니다!!\n\n");
         p += a;
      }
      else if (win_lose_draw(a, b) == -1)
      {
         printf("컴퓨터가 이겼습니다!!\n\n");
         q -= b;
      }
      else
      {
         printf("비겼습니다!!\n\n");
      }

      printf("계속 하려면 엔터키를 입력하세요...\n");
      getchar(); //getchar을 통해 skip이라는 변수에 scanf호출 시 남은 enter를 받음.
      do {
         skip=getchar(); //임의의 문자 or 숫자를 입력하여 skip에 저장.
      } while (skip != '\n');//skip이 엔터와 같다면 이 반복문은 끝난다. 즉, 엔터를 쳐야 끝난다.
      system("cls");
   }

   if (q <= 0)
   {
      q = 0;
      print_stairs(n, p, q);
      printf("\n▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n\n");
      printf("     ★ ★ 컴퓨터 최종 승리 ★ ★ \n\n");
      printf("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n\n");

      printf("메뉴로 돌아가려면 엔터키를 입력하세요...");
      getchar();
      system("cls");
      return -1;
   }
   else
   {
      p = n;
      print_stairs(n, p, q);
      printf("\n▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n\n");
      printf("    ★ ★ 플레이어 최종 승리 ★ ★ \n\n");
      printf("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n\n");

      printf("메뉴로 돌아가려면 엔터키를 입력하세요...");
      do {
         skip = getchar(); //임의의 문자 or 숫자를 입력하여 skip에 저장.
      } while (skip != '\n');//skip이 엔터와 같다면 이 반복문은 끝난다. 즉, 엔터를 쳐야 끝난다.
      system("cls");
      return 1;
   }
}

void show_record(int s, int t) //s가 이긴횟수, t가 진 횟수; main 함수에서 전달받는다.
{
   system("cls");
   float winrate;
   if (s != 0 && t != 0)
      winrate = (float)s / (s + t) * 100;
   else winrate = 0;
   printf("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n\n");
   printf("                   승리:    %2d\n\n", s);
   printf("                   패배:    %2d\n\n", t);
   printf("                   승률:    %.2f%%\n\n", winrate);
   printf("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n\n");
}

int win_lose_draw(int a, int b)
/* 이 함수는 사용자의 선택 값 a와 컴퓨터의 선택 값 b를 받아 가위~바위~보 진행 시
사용자가 이기면 1을, 컴퓨터가 이기면 -1을, 비기면 0을 반환한다.*/
{
   if (a > b)
   {
      if (a == 3 && b == 1)
         return -1;
      else return 1;
   }
   else if (a < b)
   {
      if (b == 3 && a == 1)
         return 1;
      else return -1;
   }
   else
      return 0;
}

void print_RPS(int n1, int n2)
{
   if (n2 == 1 && n1 == 2) // 큰수와 작은 수를 진작에 구해 놓은 이유는 이와 같은 곳에서 조건문을 줄이기 위함
      print_rock_scissors();
   if (n2 == 1 && n1 == 3)
      print_scissors_paper();
   if (n2 == 2 && n1 == 3)
      print_paper_rock();
}

void print_stairs(int n, int p, int q)
{
   int oddeven;
   /* i = 0번째 행부터 차례로 계단모양을 출력하는 아래의 for문은 짝수/홀수 냐에 따라 출력하는 열의 갯수만 다르다.
   따라서 다음과 같은 변수의 선언을 이용해 같은 내용의 반복문을 2번 쓰는 것을 피한다.*/

   printf("총 계단수: %d\n", n);
   printf("PLAYER:    ○ <%d>\n", p);
   printf("COMPUTER:  ● <%d>\n\n", n - q);
   /*q는 n부터 시작되는 변수이므로, n - q는 0부터 시작하는 변수이다.
   n - q가 0에서 부터 시작해야하는 이유는 이가 computer의 말이 얼마 이동했는지 보여주기 때문이다.
   q는 컴퓨터의 말이 계단위에서 몇번째 행에 위치하는 지를 파악하기 위함이고,
   n - i (i는 출력하는 열의 순서)는 출력이 진행되는 i번째 열에 컴퓨터의 말이 있는 지를 확인하기 위함이다.*/

   if (n % 2 == 0)
      oddeven = n / 2 + 1;
   else oddeven = n / 2 + 2;

   for (int i = 0; i < oddeven; i++)
   {
      if (p != i && q != n - i)
      {
         for (int j = 0; j < i; j++)
            printf("▩");
         for (int k = 0; k < n + 1 - 2 * i; k++)
            printf("  ");
         for (int h = 0; h < i; h++)
            printf("▩");
         printf("\n");
      }
      else if (p == i && q == n - i)
      {
         if (p != q)
         {
            if (p < n / 2)
            {
               for (int j = 0; j < i; j++)
                  printf("▩");
               printf("○");
               for (int k = 0; k < n - 1 - 2 * i; k++)
                  printf("  ");
               printf("●");
               for (int h = 0; h < i; h++)
                  printf("▩");
               printf("\n");
            }
            else
            {
               for (int j = 0; j < i; j++)
                  printf("▩");
               printf("●");
               for (int k = 0; k < n - 1 - 2 * i; k++)
                  printf("  ");
               printf("○");
               for (int h = 0; h < i; h++)
                  printf("▩");
               printf("\n");
            }
         }
         else
         {
            if (p < n / 2)
            {
               for (int j = 0; j < i; j++)
                  printf("▩");
               printf("◑");
               for (int k = 0; k < n - 2 * i; k++)
                  printf("  ");
               for (int h = 0; h < i; h++)
                  printf("▩");
               printf("\n");
            }
            else
            {
               for (int j = 0; j < i; j++)
                  printf("▩");
               for (int k = 0; k < n - 2 * i; k++)
                  printf("  ");
               printf("◑");
               for (int h = 0; h < i; h++)
                  printf("▩");
               printf("\n");
            }
         }
      }
      else if (p != i && q == n - i)
      {
         if (q < n / 2)
         // q는 말이 몇번째 행에 있는지 나타내는 수. 따라서 이가 n/2보다 작으면 space 출력 전에 이를 출력해 줘야함.
         {
            for (int j = 0; j < i; j++)
               printf("▩");
            printf("●");
            for (int k = 0; k < n - 2 * i; k++)
               printf("  ");
            for (int h = 0; h < i; h++)
               printf("▩");
            printf("\n");
         }
         else //위와 같은 이유로, space를 출력한 후에 출력해야함.
         {
            for (int j = 0; j < i; j++)
               printf("▩");
            for (int k = 0; k < n - 2 * i; k++)
               printf("  ");
            printf("●");
            for (int h = 0; h < i; h++)
               printf("▩");
            printf("\n");
         }
      }
      else
      {
         if (p < n / 2)
         {
            for (int j = 0; j < i; j++)
               printf("▩");
            printf("○");
            for (int k = 0; k < n - 2 * i; k++)
               printf("  ");
            for (int h = 0; h < i; h++)
               printf("▩");
            printf("\n");
         }
         else
         {
            for (int j = 0; j < i; j++)
               printf("▩");
            for (int k = 0; k < n - 2 * i; k++)
               printf("  ");
            printf("○");
            for (int h = 0; h < i; h++)
               printf("▩");
            printf("\n");
         }
      }
   }
}

void generate_two_numbers(int * n1, int * n2)
{
   srand(time(NULL)); //time을 seed로 받아 난수 출력. 시간은 항상 변하므로.
   *n1 = rand() % 3 + 1; //범위가 3, 최소값이 1인 난수 들(1~3) 중 하나를 받는다.
   do
   {
      *n2 = rand() % 3 + 1;
   } while (*n1 == *n2); // *n1과 다른 값이 나올 때까지 범위가 3, 최소값이 1인 난수 들(1~3) 중 하나를 받는다.
}

int pick_one_computer(int c1, int c2, int u1, int u2)
{
   if (c1 == u1 && c2 == u2)
   {
      if (c1 == 3 && c2 == 1)
         return 1;
      else return c1;
   } /* (컴퓨터 큰 수)=(사용자 큰 수) && (컴퓨터 작은 수)=(사용자 작은 수) 가 아니면 이 조건문을 실행하지 않고,
     만약 맞다면 이 조건문 실행하고 return 을 통해 이 함수를 호출한 함수로 돌아감.*/

   srand(time(NULL));
   if (rand() % 2 + 1 == 1) //임의의 숫자와 c1,c2를 대응해 둘 중 한 수를 반환.
      return c1;
   else return c2;
}

void print_one(int n)
{
   if (n == 1)
   {
      printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
      printf("│         ▩▩                │\n");
      printf("│       ▩▩                  │\n");
      printf("│     ▩▩                    │\n");
      printf("│   ▩▩▩▩▩▩▩▩▩▩▩    │\n");
      printf("│ ▩▩▩▩▩▩▩              │\n");
      printf("│ ▩▩▩▩▩▩▩▩            │\n");
      printf("│ ▩▩▩▩▩▩▩▩            │\n");
      printf("│ ▩▩▩▩▩▩▩▩            │\n");
      printf("│ ▩▩▩▩▩▩▩              │\n");
      printf("│   ▩▩▩▩▩                │\n");
      printf("│     ▩▩▩                  │\n");
      printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
   }
   else if (n == 2)
   {
      printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
      printf("│                             │\n");
      printf("│        ▩▩▩               │\n");
      printf("│     ▩▩▩▩▩              │\n");
      printf("│   ▩▩▩▩▩▩▩            │\n");
      printf("│ ▩▩▩▩▩▩▩▩▩          │\n");
      printf("│ ▩▩▩▩▩▩▩▩▩          │\n");
      printf("│ ▩▩▩▩▩▩▩▩▩          │\n");
      printf("│ ▩▩▩▩▩▩▩▩▩          │\n");
      printf("│ ▩▩▩▩▩▩▩▩            │\n");
      printf("│   ▩▩▩▩▩▩              │\n");
      printf("│     ▩▩▩▩                │\n");
      printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
   }
   else
   {
      printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
      printf("│                             │\n");
      printf("│      ▩▩▩▩▩             │\n");
      printf("│     ▩▩▩                  │\n");
      printf("│   ▩▩▩▩▩▩▩▩▩▩▩    │\n");
      printf("│ ▩▩▩▩▩▩▩▩            │\n");
      printf("│ ▩▩▩▩▩▩▩▩▩▩▩▩▩▩│\n");
      printf("│ ▩▩▩▩▩▩▩▩▩          │\n");
      printf("│ ▩▩▩▩▩▩▩▩▩▩▩▩▩  │\n");
      printf("│ ▩▩▩▩▩▩▩▩            │\n");
      printf("│   ▩▩▩▩▩▩▩▩▩▩▩    │\n");
      printf("│     ▩▩▩▩▩              │\n");
      printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
   }
}

void print_rock_scissors(void)
{
   printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("│                             │ │         ▩▩                │\n");
   printf("│        ▩▩▩               │ │       ▩▩                  │\n");
   printf("│     ▩▩▩▩▩              │ │     ▩▩                    │\n");
   printf("│   ▩▩▩▩▩▩▩            │ │   ▩▩▩▩▩▩▩▩▩▩▩    │\n");
   printf("│ ▩▩▩▩▩▩▩▩▩          │ │ ▩▩▩▩▩▩▩              │\n");
   printf("│ ▩▩▩▩▩▩▩▩▩          │ │ ▩▩▩▩▩▩▩▩            │\n");
   printf("│ ▩▩▩▩▩▩▩▩▩          │ │ ▩▩▩▩▩▩▩▩            │\n");
   printf("│ ▩▩▩▩▩▩▩▩▩          │ │ ▩▩▩▩▩▩▩▩            │\n");
   printf("│ ▩▩▩▩▩▩▩▩            │ │ ▩▩▩▩▩▩▩              │\n");
   printf("│   ▩▩▩▩▩▩              │ │   ▩▩▩▩▩                │\n");
   printf("│     ▩▩▩▩                │ │     ▩▩▩                  │\n");
   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void print_paper_rock(void)
{
   printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("│                             │ │                             │\n");
   printf("│      ▩▩▩▩▩             │ │        ▩▩▩               │\n");
   printf("│     ▩▩▩                  │ │     ▩▩▩▩▩              │\n");
   printf("│   ▩▩▩▩▩▩▩▩▩▩▩    │ │   ▩▩▩▩▩▩▩            │\n");
   printf("│ ▩▩▩▩▩▩▩▩            │ │ ▩▩▩▩▩▩▩▩▩          │\n");
   printf("│ ▩▩▩▩▩▩▩▩▩▩▩▩▩▩│ │ ▩▩▩▩▩▩▩▩▩          │\n");
   printf("│ ▩▩▩▩▩▩▩▩▩          │ │ ▩▩▩▩▩▩▩▩▩          │\n");
   printf("│ ▩▩▩▩▩▩▩▩▩▩▩▩▩  │ │ ▩▩▩▩▩▩▩▩▩          │\n");
   printf("│ ▩▩▩▩▩▩▩▩            │ │  ▩▩▩▩▩▩▩▩           │\n");
   printf("│   ▩▩▩▩▩▩▩▩▩▩▩    │ │    ▩▩▩▩▩▩             │\n");
   printf("│     ▩▩▩▩▩              │ │      ▩▩▩▩               │\n");
   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void print_scissors_paper(void)
{
   printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("│         ▩▩                │ │                             │\n");
   printf("│       ▩▩                  │ │      ▩▩▩▩▩             │\n");
   printf("│     ▩▩                    │ │     ▩▩▩                  │\n");
   printf("│   ▩▩▩▩▩▩▩▩▩▩▩    │ │   ▩▩▩▩▩▩▩▩▩▩▩    │\n");
   printf("│ ▩▩▩▩▩▩▩              │ │ ▩▩▩▩▩▩▩▩            │\n");
   printf("│ ▩▩▩▩▩▩▩▩            │ │ ▩▩▩▩▩▩▩▩▩▩▩▩▩▩│\n");
   printf("│ ▩▩▩▩▩▩▩▩            │ │ ▩▩▩▩▩▩▩▩▩          │\n");
   printf("│ ▩▩▩▩▩▩▩▩            │ │ ▩▩▩▩▩▩▩▩▩▩▩▩▩  │\n");
   printf("│ ▩▩▩▩▩▩▩              │ │ ▩▩▩▩▩▩▩▩            │\n");
   printf("│   ▩▩▩▩▩                │ │   ▩▩▩▩▩▩▩▩▩▩▩    │\n");
   printf("│     ▩▩▩                  │ │     ▩▩▩▩▩              │\n");
   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
