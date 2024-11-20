/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_huge_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:40:09 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/20 02:36:03 by igoryan          ###   ########.fr       */
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


int partition(int arr[], int low, int high) 
{
    int pivot;
    int i;
    int j;
     
    j = low;
    i = low - 1;
    pivot = arr[high];
    while (j < high) 
    {
        if (arr[j] <= pivot) {
            i++;
            ft_swap(&arr[i], &arr[j]); 
        }
        j++;
    }
    ft_swap(&arr[i + 1], &arr[high]); 
    return i + 1;                  
}


void quicksort(int arr[], int low, int high) 
{
    int partions;
    
    if (low < high) 
    {
        partions = partition(arr, low, high);

        quicksort(arr, low, partions - 1);
        quicksort(arr, partions + 1, high);
    }
}

int *pre_sort(t_list *lst, int size) 
{
    t_list *current;
    int *values;
    int i;
    
    values = malloc(size * sizeof(int));
    if (!values)
        return NULL;
    i = 0;
    current = lst;
    while (i < size && current != NULL) 
    {
        values[i] = current->data;
        current = current->next;
        i++;
    }
    quicksort(values, 0, size -1);
    return values; 
}

void reinsert_of_sorted(t_list **lst_a, t_list **lst_b) 
{
    t_list *current;
    t_list *max_node;
    t_list *prev_max;
    int max;
    
    while (*lst_b) 
    {
        current = *lst_b;
        max = current->data;
        max_node = current;
        prev_max = NULL;

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
            ft_pa(lst_a, lst_b);
        else 
        {
            prev_max->next = max_node->next;
            max_node->next = *lst_a;
            *lst_a = max_node;
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
        while ( chunk <= num_chunks) 
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

int sort_huge_num(t_list **lst_a, t_list **lst_b)
{
    int size;
    int *sorted;
    int chunk;
    
    if (!(*lst_a) || !lst_a)
        return (0);
    size = (*lst_a)->argc - 1;
    sorted = pre_sort(*lst_a, size);
    if (size <= 100)
        chunk = 5;
    if (size > 100 && size <= 500)
        chunk = 10;
    push_to_chunks(lst_a, lst_b, sorted, size, chunk);
    reinsert_of_sorted(lst_a, lst_b);
    free(sorted);
    return (1);
}