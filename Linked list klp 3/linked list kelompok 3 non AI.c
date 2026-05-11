#include <stdio.h>
#include<stdlib.h>



   
   struct ll { 
   int data;
   struct ll *next;
   };

struct Node {
    int data;
    struct Node* next;
};

int cari(struct ll  *head) {
    struct ll *curr = head;
    struct ll *arr[13];
    int i=0;
    int j=0;
    while (curr != NULL) {    
        
       
       arr[i]=curr;
        curr = curr->next; 
        i++;
       j=0;
        while (j<i) {
       
      
       
       if (arr[j]==curr) {
       printf("ada cycle pada linked list karena ada pengulangan alamat yaitu %d dan %d pada node ke-%d kembali ke node ke-%d",arr[j],curr,i,j);
       return 1;
       }
       
         
       j++;
        };
        
        
    }
    printf("tidak ada pengulangan pada linked list\n");
    return 0;
}

   

int main(void) {
  
struct ll *nol=NULL;
        nol =(struct ll*)malloc(sizeof(struct ll)); 
struct ll *satu=NULL;
        satu =(struct ll*)malloc(sizeof(struct ll));
struct ll *dua=NULL;
        dua =(struct ll*)malloc(sizeof(struct ll));
int n=3;


nol->data=11;
nol->next=satu;
satu->data=10;
satu->next = dua;
dua->data=20;
dua->next=satu;
 
 
 
  
  
  
  
  
  //cek apakah ada siklus
  int c= cari(nol) ;
  
  
  printf("\njadi return nilai adalah %d",c);
  
  
  }
  
   