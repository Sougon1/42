








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