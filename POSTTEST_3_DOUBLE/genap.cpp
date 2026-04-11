#include <iostream>
#include <string>
using namespace std;

#define MAX 5

struct Tiket {
    string nama;
    string rute;
};

struct Queue {
    Tiket data[MAX];
    int front, rear;
};

struct Stack {
    Tiket data[MAX];
    int top;
};

void initQueue(Queue *q) { q->front = q->rear = -1; }
void initStack(Stack *s) { s->top = -1; }

bool isQEmpty(Queue *q) { return q->front == -1 || q->front > q->rear; }
bool isQFull(Queue *q) { return q->rear == MAX - 1; }

bool isSEmpty(Stack *s) { return s->top == -1; }
bool isSFull(Stack *s) { return s->top == MAX - 1; }

void enqueue(Queue *q, Tiket t) {
    if (isQFull(q)) {
        cout << "Antrian penuh (Overflow)\n"; return;
    }

    if (q->front == -1) q->front = 0;
    q->rear++;

    *(q->data + q->rear) = t;
}

void enqueuefront(Queue *q, Tiket t) {
    if (isQFull(q)) {
        cout << "Queue penuh\n"; 
        return;
    }

    if (isQEmpty(q)) {
        q->front = q->rear = 0;
        *(q->data) = t;
    } else {
        q->rear++;

        for (Tiket *p = q->data + q->rear; p > q->data + q->front; p--) {
            *p = *(p - 1);
        }

        *(q->data + q->front) = t;
    }
}

Tiket dequeue(Queue *q) {
    Tiket kosong = {"", ""};

    if (isQEmpty(q)) {
        cout << "Antrian kosong (Underflow)\n";
        return kosong;
    }

    Tiket t = *(q->data + q->front);

    for (Tiket *p = q->data + q->front; p < q->data + q->rear; p++) {
        *p = *(p + 1);
    }

    q->rear--;

    if (q->rear < q->front)
        q->front = q->rear = -1;

    return t;
}

void push(Stack *s, Tiket t) {
    if (isSFull(s)) {
        cout << "Riwayat penuh (Overflow)\n"; return;
    }

    s->top++;
    *(s->data + s->top) = t;
}

Tiket pop(Stack *s) {
    Tiket kosong = {"", ""};

    if (isSEmpty(s)) {
        cout << "Riwayat kosong (Underflow)\n";
        return kosong;
    }

    Tiket t = *(s->data + s->top);
    s->top--;
    return t;
}

void peek(Queue *q, Stack *s) {
    if (!isQEmpty(q)) {
        cout << "Antrian terdepan: "
             << (q->data + q->front)->nama << " - "
             << (q->data + q->front)->rute << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (!isSEmpty(s)) {
        cout << "Transaksi terakhir: "
             << (s->data + s->top)->nama << " - "
             << (s->data + s->top)->rute << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

void tampilQueue(Queue *q) {
    if (isQEmpty(q)) {
        cout << "Antrian kosong\n"; return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (Tiket *p = q->data + q->front; p <= q->data + q->rear; p++) {
        cout << p->nama << " - " << p->rute << endl;
    }
}

void tampilStack(Stack *s) {
    if (isSEmpty(s)) {
        cout << "Riwayat kosong\n"; return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (Tiket *p = s->data; p <= s->data + s->top; p++) {
        cout << p->nama << " - " << p->rute << endl;
    }
}

int main() {
    Queue q;
    Stack riwayat, redo;

    initQueue(&q);
    initStack(&riwayat);
    initStack(&redo);

    int pilih;
    do {
        cout << "\nSISTEM KERETA\n";
        cout << string(20, '-') << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Proses Tiket" <<endl;
        cout << "3. Peek" << endl;
        cout << "4. Pop Riwayat(permanent)" << endl;
        cout << "5. Undo" << endl;
        cout << "6. Redo" << endl;
        cout << "7. Tampil Antrian" << endl;
        cout << "8. Tampil Riwayat" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            Tiket t;
            cout << "Nama: "; cin >> t.nama;
            cout << "Rute: "; cin >> t.rute;
            enqueue(&q, t);
        }
        else if (pilih == 2) {
            Tiket t = dequeue(&q);
            if (t.nama != "") {
                cout << "Diproses: " << t.nama << endl;
                push(&riwayat, t);

                redo.top = -1;
            }
        }
        else if (pilih == 3) {
            peek(&q, &riwayat);
        }
        else if (pilih == 4) {
            Tiket t = pop(&riwayat);
            if (t.nama != "") {
                cout << "Pop (hapus terakhir): "
                    << t.nama << " - " << t.rute << endl;
            }
        }
        else if (pilih == 5) {
            Tiket t = pop(&riwayat);
            if (t.nama != "") {
                cout << "Undo: " << t.nama << endl;

                push(&redo, t);

                enqueuefront(&q, t);
            }
        }
        else if (pilih == 6) {
            Tiket t = pop(&redo);
            if (t.nama != "") {
                cout << "Redo: " << t.nama << endl;
                dequeue(&q);
                push(&riwayat, t);
            }
        }
        else if (pilih == 7) {
            tampilQueue(&q);
        }
        else if (pilih == 8) {
            tampilStack(&riwayat);
        }

    } while (pilih != 0);
}