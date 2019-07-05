
typedef struct     s_list
{
    int            data;
    struct s_list  *next;
}                  t_list;

/*
 * Алгоритм проверки наличия зацикленного односвязного списка
 * Алгоритм "заяц и черепаха"
 * Если связанный список зациклен - то будет момент когда
 * указатель "заяц" или "заяц->next" окажется позади черепахи (либо постоянно на одной и тойже позиции)
 * и будет равен указателю "черепаха", собственно такое равенство
 * означает что связанный список зациклен.
 */
int        cycle_detector(const t_list *list)
{
    t_list *hare;
    t_list *turtle;

    if (!list)
        return (0);
    hare = (t_list*)list;
    turtle = (t_list*)list;
    while (hare && turtle && hare->next)
    {
        hare = hare->next->next;
        turtle = turtle->next;
        if (turtle == hare || hare->next == turtle)
            return (1);
    }
    return (0);
}
