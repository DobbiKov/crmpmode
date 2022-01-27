stock SelectionSort(_array[], size = sizeof(_array)) 
{
    for (new i = 0, value = 0, j = 0, swap = 0; i != size - 1; i++) 
    {
        value = i;
        for (j = i + 1; j != size; j++) 
        {
            if (_array[j] > _array[value]) //max to min
                value = j;
        }
        if (value != i) 
        {
            swap = _array[i];
            _array[i] = _array[value];
            _array[value] = swap;
        }
    }
}