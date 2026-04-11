#include <iostream>
#include <string>
using namespace std;

#define MAX 5

struct Hewan {
    int id;
    string nama;
};

struct Queue {
    Hewan data[MAX];
    int front, rear;
};

struct Stack {
    Hewan data[MAX];
    int top;
};

void initQueue(Queue *q) { q->front = q->rear = -1; }
void initStack(Stack *s) { s->top = -1; }

bool isQEmpty(Queue *q) { return q->front == -1 || q->front > q->rear; }
bool isQFull(Queue *q) { return q->rear == MAX - 1; }

bool isSEmpty(Stack *s) { return s->top == -1; }
bool isSFull(Stack *s) { return s->top == MAX - 1; }

void enqueue(Queue *q, Hewan h) {
    if (isQFull(q)) {
        cout << "Antrian penuh (Overflow)\n"; return;
    }

    if (q->front == -1) q->front = 0;
    q->rear++;

    *(q->data + q->rear) = h;
}

void enqueuefront(Queue *q, Hewan h) {
    if (isQFull(q)) {
        cout << "Queue penuh\n"; 
        return;
    }

    if (isQEmpty(q)) {
        q->front = q->rear = 0;
        *(q->data) = h;
    } else {
        q->rear++;

        for (Hewan *p = q->data + q->rear; p > q->data + q->front; p--) {
            *p = *(p - 1);
        }

        *(q->data + q->front) = h;
    }

    cout << "Pasien DARURAT masuk ke depan!\n";
}

Hewan dequeue(Queue *q) {
    Hewan kosong = {-1, ""};

    if (isQEmpty(q)) {
        cout << "Antrian kosong (Underflow)\n";
        return kosong;
    }

    Hewan h = *(q->data + q->front);

    for (Hewan *p = q->data + q->front; p < q->data + q->rear; p++) {
        *p = *(p + 1);
    }

    q->rear--;

    if (q->rear < q->front)
        q->front = q->rear = -1;

    return h;
}

void push(Stack *s, Hewan h) {
    if (isSFull(s)) {
        cout << "Riwayat penuh (Overflow)\n"; return;
    }

    s->top++;
    *(s->data + s->top) = h;
}

Hewan pop(Stack *s) {
    Hewan kosong = {-1, ""};

    if (isSEmpty(s)) {
        cout << "Riwayat kosong (Underflow)\n";
        return kosong;
    }

    Hewan h = *(s->data + s->top);
    s->top--;
    return h;
}

void peek(Queue *q, Stack *s) {
    if (!isQEmpty(q)) {
        cout << "Antrian terdepan: "
             << (q->data + q->front)->nama << " (ID: "
             << (q->data + q->front)->id << ")\n";
    } else {
        cout << "Antrian kosong\n";
    }

    if (!isSEmpty(s)) {
        cout << "Riwayat terakhir: "
             << (s->data + s->top)->nama << " (ID: "
             << (s->data + s->top)->id << ")\n";
    } else {
        cout << "Riwayat kosong\n";
    }
}

void tampilQueue(Queue *q) {
    if (isQEmpty(q)) {
        cout << "Antrian kosong\n"; return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (Hewan *p = q->data + q->front; p <= q->data + q->rear; p++) {
        cout << p->id << " - " << p->nama << endl;
    }
}

void tampilStack(Stack *s) {
    if (isSEmpty(s)) {
        cout << "Riwayat kosong\n"; return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (Hewan *p = s->data; p <= s->data + s->top; p++) {
        cout << p->id << " - " << p->nama << endl;
    }
}

int main() {
    Queue q;
    Stack riwayat;

    initQueue(&q);
    initStack(&riwayat);

    int pilih;
    do {
        cout << "\nPAWCARE PETSHOP\n";
        cout << string(20, '-') << endl;
        cout << "1. Antrian Pemeriksaan" << endl;
        cout << "2. Pasien Darurat" << endl;
        cout << "3. Panggil Pasien" << endl;
        cout << "4. Pop Riwayat" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Tampil Antrian" << endl;
        cout << "7. Tampil Riwayat" << endl;
        cout << "0. Keluar" <<endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1 || pilih == 2) {
            Hewan h;
            cout << "ID: "; cin >> h.id;
            cout << "Nama: "; cin >> h.nama;

            if (pilih == 1) enqueue(&q, h);
            else enqueuefront(&q, h);
        }
        else if (pilih == 3) {
            Hewan h = dequeue(&q);
            if (h.id != -1) {
                cout << "Dipanggil: " << h.nama << endl;
                push(&riwayat, h);
            }
        }
        else if (pilih == 4) {
            Hewan h = pop(&riwayat);
            if (h.id != -1)
                cout << "Hapus riwayat: " << h.nama << endl;
        }
        else if (pilih == 5) {
            peek(&q, &riwayat);
        }
        else if (pilih == 6) {
            tampilQueue(&q);
        }
        else if (pilih == 7) {
            tampilStack(&riwayat);
        }

    } while (pilih != 0);
}