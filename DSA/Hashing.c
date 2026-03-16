/*Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine the records in file F. 
Assume that file F is maintained in memory by a Hash Table (HT) of m memory locations with L as the set of memory addresses (2-digit) of locations in HT.
Let the keys in K and addresses in L are Integers.
Develop a Program in C that uses Hash function H: K →L as H(K)=K mod m (remainder method), 
and implement hashing technique to map a given key K to the address space L. Resolve the collision (if any) using linear probing.*/


#include <stdio.h>
#include <stdlib.h>

int *ht, m;
int count = 0;
int idx;

void insert(int key)
{
    idx = key % m;

    while (ht[idx] != -1)
    {
        idx = (idx + 1) % m;
    }
    ht[idx] = key;
    count++;
}

void display()
{
    if (count == 0)
    {
        printf("\nHash Table is empty");
        return;
    }

    printf("\nHash Table contents:\n");
    for (int i = 0; i < m; i++)
        printf("T[%d] -> %d\n", i, ht[i]);
}

int main()
{
    FILE *fp;
    int key, n;

    printf("Enter number of records: ");
    scanf("%d", &n);

    printf("Enter the two digit memory locations (m) for hash table: ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        ht[i] = -1;

    fp = fopen("Hashing_numbers.txt", "r");

    for (int i = 0; i < n; i++)
    {
        if (count == m)
        {
            printf("\nHash table is full");
            break;
        }

        fscanf(fp, "%d", &key);
        insert(key);
    }

    display();
    return 0;
}

