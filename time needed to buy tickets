int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int c = 0;
    while (1){
        int i;
        for (i = 0; i < ticketsSize; i++){
            if (tickets[i] > 0){
            tickets[i]--; c++;
            if (i == k && tickets[k]==0)  return c;
            }
        }
    }
    return c;
}
