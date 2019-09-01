#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Map
{
    int x;
    int y;
}Map;
 
Map map[100001];
 
int N = 0;
 
void Swap(int a, int b)
{
    Map temp = map[a];
    map[a] = map[b];
    map[b] = temp;
}
 
int partitionX(int start, int end)
{
    Map pivot = map[end];
    int left = start;
    int right = end;
 
    while (left < right)
    {
        while (map[left].x <= pivot.x && left < right)
        {
            ++left;
        }
 
        while (map[right].x >= pivot.x && left < right)
        {
            --right;
        }
 
        if (left < right)
        {
            Swap(left, right);
        }
    }
 
    Swap(right, end);
 
    return right;
}
 
void quickSortX(int start, int end)
{
    int pivot = 0;
 
    if (start < end)
    {
        pivot = partitionX(start, end);
        quickSortX(start, pivot - 1);
        quickSortX(pivot + 1, end);
    }
}
 
int partitionY(int start, int end)
{
    Map pivot = map[end];
    int left = start;
    int right = end;
 
    while (left < right)
    {
        while (map[left].y <= pivot.y && left < right)
        {
            ++left;
        }
 
        while (map[right].y >= pivot.y && left < right)
        {
            --right;
        }
 
        if (left < right)
        {
            Swap(left, right);
        }
    }
 
    Swap(right, end);
 
    return right;
}
 
void quickSortY(int start, int end)
{
    int pivot = 0;
 
    if (start < end)
    {
        pivot = partitionY(start, end);
        quickSortY(start, pivot - 1);
        quickSortY(pivot + 1, end);
    }
}
 
int main(void)
{
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &map[i].x, &map[i].y);
    }
 
    quickSortX(0, N - 1);
 
    int start = 0;
    int end = N - 1;
    int cnt = 0;
 
    for (int i = 0; i < N - 1; i++)
    {
        while (map[i].x == map[i + 1].x)
        {
            end = i + 1;
            ++cnt;
            ++i;
        }
 
        if (cnt >= 1)
        {        
            start = end - cnt;
            quickSortY(start, end);
        }
 
        cnt = 0;
    }
 
    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", map[i].x, map[i].y);
    }
 
    return 0;
}
