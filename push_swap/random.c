void	push_index_b(stack *a_list, stack *b_list, int *tab)
{
	int				max_size_a;
	int				a_size;
	int				start_index;
	int				end_index;
	stack_element	*current_a;
	int				one_two;
	int				count;

	a_size = a_list->size;
	one_two = 1;
	current_a = a_list->a_top;
	max_size_a = max_size(&a_size);
	while (a_size > 0)
	{
		start_index = a_size - max_size_a;
		end_index = a_size;
		if (start_index < 0)
		{
			start_index = 0;
		}
		current_a = a_list->a_top;
		count = 0;
		while (start_index < end_index)
		{
			if (current_a->index > a_size - max_size_a
				&& current_a->index <= a_size)
			{
				push(a_list, b_list, 'b');
				start_index++;
				count--;
			}
			else if (one_two == 1)
			{
				rotate(a_list, b_list, 'a');
				count++;
			}
			else if (one_two == 0)
			{
				rrotate(a_list, b_list, 'a');
				count++;
			}
			current_a = a_list->a_top;
		}
		while (count > 0)
		{
			rotate(a_list, b_list, 'a');
			count--;
		}
		a_size -= max_size_a;
		sort(a_list, b_list);
		index_tab_a(a_list, tab);
		one_two = 0;
	}
}