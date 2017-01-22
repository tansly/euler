struct rad_n {
    int rad;
    int n;
};

void sorti(int *array, int len)
{
    int i, j;
    int temp;
    for (i = 1; i < len; i++) {
        temp = array[i];
        for (j = i - 1; j >= 0 && array[j] > temp; j--) {
            array[j + 1] = array[j];
        }
        array[j + 1] = temp;
    }
}

void sortd(int *array, int len)
{
    int i, j;
    int temp;
    for (i = 1; i < len; i++) {
        temp = array[i];
        for (j = i - 1; j >= 0 && array[j] < temp; j--) {
            array[j + 1] = array[j];
        }
        array[j + 1] = temp;
    }
}

void inserti(struct rad_n current, struct rad_n *array, int len)
{
    int i;
    for (i = len - 1; i >= 0 && array[i].rad > current.rad; i--) {
        array[i + 1] = array[i];
    }
    array[i + 1] = current;
}
