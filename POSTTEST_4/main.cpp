#include <iostream>
#include <string>
using namespace std;


struct Hewan
{
    int id;
    string nama;
};

struct Node
{
    Hewan data;
    Node* next;
};


struct Queue
{
     Node *front, *rear;
};

struct Stack
{
    Node *top;
};

void initQueue(Queue *q) { q->front = q->rear = nullptr; }
bool isQEmpty(Queue *q) { return q->front == nullptr; }

void initStack(Stack *s) { s->top = nullptr; }
bool isSEmpty(Stack *s) { return s->top == nullptr; }

void enqueue(Queue *q, Hewan h)
{
    Node* baru = new Node;
    baru->data = h;
    baru->next = nullptr;

    if (isQEmpty(q))
    {
        q->front = q->rear = baru;
    } else{
        q->rear->next = baru;
        q->rear = baru;
    }
}

Hewan dequeue(Queue *q)
{
    Hewan kosong = {-1, ""};

    if (isQEmpty(q))
    {
        cout << "Antrian kosong (Underflow)\n";
        return kosong;
    }

    Node* hapus = q->front;
    Hewan h = hapus->data;

    q->front = q->front->next;
    if (q->front == nullptr)
    {
        q->rear = nullptr;
    }
    delete hapus;
    return h;
}

void push(Stack *s, Hewan h)
{
    Node* baru = new Node;
    baru->data = h;
    baru->next = s->top;
    s->top = baru;
}

Hewan pop(Stack *s)
{
    Hewan kosong = {-1, ""};

    if (isSEmpty(s))
    {
        cout << "Riwayat kosong (Underflow)\n";
        return kosong;
    }
    
    Node* hapus = s->top;
    Hewan h = hapus->data;

    s->top = s->top->next;
    delete hapus;

    return h;
}

void peek(Queue *q, Stack *s)
{
    if (!isQEmpty(q))
    {
        cout << "Antrian terdepan: "
             << q->front->data.nama << " (ID: "
             << q->front->data.id << ")\n";
    }else{
        cout << "Antrian kosong\n";
    }

    if (!isSEmpty(s))
    {
        cout << "Riwayat terakhir: "
             << s->top->data.nama << " (ID: "
             << s->top->data.id << ")\n";
    }else{
        cout << "Riwayat kosong\n";
    }
}

void tampilQueue(Queue *q)
{
    if (isQEmpty(q))
    {
        cout << "Antrian kosong\n";
        return;
    }
    
    cout << "\n=== ANTRIAN ===\n";
    Node* p = q->front;
    while (p != nullptr)
    {
        cout << p->data.id << " - " << p->data.nama << endl;
        p = p->next;
    }
}

void tampilStack(Stack *s)
{
    if (isSEmpty(s))
    {
        cout << "Riwayat kosong\n";
        return;
    }
    
    cout << "\n=== RIWAYAT ===\n";
    Node* p = s->top;
    while (p != nullptr)
    {
        cout << p->data.id << " - " << p->data.nama << endl;
        p = p->next;
    }
    
}

int main()
{
    Queue q;
    Stack riwayat;

    initQueue(&q);
    initStack(&riwayat);

    int pilih;
    do
    {
        cout << "\nPAWCARE PETSHOP\n";
        cout << string(20, '-') << endl;
        cout << "1. Antrian Pemeriksaan" << endl;
        cout << "2. Panggil Pasien" << endl;
        cout << "3. Pop Riwayat" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Tampil Antrian" << endl;
        cout << "6. Tampil Riwayat" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1)
        {
            Hewan h;
            cout << "ID: "; cin >> h.id;
            cout << "Nama: "; cin >> h.nama;
            enqueue(&q, h);
        }
        else if (pilih == 2)
        {
            Hewan h = dequeue(&q);
            if (h.id != -1)
            {
                cout << "Dipanggil: " << h.nama << endl;
                push(&riwayat, h);
            }
        }
        else if (pilih == 3)
        {
            Hewan h = pop(&riwayat);
            if (h.id != -1)
            {
                cout << "Hapus riwayat: " << h.nama << endl;
            }
        }
        else if (pilih == 4)
        {
            peek(&q, &riwayat);
        }
        else if (pilih == 5)
        {
            tampilQueue(&q);
        }
        else if (pilih == 6)
        {
            tampilStack(&riwayat);
        }
    } while (pilih != 0);
    
}