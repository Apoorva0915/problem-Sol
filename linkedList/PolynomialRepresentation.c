#include <stdio.h>
#include <malloc.h>

struct Node
{
    int coe;
    int pow;
    struct Node *next;
};

struct Node *createNode(int coe, int pow)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coe = coe;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void addLast(struct Node **s, int coe, int pow)
{
    struct Node *newNode = createNode(coe, pow);
    if (*s == NULL)
    {
        *s = newNode;
    }
    else
    {
        struct Node *temp = *s;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node *addPolynomial(struct Node *s1, struct Node *s2)
{
    struct Node *s3 = NULL;
    while (s1 != NULL && s2 != NULL)
    {
        if (s1->pow == s2->pow)
        {
            addLast(&s3, s1->coe + s2->coe, s1->pow);
            s1 = s1->next;
            s2 = s2->next;
        }
        else if (s1->pow > s2->pow)
        {
            addLast(&s3, s1->coe, s1->pow);
            s1 = s1->next;
        }
        else
        {
            addLast(&s3, s2->coe, s2->pow);
            s2 = s2->next;
        }
    }

    while (s1 != NULL)
    {
        addLast(&s3, s1->coe, s1->pow);
        s1 = s1->next;
    }
    while (s2 != NULL)
    {
        addLast(&s3, s2->coe, s2->pow);
        s2 = s2->next;
    }
    return s3;
}

void show(struct Node *temp)
{
    printf("%dX^%d ", temp->coe, temp->pow);
    temp = temp->next;
    while (temp != NULL)
    {
        if (temp->pow != 0)
        {
            if (temp->coe > 0)
            {
                printf("+%dX^%d ", temp->coe, temp->pow);
            }
            else
            {
                printf("%dX^%d ", temp->coe, temp->pow);
            }
        }
        else
        {
            if (temp->coe > 0)
            {
                printf("+%d", temp->coe);
            }
            else
            {
                printf("%d", temp->coe);
            }
        }
        temp = temp->next;
    }
}

int main()
{
    struct Node *poly1 = NULL;
    addLast(&poly1, 2, 5);
    addLast(&poly1, -39, 3);
    addLast(&poly1, 1, 0);

    struct Node *poly2 = NULL;
    addLast(&poly2, 5, 6);
    addLast(&poly2, -50, 3);
    addLast(&poly2, 8, 0);

    struct Node *poly3 = NULL;
    poly3 = addPolynomial(poly1, poly2);

    show(poly1);
    printf("\n");
    show(poly2);
    printf("\nPolynomial Addition\n");
    show(poly3);
}