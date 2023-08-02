// Program Double Linked List
// Double linked list adalah jenis linked list yang setiap node nya memiliki 3 komponen : *prev, data, dan *next

#include <iostream>
using namespace std;

// data struct bernama 'Node'
struct Node {
  int data;
  struct Node* next = NULL; // Node Selanjutnya
  struct Node* prev = NULL; // Node Sebelumnya
};

// Banyaknya node yang ada
int nodeLength = 0;

// Memasukkan node baru ke bagian depan
void insertFront(struct Node** head, int data) {
  // alokasi memori untuk node baru
  struct Node* newNode = new Node;

  // memasukkan data ke node baru
  newNode->data = data;

  // node baru menjadi bagian kepala
  newNode->next = (*head);

  // prev menjadi null
  newNode->prev = NULL;

  // sebelum head adalah newNode
  if ((*head) != NULL)
    (*head)->prev = newNode;

  // pointer head mengarah ke node baru
  (*head) = newNode;
  nodeLength++;
}


// memasukkan node baru di akhir list
void insertEnd(struct Node** head, int data) {
  // alokasi memori untuk node
  struct Node* newNode = new Node;

  // data untuk newNode
  newNode->data = data;

  // assign null to next of newNode
  // next dari newNode menjadi null
  newNode->next = NULL;

  // memasukkan node *head untuk menjadi variable sementara
  struct Node* temp = *head;

  // Jika listnya kosong, maka newNode menjadi node head
  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }

  // Jika linked list tidak kosong, maka akan lompat hingga ke ujung dari linked list
  while (temp->next != NULL)
    temp = temp->next;

  // Node terakhir dari list adalah temp

  // Next dari node temp adalah newNode
  temp->next = newNode;

 	// previous dari newNode adalah temp
  newNode->prev = temp;
  nodeLength++;
}

// memasukkan node baru setelah sebuah node tertentu
// Mencari node yang memiliki data yang bernilai seperti argumen dataBefore
// Kemudian setelah node tersebut dijumpai, maka data akan diinsert setelahnya
void insertAfter(struct Node** head, int ind, int data) {
	struct Node* prev_node = *head;
  int index = 0;
  // memeriksa prev_node null atau tidak
  while (prev_node != NULL && index < ind) {
  	prev_node = prev_node->next;
    index++;
  }

  // alokasi memori untuk newNode
  struct Node* newNode = new Node;

  if (prev_node == NULL) {
    cout << "Data tidak ditemukan";
    return;
  }

  // memasukkan data ke newNode
  newNode->data = data;

  // data selanjutnya dari newNode adalah pointer next dari prev_node
  newNode->next = prev_node->next;

  // next dari prev_node menjadi newNode
  prev_node->next = newNode;

  // prev dari new node adalah prev_node;
  newNode->prev = prev_node;

  // previous dari next-nya newNode menjadi newNode 
  if (newNode->next != NULL)
    newNode->next->prev = newNode;

 	nodeLength++;
}
// Menghapus sebuah node dari double linked list
// head adalah node kepala, del_node adalah node yang ingin dihapus
void deleteNode(struct Node** head, int index) {
  // Jika head atau node untuk dihapusnya bernilai null, maka tidak bisa
  struct Node* del_node = *head;
  int ind = 0;
  if (*head == NULL || del_node == NULL) {
  	cout << "Head atau Delete Node tidak bisa kosong";
    return;
  }
  while (del_node != NULL && ind < index) {
  	del_node = del_node->next;
    ind++;
  }
  if (del_node == NULL) {
  	cout << "Data tidak ditemukan";
  	return;
  }

  // Jika node yang akan dihapus adalah head, maka pointer head mengarah ke next dari del_node
  if (*head == del_node)
    *head = del_node->next;

  // Jika del_node bukan node terakhir, maka prev dari next-nya del_node mengarah ke previous dari del_node
  if (del_node->next != NULL)
    del_node->next->prev = del_node->prev;

  // Jika del_node bukan node pertama, maka next dari prev-nya node mengarah ke next dari del_node
  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;

  // Membebaskan memori dari data del_node
  free(del_node);
  nodeLength--;
}

void deleteFront (struct Node** head) {
  struct Node* del_node = *head;
  (*head) = del_node->next;
  if (del_node != NULL) {
    del_node->next->prev = NULL;
  }

  free(del_node);
  nodeLength--;
}

void deleteEnd (struct Node** head) {
  struct Node* del_node = *head;
  while (del_node->next != NULL) {
    del_node = del_node->next;
  }
  del_node->prev->next = NULL;

  free(del_node);
  nodeLength--;
}

// Mendisplay data dari linked list
void displayList(struct Node* node) {
  struct Node* last;

  cout << "\n";
  int ind = 0;
  while (node != NULL) {
    cout << "Node " << ind << " = " << node->data << endl;
    last = node;
    node = node->next;
    ind++;
  }

  cout << "Banyak Node = " << nodeLength << endl;
}

int main() {
  // inisialisasi sebuah node kosong
  struct Node* head = NULL;
  int pilihan = 1;
  int before, data;

  cout << "\nProgram Double Linked List by Muhammad Rizkiansyah - 20220801341" << endl;
  awal:
  cout << "\n Ada beberapa menu, silahkan anda pilih : " << endl;
  cout << "1. Insert Data di Depan" << endl;
  cout << "2. Insert Data di Akhir" << endl;
  cout << "3. Insert Tengah" << endl;
  cout << "4. Hapus Depan" << endl;
  cout << "5. Hapus Akhir" << endl;
  cout << "6. Hapus Tengah" << endl;
  cout << "7. Tampilkan Semua Data" << endl;
  cout << "8. Keluar dari Program" << endl;
  cout << "Masukkan Pilihan anda : ";
  cin >> pilihan;
  switch (pilihan) {
	  case 1:
	  	cout << "Masukkan angka yang ingin anda masukkan ke awal list : ";
	  	cin >> data;
	  	insertFront(&head, data);
	  	break;
	  case 2:
	  	cout << "Masukkan angka yang ingin anda masukkan ke akhir list : ";
	  	cin >> data;
	  	insertEnd(&head, data);
	  	break;
	  case 3:
	  	cout << "Masukkan index node sebelumnya : ";
	  	cin >> before;
	  	cout << "Masukkan angka yang ingin dimasukkan setelahnya : ";
	  	cin >> data;
	  	insertAfter(&head, before, data);
	  	break;
	  case 4: 
	  	deleteFront(&head);
	  	break;
	  case 5:
	  	deleteEnd(&head);
	  	break;
    case 6: 
      cout << "Masukkan index node yang ingin dihapus : ";
      cin >> data;
      deleteNode(&head, data);
      break;
    case 7:
      displayList(head);
      break;
	  default:
	  	return 0;
  }
  if (pilihan != 7) displayList(head);
  goto awal;
  return 0;
}