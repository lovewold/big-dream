//////#define _CRT_SECURE_NO_WARNINGS 1
////////////#include <iostream>
////////////#include<string>
////////////
////////////using namespace std;
////////////
////////////int f(int n)
////////////{
////////////	if (n == 1) return 1;
////////////	if (n == 2) return 2;
////////////	return f(n - 1) + f(n - 2);
////////////}
////////////int main()
////////////{
////////////	int n;
////////////	cin >> n;
////////////	cout << f(n) << endl;
////////////	return ;
////////////}
//////////
//////////#include<iostream>
//////////#include<cstdio>
//////////#include<cstring>
//////////#include<vector>
//////////using namespace std;
//////////
//////////const int N = 10;
//////////int n;
//////////int state[N];
//////////bool used[N];
//////////
//////////void dfs(int u)
//////////{
//////////    if (u > n)
//////////    {
//////////        for (int i = 1; i <= n; i++) printf("%d ", state[i]);
//////////        puts("");
//////////        return;
//////////    }
//////////    for (int i = 1; i <= n; i++)
//////////    {
//////////        if (!used[i])
//////////        {
//////////            state[u] = i;
//////////            used[i] = true;
//////////            dfs(u + 1);
//////////
//////////            state[u] = 0;
//////////            used[i] = false;
//////////
//////////        }
//////////    }
//////////}
//////////int main()
//////////{
//////////    cin >> n;
//////////
//////////    dfs(1);
//////////    return 0;
//////////}
////////#include<iostream>
////////#include<cstring>
////////#include<cstdio>
////////#include<algorithm>
////////
////////using namespace std;
////////
////////const int N = 6;
////////char R[N][N], backup[N][N];
////////
////////int dx[5] = { -1,0,1,0,0 }, dy[5] = { 0,1,0,-1,0 };
////////
////////void ture(int x, int y)
////////{
////////    for (int i = 0; i < 5; i++)
////////    {
////////        int a = x + dx[i];
////////        int b = y + dy[i];
////////        if (a < 0 || a >= 5 || b < 0 || b >= 5)
////////            continue;
////////        R[a, b] ^= 1;
////////    }
////////}
////////
////////int main()
////////{
////////    int t = 0;
////////    cin >> t;
////////    while (t--)
////////    {
////////        for (int i = 0; i < t; i++) cin >> R[i];
////////
////////        int op = 32;
////////        int res = 10;
////////        for (op = 0; op < 32; op++)
////////        {
////////            memcpy(backup, R, sizeof R);//拷贝避免影响原始数组
////////            int step = 0;
////////
////////            for (int i = 0; i < 5; i++)
////////            {
////////                if (op >> i & 1)
////////                {
////////                    step++;
////////                    ture(0, i);
////////                }
////////            }
////////
////////            for (int i = 1; i < 5; i++)
////////            {
////////                for (int j = 0; j < 5; j++)
////////                    if (R[i - 1][j] == '0')
////////                        ture(i, j);
////////                step++;
////////            }
////////        }
////////        bool open = ture;
////////        for (int i = 0; i < 5; i++)
////////        {
////////            if (!R[4][i])
////////                open = false;//黑
////////            break;
////////        }
////////        if (open) res = min(res, step);
////////        memcpy(R, backup, sizeof backup);
////////        if (res > 6)
////////            res = -1;
////////        cout << res << endl;
////////
////////    }
////////
////////
////////    return 0;
////////}
//////#include<iostream>
//////#include<cstring>
//////#include<cstdio>
//////#include<algorithm>
//////
//////using namespace std;
//////
//////const int N = 6;
//////char R[N][N], backup[N][N];
//////
//////int dx[5] = { -1,0,1,0,0 }, dy[5] = { 0,1,0,-1,0 };
//////
//////void ture(int x, int y)
//////{
//////    for (int i = 0; i < 5; i++)
//////    {
//////        int a = x + dx[i];
//////        int b = y + dy[i];
//////        if (a < 0 || a >= 5 || b < 0 || b >= 5)
//////            continue;
//////        R[a][b] ^= 1;
//////    }
//////}
//////
//////int main()
//////{
//////    int t = 0;
//////    cin >> t;
//////    while (t--)
//////    {
//////        for (int i = 0; i < t; i++) cin >> R[i];
//////
//////        int op = 32;
//////        int res = 10;
//////        for (op = 0; op < 32; op++)
//////        {
//////            memcpy(backup, R, sizeof R);//拷贝避免影响原始数组
//////            int step = 0;
//////
//////            for (int i = 0; i < 5; i++)
//////            {
//////                if (op >> i & 1)
//////                {
//////                    step++;
//////                    ture(0, i);
//////                }
//////            }
//////
//////            for (int i = 1; i < 5; i++)
//////            {
//////                for (int j = 0; j < 5; j++)
//////                {
//////                    if (R[i - 1][j] == '0')
//////                        ture(i, j);
//////                    step++;
//////                }
//////            }
//////            bool open = true;
//////            for (int i = 0; i < 5; i++)
//////            {
//////                if (R[4][i] == '0')
//////                {
//////                    open = false;//黑
//////                    break;
//////                }
//////            }
//////
//////            if (open)
//////            {
//////                res = min(res, step);
//////            }
//////            memcpy(R, backup, sizeof backup);
//////            if (res > 6)
//////                res = -1;
//////        }
//////        
//////        cout << res << endl;
//////
//////    }
//////
//////
//////    return 0;
//////}
////
////#include<iostream>
////#include<cstring>
////#include<cstdio>
////#include<algorithm>
////
////using namespace std;
////
////const int N = 6;
////char R[N][N], backup[N][N];
////
////int dx[5] = { -1,0,1,0,0 }, dy[5] = { 0,1,0,-1,0 };
////
////void ture(int x, int y)
////{
////    for (int i = 0; i < 5; i++)
////    {
////        int a = x + dx[i];
////        int b = y + dy[i];
////        if (a < 0 || a >= 5 || b < 0 || b >= 5)
////            continue;
////        R[a][b] ^= 1;
////    }
////}
////
////int main()
////{
////    int t = 0;
////    cin >> t;
////    while (t--)
////    {
////        for (int i = 0; i < 5; i++) cin >> R[i];
////
////        int op = 32;
////        int res = 10;
////        for (op = 0; op < 32; op++)
////        {
////            memcpy(backup, R, sizeof R);//拷贝避免影响原始数组
////            int step = 0;
////
////            for (int i = 0; i < 5; i++)
////            {
////                if (op >> i & 1)
////                {
////                    step++;
////                    ture(0, 4 - i);
////                }
////            }
////
////            for (int i = 1; i < 5; i++)
////            {
////                for (int j = 0; j < 5; j++)
////                {
////                    if (R[i - 1][j] == '0')
////                    {
////                        ture(i, j);
////                        step++;
////                    }
////                        
////                }
////            }
////            bool open = true;
////            for (int i = 0; i < 5; i++)
////            {
////                if (R[4][i] == '0')
////                {
////                    open = false;//黑
////                    break;
////                }
////            }
////            if (open) res = min(res, step);
////            if (res > 6)
////                res = -1;
////            memcpy(R, backup, sizeof backup);
////
////        }
////
////        cout << res << endl;
////
////    }
////
////
////    return 0;
////}
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 6;
//char R[N][N], backup[N][N];
//
//int dx[5] = { -1,0,1,0,0 }, dy[5] = { 0,1,0,-1,0 };
//
//void ture(int x, int y)
//{
//    for (int i = 0; i < 5; i++)
//    {
//        int a = x + dx[i];
//        int b = y + dy[i];
//        if (a < 0 || a >= 5 || b < 0 || b >= 5)
//            continue;
//        R[a][b] ^= 1;
//    }
//}
//
//int main()
//{
//    int t = 0;
//    cin >> t;
//    while (t--)
//    {
//        for (int i = 0; i < t; i++) cin >> R[i];
//
//        int op = 32;
//        int res = 10;
//        for (op = 0; op < 32; op++)
//        {
//            memcpy(backup, R, sizeof R);//拷贝避免影响原始数组
//            int step = 0;
//
//            for (int i = 0; i < 5; i++)
//            {
//                if (op >> i & 1)
//                {
//                    step++;
//                    ture(0, i);
//                }
//            }
//
//            for (int i = 1; i < 5; i++)
//            {
//                for (int j = 0; j < 5; j++)
//                {
//                    if (R[i - 1][j] == '0')
//                        ture(i, j);
//                    step++;
//                }
//            }
//            bool open = true;
//            for (int i = 0; i < 5; i++)
//            {
//                if (R[4][i] == '0')
//                {
//                    open = false;//黑
//                    break;
//                }
//
//            }
//            if (open) res = min(res, step);
//        }
//        memcpy(R, backup, sizeof backup);
//        if (res > 6)
//            res = -1;
//
//        cout << res << endl;
//    }
//    
//
//
//    return 0;
//}
//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//void tast(int n)
//{
//    int r = ((n + 1)/2);
//    
//    printf("%d", r);
//
//}
//int main()
//{
//    int n;
//    cin >> n;
//    tast(n);
//    return 0;
//}

#include<iostream>
#include<cstdio>
using namespace std;

void tast(int n)
{
    int left = 1;
    int right = n;
    int t = 0;
    while (left < right&&(right-left!=1))
    {
        int mid = (left + right) / 2;
        left = mid;
        t++;
    }
    cout << t << endl;
    return;
}
int main()
{
    int n;
    cin >> n;
    tast(n);
    return 0;
}