#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_symmetric(const short *first, const short *last)
{
    size_t size = last - first; 
    size_t n = (size_t)sqrt(size);

    if (n * n != size)
    {
        return false;
    }

    for (int w = 0; w < n; w++)
    {
        for (int k = 0; k < n; k++)
        {
            if ((w != k) && (*(first + w * n + k) != *(first + k * n + w)))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    short tab1[3][3] = {1, 2, 3, 2, 1, 3, 3, 3, 1};
    short tab2[3][3] = {1, 2, 3, 2, 1, 3, 4, 3, 1};

    if (is_symmetric(*tab1, &tab1[2][2] + 1))
    {
        printf("tab1 jest symetryczna\n");
    }
    else
    {
        printf("tab1 nie jest symetryczna\n");
    }

    if (is_symmetric(*tab2, &tab2[2][2] + 1))
    {
        printf("tab2 jest symetryczna\n");
    }
    else
    {
        printf("tab2 nie jest symetryczna\n");
    }

    return 0;
}