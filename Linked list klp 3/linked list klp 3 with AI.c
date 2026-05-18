#include <stdio.h>
#include <stdlib.h>

/* ── Definisi Node ── */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* ── Buat node baru ── */
Node *buatNode(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

/*
 * detectCycle – Floyd's Tortoise & Hare
 * Mengembalikan pointer ke node awal siklus,
 * atau NULL jika tidak ada siklus.
 *
 * Cara kerja:
 *  Fase 1 – slow bergerak 1 langkah, fast 2 langkah.
 *           Jika bertemu → ada siklus.
 *  Fase 2 – Reset slow ke head, biarkan fast di titik pertemuan.
 *           Keduanya bergerak 1 langkah; titik temu baru = awal siklus.
 */
Node *detectCycle(Node *head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    /* Fase 1: cari titik pertemuan */
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    /* Tidak ada siklus */
    if (fast == NULL || fast->next == NULL)
        return NULL;

    /* Fase 2: temukan awal siklus */
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; /* node awal siklus */
}

/* ── Cetak linked list (maks maxNode node agar tidak infinite loop) ── */
void cetakList(Node *head, int maxNode) {
    Node *curr = head;
    int count = 0;
    while (curr != NULL && count < maxNode) {
        printf("%d", curr->data);
        if (curr->next != NULL && count + 1 < maxNode)
            printf(" -> ");
        curr = curr->next;
        count++;
    }
    if (curr != NULL)
        printf(" -> ... (cycle)");
    printf("\n");
}

/* ════════════════════════════════════════════════════════
   MAIN
   Data:  nol(11) -> satu(10) -> dua(20) -> tiga(20) -> empat(20) -> NULL
   ════════════════════════════════════════════════════════ */
int main(void) {
    /* Alokasi node */
    Node *nol   = buatNode(0);
    Node *satu  = buatNode(0);
    Node *dua   = buatNode(0);
    Node *tiga  = buatNode(0);
    Node *empat = buatNode(0);

    /* Isi data sesuai soal */
    nol->data   = 11;  nol->next   = satu;
    satu->data  = 10;  satu->next  = dua;
    dua->data   = 20;  dua->next   = tiga;
    tiga->data  = 20;  tiga->next  = empat;
    empat->data = 20;  empat->next = NULL;   /* ← tidak ada siklus */

    printf("=== Linked List Cycle II ===\n\n");
    printf("Linked list  : ");
    cetakList(nol, 10);

    /* ── Deteksi siklus ── */
    Node *hasil = detectCycle(nol);

    if (hasil != NULL)
        printf("Siklus dimulai di node dengan data: %d\n", hasil->data);
    else
        printf("Hasil        : Tidak ada siklus (NULL)\n");

    /* ── Demo DENGAN siklus: sambungkan empat -> dua ── */
    printf("\n--- Demo: tambahkan siklus (empat -> dua) ---\n");
    empat->next = dua;   /* buat siklus */

    hasil = detectCycle(nol);
    if (hasil != NULL) {
        printf("Linked list  : nol(11)->satu(10)->dua(20)->tiga(20)->empat(20)->[kembali ke dua]\n");
        printf("Siklus dimulai di node dengan data: %d\n", hasil->data);
    }

    /* Putus siklus sebelum free agar tidak double-free */
    empat->next = NULL;

    /* Bebaskan memori */
    free(nol); free(satu); free(dua); free(tiga); free(empat);
    return 0;
}
