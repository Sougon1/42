








void sort_stack_b(stack *b_list)
{
    int rotation;
    while (is_sorted(b_list))
    {
        int min_index_b = find_min_index_b(b_list);

        if (min_index_b <= b_list->size / 2)
        {
            while (min_index_b-- != 0)
            {
                ft_printf("rrb\n");
                rotate_b(b_list);
            }
        }
        else
        {
            rotation = b_list->size - min_index_b;
            while (rotation-- > 0)
            {
                ft_printf("rrb\n");
                rrotate_b(b_list);
            }
        }
        ft_printf("sb\n")
        swap_b(b_list);
    }
}

void sort_half_of_a(stack *a_list, stack *b_list)
{
    int half_size = a_list->size / 2;
    
    while (b_list->size < half_size)
    {
        int max_index = find_max_index_a(a_list);
        if (max_index > a_list->size / 2)
        {
            while (max_index != 0)
            {
                rrotate_a(a_list);
                max_index--;
            }
        } else {
            while (max_index != 0)
            {
                rotate_a(a_list);
                max_index--;
            }
        }
        // push_b(a_list, b_list);
    }
}