#include <stdio.h>

#define MAX 100


int isMember(int set[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (set[i] == element)
            return 1;
    }
    return 0;
}


int insert(int set[], int n, int element) {
    if (isMember(set, n, element)) {
        printf("Element already exists in the set.\n");
        return n;
    }
    set[n] = element;
    return n + 1;
}


int deleteElement(int set[], int n, int element) {
    if (!isMember(set, n, element)) {
        printf("Element not found in the set.\n");
        return n;
    }
    int i, j;
    for (i = 0; i < n; i++) {
        if (set[i] == element) {
            for (j = i; j < n - 1; j++)
                set[j] = set[j + 1];
            break;
        }
    }
    return n - 1;
}


void display(int set[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++)
        printf("%d ", set[i]);
    printf("}\n");
}


int setUnion(int A[], int nA, int B[], int nB, int U[]) {
    int k = 0;

 
    for (int i = 0; i < nA; i++)
        U[k++] = A[i];

 
    for (int i = 0; i < nB; i++) {
        if (!isMember(A, nA, B[i]))
            U[k++] = B[i];
    }
    return k;
}

int setIntersection(int A[], int nA, int B[], int nB, int I[]) {
    int k = 0;
    for (int i = 0; i < nA; i++) {
        if (isMember(B, nB, A[i]))
            I[k++] = A[i];
    }
    return k;
}


int setDifference(int A[], int nA, int B[], int nB, int D[]) {
    int k = 0;
    for (int i = 0; i < nA; i++) {
        if (!isMember(B, nB, A[i]))
            D[k++] = A[i];
    }
    return k;
}

int main() {
    int setA[MAX], setB[MAX], result[MAX];
    int nA = 0, nB = 0, nR;
    int choice, element;

    while (1) {
        printf("\n----- SET OPERATIONS -----\n");
        printf("1. Insert into Set A\n");
        printf("2. Delete from Set A\n");
        printf("3. Search element in Set A\n");
        printf("4. Display Set A\n");
        printf("5. Union (A ∪ B)\n");
        printf("6. Intersection (A ∩ B)\n");
        printf("7. Difference (A - B)\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to insert into Set A: ");
            scanf("%d", &element);
            nA = insert(setA, nA, element);
            break;

        case 2:
            printf("Enter element to delete from Set A: ");
            scanf("%d", &element);
            nA = deleteElement(setA, nA, element);
            break;

        case 3:
            printf("Enter element to search in Set A: ");
            scanf("%d", &element);
            if (isMember(setA, nA, element))
                printf("Element found in Set A.\n");
            else
                printf("Element NOT found in Set A.\n");
            break;

        case 4:
            printf("Set A: ");
            display(setA, nA);
            break;

        case 5:
            printf("Enter number of elements in Set B: ");
            scanf("%d", &nB);
            printf("Enter elements of Set B:\n");
            for (int i = 0; i < nB; i++)
                scanf("%d", &setB[i]);

            nR = setUnion(setA, nA, setB, nB, result);
            printf("A ∪ B = ");
            display(result, nR);
            break;

        case 6:
            printf("Enter number of elements in Set B: ");
            scanf("%d", &nB);
            printf("Enter elements of Set B:\n");
            for (int i = 0; i < nB; i++)
                scanf("%d", &setB[i]);

            nR = setIntersection(setA, nA, setB, nB, result);
            printf("A ∩ B = ");
            display(result, nR);
            break;

        case 7:
            printf("Enter number of elements in Set B: ");
            scanf("%d", &nB);
            printf("Enter elements of Set B:\n");
            for (int i = 0; i < nB; i++)
                scanf("%d", &setB[i]);

            nR = setDifference(setA, nA, setB, nB, result);
            printf("A - B = ");
            display(result, nR);
            break;

        case 8:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
