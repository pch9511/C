
#include <stdio.h>
#include <string.h>

/*
T - Test 횟수      - 5회 이하
N - N x N map    - 10이상 30 이하

1 - 벽
3 - 출발지
4 - 도착지

N x N map에서 출발지 부터 도착지 까지 가장 짧은 path의 길이를 출력하라
폭탄 제거기는 3개마 있다.  4버째 폭탄을 만나면, 다른 길을 찾아야 한다.

(ex)
T = 1
N = 6

1 1 1 1 1 1
1 2 2 4 0 1
1 2 2 2 0 1
1 2 2 0 0 1
1 3 0 2 0 1
1 1 1 1 1 1

출력
#=5

*/

#define DEBUG 1

#define MAX_T 5
#define MAX_N 30


#define WW (1)
#define SS (3)
#define DD (4)
#define TT (5)
/*지나간 자리*/

#if (DEBUG)
#define LL //
#define NN 20
#else
#define LL 
#define NN MAX_N
#endif

int T = 1;
int N = NN;


#if (DEBUG)
int map[NN][NN] = {
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
 1, 3, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1,
 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1,
 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1,
 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1,
 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1,
 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1,
 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1,
 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1,
 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1,
 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1,
 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1,
 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1,
 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1,
 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1,
 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1,
 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 4, 1,
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
int map_cp[NN][NN] = { 0 };
#else
int map[MAX_N][MAX_N] = { 0 };
int map_cp[MAX_N][MAX_N] = { 0 };
#endif

int path_log[MAX_N * MAX_N][2];

int path_count = 0;
int Min_Path_Count = 9999;
int g_start_x;
int g_start_y;
int g_end_x;
int g_end_y;


typedef struct pos {
 int x;
 int y;
 int dl;
 int dr;
 int du;
 int dd;
} pos;

#define STACK_MAX 10000
struct pos pool[STACK_MAX];
int stack_idx = -1;


/////////////////////////////////////////
void get_input()
{
 int x;
 int y;

 scanf_s("%d", &N);

 for (y = 0; y<N; y++)
 {
  for (x = 0; x<N; x++)
  {
   scanf_s("%d", &map[y][x]);
  }
 }
}

/////////////////////////////////////////
void copy_map(int init)
{
 int x;
 int y;

 for (y = 0; y<N; y++)
 {
  for (x = 0; x<N; x++)
  {
   map_cp[y][x] = map[y][x];
  }
 }
}


/////////////////////////////////////////
void print_map(int select)
{
 int x;
 int y;

 printf("======================\n");
 printf("print input\n");
 printf("======================\n");
 for (y = 0; y<N; y++)
 {
  for (x = 0; x<N; x++)
  {
   if (select == 0)
   {
    printf("%d ", map[y][x]);
   }
   else
   {
    printf("%d ", map_cp[y][x]);
   }
  }
  printf("\n");
 }
 printf("======================\n");
}


/////////////////////////////////////////
void get_start_point(int * start_x, int * start_y)
{
 int x;
 int y;

 for (y = 0; y<N; y++)
 {
  for (x = 0; x<N; x++)
  {
   if (map[y][x] == SS)
   {
    *start_x = x;
    *start_y = y;
   }
  }
 }
}


/////////////////////////////////////////
void get_end_point(int *end_x, int * end_y)
{
 int x;
 int y;

 for (y = 0; y<N; y++)
 {
  for (x = 0; x<N; x++)
  {
   if (map[y][x] == DD)
   {
    *end_x = x;
    *end_y = y;
   }
  }
 }
}


/////////////////////////////////////////
int push(pos newp)
{
 if (stack_idx >= (STACK_MAX - 1))
 {
  printf("Stack Full\n");
  while (1);
 }

 stack_idx++;
 pool[stack_idx] = newp;

 return 0;
}


/////////////////////////////////////////
int push_no_dir(int x, int y)
{
 if (stack_idx >= (STACK_MAX - 1))
 {
  return -1;
 }

 stack_idx++;
 pool[stack_idx].x = x;
 pool[stack_idx].y = y;
 pool[stack_idx].dl = 0;
 pool[stack_idx].dr = 0;
 pool[stack_idx].du = 0;
 pool[stack_idx].dd = 0;

 return 0;
}


/////////////////////////////////////////
int pop(pos *old)
{
 if (stack_idx < 0) {
  printf("Stack Empty\n");
  return -1;
 }

 *old = pool[stack_idx];

 if (stack_idx > 0)
  stack_idx--;

 return 0;
}


/////////////////////////////////////////
int clear_path()
{
 stack_idx = 0;

 while (1)
 {
  if (push_no_dir(0, 0) < 0)
   break;
 }

 stack_idx = -1;

 return 0;
}


/////////////////////////////////////////
#define DOWN 1
#define RIGHT 2
#define UP  3
#define LEFT 4


int get_direction(int sx, int sy, int ex, int ey, int *DIR)
{
 int x_dir1;
 int x_dir2;
 int y_dir1;
 int y_dir2;

 int x_dif;
 int y_dif;

 if (sx < ex) {
  x_dir1 = RIGHT;
  x_dir2 = LEFT;
  x_dif = ex - sx;
 }
 else {
  x_dir1 = LEFT;
  x_dir2 = RIGHT;
  x_dif = sx - ex;
 }

 if (sy < ey) {
  y_dir1 = DOWN;
  y_dir2 = UP;
  y_dif = ey - sy;
 }
 else {
  y_dir1 = UP;
  y_dir2 = DOWN;
  y_dif = sy - ey;
 }

 if (x_dif < y_dif) {
  DIR[0] = y_dir1;
  DIR[1] = x_dir1;
  DIR[2] = y_dir2;
  DIR[3] = x_dir2;
 }
 else {
  DIR[0] = x_dir1;
  DIR[1] = y_dir1;
  DIR[2] = x_dir2;
  DIR[3] = y_dir2;
 }

 return 0;
}



/////////////////////////////////////////
int search_short_path(pos start)
{
 pos p;
 int i = 0;
 int dir;
 int DIR[4];

 p = start;

 if ((p.x == g_end_x) && (p.y == g_end_y))
 {
  return stack_idx;
 }

 get_direction(p.x, p.y, g_end_x, g_end_y, &DIR[0]);

 i = 0;

 while (1)
 {
  i++;
  if (i > 3)   i = 0;

  dir = DIR[i];

  switch (dir)
  {
  case DOWN:
   if (p.dd == 0) // DOWN
   {
    if ((map_cp[p.y + 1][p.x] == 0) || (map_cp[p.y + 1][p.x] == DD))
    {
     p.y++;
     map_cp[p.y][p.x] = 5;
     push(p);
     p.dr = p.dl = p.du = p.dd = 0;
     return search_short_path(p);
    }
   }
   p.dd = 1;
   break;

  case RIGHT:
   if (p.dr == 0) // RIGHT
   {
    if ((map_cp[p.y][p.x + 1] == 0) || (map_cp[p.y][p.x + 1] == DD))
    {
     p.x++;
     map_cp[p.y][p.x] = 5;
     push(p);
     p.dr = p.dl = p.du = p.dd = 0;
     return search_short_path(p);
    }
   }
   p.dr = 1;
   break;

  case UP:
   if (p.du == 0) // UP
   {
    if ((map_cp[p.y - 1][p.x] == 0) || (map_cp[p.y - 1][p.x] == DD))
    {
     p.y--;
     map_cp[p.y][p.x] = 5;
     push(p);
     p.dr = p.dl = p.du = p.dd = 0;
     return search_short_path(p);
    }
   }
   p.du = 1;
   break;

  case LEFT:
   if (p.dl == 0) // LEFT
   {
    if ((map_cp[p.y][p.x - 1] == 0) || (map_cp[p.y][p.x - 1] == DD))
    {
     p.x--;
     map_cp[p.y][p.x] = 5;
     push(p);
     p.dr = p.dl = p.du = p.dd = 0;
     return search_short_path(p);
    }
   }
   p.dl = 1;
   break;

  default:
   break;
  }

  if ((p.dd == 1) && (p.du == 1) && (p.dl == 1) && (p.dr == 1))
  {
   map_cp[p.y][p.x] = 8;

   pos np;
   np.x = -1;
   // 방향 없음. Back 해야함.
   printf("NO WAY\n");

   while (1)
   {
    if (pop(&np) < 0) {
     printf("NO WAY\ - Failn\n");
     return -1;
    }

    if ((np.x != p.x) || (np.y != p.y))
    {
     break;
    }
   }

   return search_short_path(np);
  }
 }

 return -1;
}



/////////////////////////////////////////
int main()
{
 int i;
 int start_x;
 int start_y;
 int end_x;
 int end_y;
 int result;

#if !(DEBUG)
 scanf("&d", &T);
#else
 T = 1;
#endif

 for (i = 0; i<T; i++)
 {
#if !(DEBUG)
  LL printf("get input\n");
  get_input();
#endif
  get_start_point(&start_x, &start_y);
  get_end_point(&end_x, &end_y);

  LL printf("start [x:y] = [%d:%d]\n", start_x, start_y);
  LL printf("end   [x:y] = [%d:%d]\n", end_x, end_y);

  g_start_x = start_x;
  g_start_y = start_y;
  g_end_x   = end_x;
  g_end_y   = end_y;

  pos start;
  start.x = start_x;
  start.y = start_y;
  start.dd = 0;
  start.dl = 0;
  start.dr = 0;
  start.du = 0;
 
  clear_path();
  copy_map(0);

  map_cp[start.y][start.x] = 5;
  push(start);
  result = search_short_path(start);
  
  printf("#%d\n", result);
 }

 LL print_map(0);
 LL print_map(1);

 printf("Done - press Key\n");
 getchar();
 return 0;
}
