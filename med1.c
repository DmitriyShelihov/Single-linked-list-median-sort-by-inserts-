#include "med1.h"

void list_insert_sort(LIST** lst, double number)
{
    assert(lst != NULL);

    LIST* new_lst = (LIST*)malloc(sizeof(LIST));
    new_lst->value = number;
    new_lst->next = NULL;
    LIST* save_lst = list;

    if (number < list->value)
    {
        new_lst->next = list;
        list = new_lst;
        return;
    }

    while (list->next != NULL)
    {
        if (number >= list->value && (number <= list->next->value))
        {
            new_lst->next = list->next;
            list->next = new_lst;
            list = save_lst;
            return;
        }
        list = list->next;
    }


    list->next = new_lst;
    list = save_lst;
}

LIST* list_ctor()
{
    LIST* lst = (LIST*)malloc(sizeof(LIST));
    lst->next = NULL;

    double number = 0;

    if (scanf("%lf", &number) == 1)
        lst->value = number;
    else
    {
        printf(RED "ERROR: didn't found number for list\n" END_OF_COLOUR);
        return NULL;
    }
    return lst;
}

void list_dump(LIST* head)
{
    assert(head != NULL);

    LIST* save_head = head;
    printf(YELLOW "List_dump: \n");

    printf(GREEN "Pointer is" BLUE "   %p" RED "|",  head);

    while (head->next != NULL)
    {
        head = head->next;
        printf(BLUE "    %p" RED "|" END_OF_COLOUR, head);

    }
    head = save_head;
    printf("\n");
    printf(GREEN "Number is" BLUE "%12.6lf" RED "|",  head->value);

    while (head->next != NULL)
    {
        head = head->next;
        printf(BLUE "%12.6lf" RED "|" END_OF_COLOUR, head->value);

    }
    head = save_head;
    printf(GREEN "\nNEXT  is  " BLUE "   %p" RED "|", head->next);

    while (head->next != NULL)
    {
        head = head->next;
        printf(BLUE "    %p" RED "|" END_OF_COLOUR, head->next);
    }
    printf("\n\n");
}

double list_med(LIST* lst)
{
    LIST* a = lst->next;
    LIST* b = (lst->next)->next;

    while (b != NULL && (b->next) != NULL)
    {
        a = a->next;
        b = (b->next)->next;
    }
    return a->value;
}

void list_dtor(LIST* lst)
{
    if (lst == NULL)
        return;
    else
    {
        list_dtor(lst->next);
        free(lst);
    }
}

int main()
{
    LIST* lst = list_ctor();
    double number = 0;

    while (scanf("%lf", &number) == 1)
        list_insert_sort(&lst, number);

    printf(YELLOW "\n%lf\n" END_OF_COLOUR, list_med(lst));
    list_dump(lst);
    return 0;
}
