int main() {
    int sla;

    if (1 > 10) {
        return 1;
    } else if (2 > 10) {
        sla = 0;
    } else {
        sla = 2;
    }

    sla = sla < 5 ? 10 : 100;

    return 0;
}