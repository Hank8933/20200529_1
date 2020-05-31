#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct POINT{
    double x, y;
}poi;

typedef struct TRIANGLE{
    poi a, b, c;
}tri;

void poiToTri(int n, poi p[], tri t[])
{
    for(int i = 0, j = 1; i < n-2; i++){
        t[i].a = p[0];
        t[i].b = p[j++];
        t[i].c = p[j];
    }
}

int main()
{
    //freopen("list", "r", stdin);
    int n;
    scanf("%d", &n);
    poi pois[n];
    tri tris[n-2];
    double area = 0;
    for(int i = 0; i < n; i++){
        scanf("%lf %lf", &pois[i].x, &pois[i].y);
    }

    poiToTri(n, pois, tris);
/*
    for(int i = 0; i < n-2; i++){
        printf("%d %d\n", tris[i].a.x, tris[i].a.y);
        printf("%d %d\n", tris[i].b.x, tris[i].b.y);
        printf("%d %d\n\n", tris[i].c.x, tris[i].c.y);
    }
*/
    for(int i = 0; i < n-2; i++){
        area += fabs((tris[i].a.x * (tris[i].b.y - tris[i].c.y)\
                            + tris[i].b.x * (tris[i].c.y - tris[i].a.y)\
                            + tris[i].c.x * (tris[i].a.y - tris[i].b.y)) / 2);
    }

    printf("area: %.2f\n", area);
    return 0;
}
