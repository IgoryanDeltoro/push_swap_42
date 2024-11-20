/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:40:09 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/20 01:06:52 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
int get_min(t_list *lst)
{
    int smallest;
    
    smallest = lst->data;
    while (lst->next != NULL)
    {
        if (smallest > lst->next->data)
            smallest = lst->next->data;
        lst = lst->next;
    }
    return smallest;
}


void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; 
    int i = low - 1;      

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    return i + 1;                  
}


void quicksort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int *pre_sort(t_list *head, int size) 
{
    int *values = malloc(size * sizeof(int));
    if (!values)
        return NULL; 
    t_list *current = head;
    for (int i = 0; i < size && current != NULL; i++) 
    {
        values[i] = current->data;
        current = current->next;
    }
    quicksort(values, 0, size -1);
    return values; 
}

void reinsert_sorted(t_list **a, t_list **b) {
    while (*b) 
    {
        t_list *current = *b;
        int max = current->data;
        t_list *max_node = current;
        t_list *prev_max = NULL;

        while (current->next) 
        {
            if (current->next->data > max) 
            {
                max = current->next->data;
                prev_max = current;
                max_node = current->next;
            }
            current = current->next;
        }
        if (!prev_max) 
            ft_pa(a, b);
        else 
        {
            prev_max->next = max_node->next;
            max_node->next = *a;
            *a = max_node;
        }
    }
}

void push_to_chunks(t_list **a, t_list **b, int *sorted, int size, int num_chunks) 
{
    int chunk_size = size / num_chunks;
    int chunk = 0;
    int min = 0;
    int max = 0;
    int index = find_index(*a);
    int flag = 0;
    
    if (get_min(*a) != (*a)->data)
        rotate_to_top(a, index);
    while (*a) 
    {
        int value = (*a)->data;
        while ( chunk < num_chunks) 
        {
            min = sorted[chunk * chunk_size];
            if (chunk == num_chunks)
                max = sorted[size - 1];
            else
                max = sorted[(chunk + 1) * chunk_size - 1];
            if (value >= min && value <= max) 
            {
                ft_pb(a, b);
                flag++;
                break;
            }
            else if (flag == chunk_size)
            {
                    flag = 0;
                    chunk++;
            }
            break;
        }
        ft_ra(a);
    }
}

int sort_big_num(t_list **lst_a, t_list **lst_b)
{
    int size = (*lst_a)->argc - 1;
    int *sorted = pre_sort(*lst_a, size);
    int chunk;
    
    if (!(*lst_a) || !lst_a)
        return (0);
    if (size <= 100)
        chunk = 5;
    if (size >= 101 && size <= 200)
        chunk = 5;
    if (size >= 201 && size <= 300)
        chunk = 6;
    if (size >= 301 && size <= 400)
        chunk = 8;
    if (size >= 401 && size <= 500)
        chunk = 10;
    
    printf("chunk: %d\n", chunk);
    push_to_chunks(lst_a, lst_b, sorted, size, chunk);
    reinsert_sorted(lst_a, lst_b);
    return (1);
}