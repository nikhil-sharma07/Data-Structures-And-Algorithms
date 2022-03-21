ListNode rotateRight(ListNode *head, int k)
{
    ListNode temp - head : int len = 0;
    while (temp != NULL)
    {
        temp - temp->next;
        len++;
    }
    if (k >= len)
        k = k % len;

    ListNode prev = NULL;
    temp = head;
    int move = len - k;
    for (int i = 1; i <= move; i++)
    {

        prev = temp;

        temp = temp->next;
    }
    prev->next = NULL;
    while (temp != NULL)
    {

        prev = temp;

        temp = temp->next;
    }
    prev->next = head;
    head = prev;
    return head;
}